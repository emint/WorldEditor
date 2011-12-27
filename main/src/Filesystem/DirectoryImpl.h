/*
 * Directory.h
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#ifndef DIRECTORYIMPL_H_
#define DIRECTORYIMPL_H_

#include <string>

#include "boost/filesystem.hpp"

#include "../Exceptions/InvalidArgumentException.h"
#include "../Exceptions/ResourceNotFoundException.h"

#include "Directory.h"

using namespace boost::filesystem;
using namespace std;

class DirectoryImpl : public Directory {
  public:
    DirectoryImpl(string dirName);
    DirectoryImpl();

    virtual ~DirectoryImpl();

    virtual vector<string> getFileWithExtension(string extension) const;
  private:
    path* dirPath;
};

#endif /* DIRECTORY_H_ */
