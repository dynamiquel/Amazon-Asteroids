// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include <SDL.h>
#include "textures.h"
#include "object.h"
#include "vector2int.h"

class Drawer
{
public:
    static Drawer* Create(SDL_Window* window, SDL_Renderer* renderer);
    ~Drawer();

    bool DrawImage(const char* imagePath, int posX = 0, int posY = 0);
    bool DrawImageCached(const char* img, int posX, int posY, const bool fromCentre = true);
    bool DrawImageCached(const char* img, const Vector2Int& position, const bool fromCentre = true);
    SDL_Texture* GetTexture(const char* imagePath);
    bool DrawText(const char* fontName, const char* text, float size, int posX, int posY);

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    Textures* textures;
};