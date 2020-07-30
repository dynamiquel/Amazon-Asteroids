#include "texture_instance.h"

TextureInstance::TextureInstance(SDL_Texture* tex, SDL_Rect* pos)
{
    texture = tex;
    position = pos;
}