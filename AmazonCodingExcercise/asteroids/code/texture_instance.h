#include <SDL.h>

struct TextureInstance
{
    public:
        SDL_Texture* texture;
        SDL_Rect* position;

        TextureInstance(SDL_Texture* tex, SDL_Rect* pos);
};