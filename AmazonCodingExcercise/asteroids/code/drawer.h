// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include <SDL.h>
#include "texture_instance.h"
#include "textures.h"

class Drawer
{
public:
    static Drawer* Create(SDL_Window* window, SDL_Renderer* renderer);

    bool DrawImage(const char* imagePath, int posX = 0, int posY = 0);
    void DrawImageCached(const char* img, int posX, int posY);
    SDL_Texture* GetTexture(const char* imagePath);
    bool DrawText(const char* font, const char* text, float size, int posX, int posY);

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    Textures* textures;
};