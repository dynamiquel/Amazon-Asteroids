#include "texture_instance.h"

TextureInstance::TextureInstance(SDL_Texture* texture, SDL_Rect* position)
{
    this.texture = texture;
    this.position = position;
}