// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "drawer.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBTTF_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION
#define STB_RECT_PACK_IMPLEMENTATION

#include <stb_image.h>
#include <stbttf.h>

static SDL_Surface* CreateImageSurface(const char* img)
{
    int req_format = STBI_rgb_alpha;
    int width, height, orig_format;
    unsigned char* data = stbi_load(img, &width, &height, &orig_format, req_format);
    if (data == nullptr)
    {
        SDL_Log("Loading image %s failed: %s", img, stbi_failure_reason());
        return nullptr;
    }

    int depth, pitch;
    Uint32 pixel_format;
    if (req_format == STBI_rgb_alpha)
    {
        depth = 32;
        pitch = 4 * width;
        pixel_format = SDL_PIXELFORMAT_RGBA32;
    }

    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, width, height,
                                                           depth, pitch, pixel_format);
                                                        
    if (surface == nullptr)
    {
        SDL_Log("Creating surface failed: %s", SDL_GetError());
        return nullptr;
    }

    return surface;
}

/*static*/ Drawer* Drawer::Create(SDL_Window* window, SDL_Renderer* renderer)
{
    Drawer* newDrawer = new Drawer();
    newDrawer->m_window = window;
    newDrawer->m_renderer = renderer;
    return newDrawer;
}

bool Drawer::DrawImage(const char* img, int posX, int posY)
{
    SDL_Surface* surface = CreateImageSurface(img);
    if (surface)
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        SDL_FreeSurface(surface);

        SDL_Rect posRect;
        posRect.x = posX;
        posRect.y = posY;
        posRect.w = surface->w;
        posRect.h = surface->h;

        SDL_RenderCopy(m_renderer, texture, NULL, &posRect);       
        SDL_DestroyTexture(texture);

        return true;
    }
    else
    {
        return false;
    }
}

bool Drawer::GetTexture(const char* img, int posX, int posY, /*OUT*/ TextureInstance* texture)
{
    SDL_Surface* surface = CreateImageSurface(img);
    if (surface)
    {
        SDL_Texture* tex = SDL_CreateTextureFromSurface(m_renderer, surface);
        SDL_FreeSurface(surface);

        SDL_Rect positionRect;
        positionRect.x = posX;
        positionRect.y = posY;
        positionRect.w = surface->w;
        positionRect.h = surface->h;

        texture = new TextureInstance(tex, &positionRect);

        return true;
    }
    else
    {
        return false;
    }
}

bool Drawer::DrawText(const char* font, const char* text, float size, int posX, int posY)
{
    STBTTF_Font* stbFont = STBTTF_OpenFont(m_renderer, font, size);
    if (stbFont)
    {
        SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
        STBTTF_RenderText(m_renderer, stbFont, posX, posY, text);
        return true;
    }
    else
    {
        SDL_Log("Error loading font: %s", font);
        return false;
    }
}
