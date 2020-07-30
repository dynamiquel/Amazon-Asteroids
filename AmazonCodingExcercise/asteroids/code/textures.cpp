#include "textures.h"

Textures::Textures()
{
}

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