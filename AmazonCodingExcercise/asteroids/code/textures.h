#pragma once

#include <map>
#include <SDL.h>

class Textures
{
    public:
        Textures();
        SDL_Texture* GetTexture(const char* textureName);
        void AddTexture(const char* textureName, SDL_Texture* texture);
        void RemoveTexture(const char* textureName);
        void Clear();
    private:
        std::map<const char*, SDL_Texture*> textures;
};