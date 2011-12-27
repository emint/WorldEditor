/*
 * AssetManagerTest.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#include "Assets/AssetManager.h"
#include "Mock_Directory.h"
#include "Mock_SurfaceLoader.h"
#include <vector>
#include <iostream>

using namespace std;
using ::testing::Return;

TEST(AssetManager, loadsReturnedPNGS){
  MockSurfaceLoader loader;
  MockDirectory dir;
  AssetManager manager(&loader);

  string img1 = "hello.png";
  string img2 = "bye.png";
  vector<string> imgs;

  imgs.push_back(img1);
  imgs.push_back(img2);

  EXPECT_CALL(dir, getFileWithExtension(".png")).Times(1).WillOnce(Return(imgs));
  EXPECT_CALL(loader, loadImage(img2)).Times(1);
  EXPECT_CALL(loader, loadImage(img1)).Times(1);

  manager.loadAssets(&dir);
}
