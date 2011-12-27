/*
 * Directory.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#include "Directory.h"
#include <iostream>
using namespace std;

Directory::Directory(string dirName) {
  dirPath = new path(dirName);

  if (!exists(*dirPath)){
    throw ResourceNotFoundException("Folder does not exist");
  }
  if (!is_directory(*dirPath)){
    throw InvalidArgumentException("Argument is not a folder");
  }
}

Directory::~Directory() {
  // TODO Auto-generated destructor stub
}

vector<string> Directory::getFileWithExtension(string ext) const{
  vector<string> files;
  for (directory_iterator iter(*dirPath), end; iter != end; ++iter){
    if (extension(iter->path()) == ext){
      files.push_back(iter->path().string());
    }
  }
  return files;
}
