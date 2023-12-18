#pragma once
#include<C:\mingw_dev_lib\include\SDL2\SDL.h>

class Drawing{
    public:
        //The window renderer
        static SDL_Renderer* gRenderer;
        //global reference to png image where NPC sprites are stored
        static SDL_Texture* assetsNPC;
        //global reference to png image where player sprites are stored
        static SDL_Texture* assetsPlayer;
};