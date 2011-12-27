/*
 * SurfaceLoader.h
 *
 *  Created on: Dec 21, 2011
 *      Author: emint
 */

#ifndef SURFACELOADER_H_
#define SURFACELOADER_H_

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

using namespace std;

class SurfaceLoader {
  public:
    SurfaceLoader();
    virtual ~SurfaceLoader();

    virtual SDL_Surface* loadImage(string imageName);

    virtual SDL_Surface* mainSurface(int width, int height, int bpp, Uint32 flags);
};

#endif /* SURFACELOADER_H_ */
