// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include <SDL.h>
#include "texture_instance.h"

#pragma once

struct SDL_Window;
struct SDL_Renderer;

class Drawer
{
public:
    static Drawer* Create(SDL_Window* window, SDL_Renderer* renderer);

    bool DrawImage(const char* imagePath, int posX = 0, int posY = 0);
    bool GetTexture(const char* img, int posX, int posY, /*OUT*/ TextureInstance* texture);
    bool DrawText(const char* font, const char* text, float size, int posX, int posY);

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};