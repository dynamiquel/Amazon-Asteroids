#include <SDL.h>

#pragma once

class TextureInstance
{
    public:
        SDL_Texture* texture;
        SDL_Rect* position;

        TextureInstance(SDL_Texture* texture, SDL_Rect* position);
}