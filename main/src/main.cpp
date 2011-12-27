/*
 * main.cpp
 *
 *  Created on: Dec 27, 2011
 *      Author: emint
 */
#include <iostream>
#include "Assets/AssetManager.h"
#include "Exceptions/InvalidArgumentException.h"
#include "Exceptions/ResourceNotFoundException.h"
#include "Display/SurfaceLoader.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Filesystem/DirectoryImpl.h"

using namespace std;

int main(int argc, char* argv[]){
  //Start SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    cout << "Error initializing SDL. " << SDL_GetError();
    return -1;
  }
  int flags = IMG_INIT_JPG | IMG_INIT_PNG;
  int initted=IMG_Init(flags);
  if(!initted || flags != flags) {
      cout<<"could not init SDL_Image" << endl;
      cout<<"Reason: " << IMG_GetError() << endl;
  }

  cout<<"Loading assets from: "<<argv[1]<<endl;

  AssetManager manager(new SurfaceLoader());
  try {
    manager.loadAssets(new DirectoryImpl(argv[1]));
  } catch (ResourceNotFoundException e){
    cout<<e.what()<<endl;
  } catch (InvalidArgumentException e){
    cout<<e.what()<<endl;
  }
}
