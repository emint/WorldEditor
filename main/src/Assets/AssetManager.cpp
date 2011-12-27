/*
 * AssetManager.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#include "AssetManager.h"
#include <iostream>
using namespace boost::filesystem;

AssetManager::AssetManager() {
  // TODO Auto-generated constructor stub

}

AssetManager::~AssetManager() {
  // TODO Auto-generated destructor stub
}

void AssetManager::loadAssets(string assetFolder){
  path folder(assetFolder);
  if (!exists(folder)){
    throw ResourceNotFoundException("Folder does not exist");
  }
  if (!is_directory(folder)){
    throw InvalidArgumentException("Argument is not a folder");
  }

  for (directory_iterator iter(folder), end; iter != end; ++iter){
    if(extension(iter->path()) == ".png"){
      cout<<"Found image: "<<basename(iter->path())<<endl;
    }
  }


}
