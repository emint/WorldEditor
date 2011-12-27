#Home directory
HOME = /home/emint


#Path to avoid the "../" in includes
SRC_PATH = main/src

MAIN_SRC_ROOT = main/src/
MAIN_TEST_ROOT = main/test/

#Compiler, flags, and system libraries
CXXFLAGS = -Wall -g -Werror -I$(HOME)/gtest-1.6.0/include -I$(HOME)/gmock-1.6.0/include -I$(SRC_PATH)
LIBS = -lSDL -lSDL_image -lboost_filesystem

#Linking into a static library
LIBCREATE =  ar rcs

#Name of world editor library
WORLD_EDIT_LIB = libworld.a

#Testing library, assuming gtest in homefolder
TESTLIBS = $(HOME)/gmock-1.6.0/make/gmock_main.a

#Sources and headers that will be going into the library 
LIB_HDRS = Exceptions/InvalidArgumentException.h Exceptions/ResourceNotFoundException.h
LIB_HDRS += Assets/AssetManager.h Filesystem/Directory.h Filesystem/DirectoryImpl.h  Display/SurfaceLoader.h

LIB_SRCSS = Exceptions/InvalidArgumentException.cpp Exceptions/ResourceNotFoundException.cpp
LIB_SRCSS += Assets/AssetManager.cpp Filesystem/DirectoryImpl.cpp Display/SurfaceLoader.cpp


LIB_HEADERS = $(addprefix $(MAIN_SRC_ROOT), $(LIB_HDRS))
LIB_SOURCES = $(addprefix $(MAIN_SRC_ROOT), $(LIB_SRCSS))

#Sources that can be run
MAIN_SRCSS = main.cpp

MAIN_SOURCES = $(addprefix $(MAIN_SRC_ROOT), $(MAIN_SRCSS))

#For testing source files
TEST_SRCS = AssetManagerTest.cpp

TEST_HDRS = Mock_SurfaceLoader.h Mock_Directory.h

TEST_SOURCES = $(addprefix $(MAIN_TEST_ROOT), $(TEST_SRCS))

TEST_HEADERS = $(addprefix $(MAIN_TEST_ROOT), $(TEST_HDRS))

#Objects
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

#Objects that can be run
MAIN_OBJS = $(MAIN_SOURCES:.cpp=.o)
TEST_OBJS = $(TEST_SOURCES:.cpp=.o)
#Dependency file to write
DEPENDENCY_FILE = Makefile.dependencies

#Target names
TARGETS = editor unit_tests library

all: dependencies $(TARGETS) 

editor: library $(MAIN_OBJS) $(LIB_OBJECTS) $(LIB_HEADERS) 
	$(CXX) $(CXXFLAGS) $(LIBS) -o $@ $(MAIN_OBJS) -L. -lworld 

unit_tests: $(TEST_OBJS) $(LIB_OBJECTS) $(LIB_HEADERS) $(LIB_SOURCES) $(TEST_HEADERS) $(TEST_SOURCES) 
	$(CXX) $(CXXFLAGS)  $(LIBS) $(TESTLIBS) -o $@  $(TEST_OBJS) $(LIB_OBJECTS)

library: $(LIB_OBJECTS) $(LIB_HEADERS) $(LIB_SOURCES) 
	 $(LIBCREATE) $(WORLD_EDIT_LIB) $(LIB_OBJECTS)
	
##Generate dependencies using -MM gcc flag
dependencies: $(LIB_SOURCES) $(LIB_HEADERS)  $(TEST_SOURCES) $(TEST_HEADERS)
	$(CXX) $(CXXFLAGS) -MM  $(LIB_SOURCES) $(TEST_SOURCES) > $(DEPENDENCY_FILE)

-include Makefile.dependencies

clean:
	rm -f $(TARGETS) $(MAIN_OBJS) $(TEST_OBJS) $(OBJECTS) $(WORLD_EDIT_LIB) *~ Makefile.dependencies