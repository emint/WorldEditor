/*
 * AssetManager.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager(SurfaceLoader* loader) : loader_(loader) {
  // TODO Auto-generated constructor stub

}

AssetManager::~AssetManager() {
  // TODO Auto-generated destructor stub
}

void AssetManager::loadAssets(string assetFolder){
  Directory dir(assetFolder);

  vector<string> imgs = dir.getFileWithExtension(".png");

  for(vector<string>::iterator iter = imgs.begin(); iter != imgs.end(); ++iter){
    loader_->loadImage(*iter);
  }

}
