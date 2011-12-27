/*
 * ResourceNotFoundException.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#ifndef RESOURCENOTFOUNDEXCEPTION_H_
#define RESOURCENOTFOUNDEXCEPTION_H_

#include <exception>
#include <string>
#include <sstream>
using namespace std;

class ResourceNotFoundException: public std::exception {
  public:
    ResourceNotFoundException(string resourceName) : resource(resourceName) {
    }

    virtual ~ResourceNotFoundException() throw();

    virtual const char* what() const throw() {
      string err = "Could not locate resource named "+resource+".";
      return err.c_str();
    }

  private:
    string resource;
};

#endif /* RESOURCENOTFOUNDEXCEPTION_H_ */
