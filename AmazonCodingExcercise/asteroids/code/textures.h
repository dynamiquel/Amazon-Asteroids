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
        // Used void* with casting to store STBTTF_Font* since I couldn't figure out how to store STBTTF_Font*.
        void* GetFont(const char* fontName);
        void AddFont(const char* fontName, void* font);
        void RemoveFont(const char* fontName);
        void Clear();
    private:
        std::map<const char*, SDL_Texture*> textures;
        std::map<const char*, void*> fonts;
};