#pragma once
#include<C:\mingw_dev_lib\include\SDL2\SDL.h>
#include<C:\mingw_dev_lib\include\SDL2\SDL_image.h>

class Drawing{
    public:
        //The window renderer
        static SDL_Renderer* gRenderer;
        //global reference to png image where NPC sprites are stored
        static SDL_Texture* assetsRANDOMLY_APPEARING_ENTITY;
        //global reference to png image where player sprites are stored
        static SDL_Texture* assetsPlayer;
};