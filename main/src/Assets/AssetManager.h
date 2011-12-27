/*
 * AssetManager.h
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_

#include <string>
#include "../Filesystem/Directory.h"
#include "../Display/SurfaceLoader.h"

using namespace std;

class AssetManager {
  public:
    AssetManager(SurfaceLoader* loader);
    virtual ~AssetManager();

    virtual void loadAssets(string assetFolder);
  private:
    SurfaceLoader* loader_;
};

#endif /* ASSETMANAGER_H_ */
