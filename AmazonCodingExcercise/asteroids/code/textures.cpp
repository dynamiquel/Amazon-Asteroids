#include "textures.h"

// Attempts to get a texture from the texture map.
// Returns nullptr if none was found.
SDL_Texture* Textures::GetTexture(const char* textureName)
{
    auto pos = textures.find(textureName);

    if (pos == textures.end())
    {
        SDL_Log("Could not texture with name: %s", textureName);
        return nullptr;
    }
        return pos->second;

}

// Adds a texture to the texture map so it can be reused.
void Textures::AddTexture(const char* textureName, SDL_Texture* texture)
{
    textures[textureName] = texture;
}

void Textures::RemoveTexture(const char* textureName)
{
    textures.erase(textureName);
}

// Returns a font from the font map.
// void* is used because I couldn't figure out how to get
// STBTTF_Font to work.
void* Textures::GetFont(const char* fontName)
{
    auto pos = fonts.find(fontName);

    if (pos == fonts.end())
    {
        SDL_Log("Could not font with name: %s", fontName);
        return nullptr;
    }
        return pos->second;

}

// Adds a font to the font map so it can be reused.
void Textures::AddFont(const char* fontName, void* font)
{
    fonts[fontName] = font;
}

void Textures::RemoveFont(const char* fontName)
{
    fonts.erase(fontName);
}

void Textures::Clear()
{
    textures.clear();
    fonts.clear();
}