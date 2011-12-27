/*
 * Mock_Directory.h
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#ifndef MOCK_DIRECTORY_H
#define MOCK_DIRECTORY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Filesystem/Directory.h"
#include <vector>
#include <string>
using namespace std;

class MockDirectory : public Directory {
  public:
    MOCK_CONST_METHOD1(getFileWithExtension, vector<string>(string extension));
};
#endif
