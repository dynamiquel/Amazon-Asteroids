#include "textures.h"

Textures::Textures()
{
}

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

void Textures::Clear()
{
    textures.clear();
}