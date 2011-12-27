/*
 * InvalidArgumentException.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#ifndef INVALIDARGUMENTEXCEPTION_H_
#define INVALIDARGUMENTEXCEPTION_H_

#include <exception>
#include <string>

using namespace std;

class InvalidArgumentException: public std::exception {
  public:
    InvalidArgumentException(string message);
    virtual ~InvalidArgumentException() throw();

    virtual const char* what() const throw() {
      return msg.c_str();
    }

  private:
    string msg;
};

#endif /* INVALIDARGUMENTEXCEPTION_H_ */
