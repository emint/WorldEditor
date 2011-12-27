/*
 * Directory.h
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#ifndef DIRECTORY_H_
#define DIRECTORY_H_

#include <string>

#include "boost/filesystem.hpp"

#include "../Exceptions/InvalidArgumentException.h"
#include "../Exceptions/ResourceNotFoundException.h"

using namespace boost::filesystem;
using namespace std;

class Directory {
  public:
    Directory(string dirName);
    Directory() : dirPath(NULL) {

    }

    virtual ~Directory();

    virtual vector<string> getFileWithExtension(string extension) const;
  private:
    path* dirPath;
};

#endif /* DIRECTORY_H_ */
