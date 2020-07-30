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
    newDrawer->textures = new Textures();
    return newDrawer;
}

Drawer::~Drawer()
{
    textures->Clear();
    delete textures;
}

bool Drawer::DrawImage(const char* img, int posX, int posY)
{
    SDL_Surface* surface = CreateImageSurface(img);
    if (surface)
    {
        SDL_Texture* optimizedSurface = SDL_CreateTextureFromSurface(m_renderer, surface);

        SDL_Rect sizeRect;
        sizeRect.x = 0;
        sizeRect.y = 0;
        sizeRect.w = surface->w;
        sizeRect.h = surface->h;

        SDL_Rect posRect;
        posRect.x = posX;
        posRect.y = posY;
        posRect.w = sizeRect.w;
        posRect.h = sizeRect.h;

        SDL_RenderCopy(m_renderer, optimizedSurface, &sizeRect, &posRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(optimizedSurface);

        return true;
    }
    else
    {
        return false;
    }
}

bool Drawer::DrawImageCached(const char* img, const Object& object, const bool fromCentre)
{
    return DrawImageCached(img, object.rect.position.x, object.rect.position.y, fromCentre);
}

bool Drawer::DrawImageCached(const char* img, int posX, int posY, const bool fromCentre)
{
    SDL_Texture* texture = textures->GetTexture(img);

    if (texture == nullptr)
    {
        texture = GetTexture(img);

        if (!texture)
            return false;

        textures->AddTexture(img, texture);
    }

    int width;
    int height;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    SDL_Rect posRect;
    if (fromCentre)
    {
        posRect.x = posX - (int)(roundf(width * .5f));
        posRect.y = posY - (int)(roundf(height * .5f));
    }
    else
    {
        posRect.x = posX;
        posRect.y = posY;
    }
    posRect.w = width;
    posRect.h = height;

    SDL_RenderCopy(m_renderer, texture, NULL, &posRect);

    return true;
}

SDL_Texture* Drawer::GetTexture(const char* img)
{
    SDL_Surface* surface = CreateImageSurface(img);
    if (surface)
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(m_renderer, surface);
        SDL_FreeSurface(surface);

        return texture;
    }
    else
    {
        SDL_Log("Error loading image: %s", img);
        return nullptr;
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
