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

bool Drawer::DrawImage(const char* img, const Object& object, const bool fromCentre)
{
    return DrawImage(img, object.rect.position, object.rect.rotation, fromCentre);
}

bool Drawer::DrawImage(const char* img, const Vector2& position, const float rotation, const bool fromCentre)
{
    return DrawImage(img, position.x, position.y, rotation, fromCentre);
}

// Draws a texture to the screen, using cached textures.
bool Drawer::DrawImage(const char* img, int posX, int posY, const float rotation, const bool fromCentre)
{
    // Attempts to get a cached texture with the given image name.
    SDL_Texture* texture = textures->GetTexture(img);

    // No cached textures with the given image name.
    if (texture == nullptr)
    {
        texture = GetTexture(img);

        if (!texture)
            return false;

        textures->AddTexture(img, texture);
    }

    // Gets the height and width of the texture.
    int width;
    int height;
    SDL_QueryTexture(texture, NULL, NULL, /*out*/ &width, /*out*/ &height);

    SDL_Rect posRect;
    // If the given's positions were centre positions; not top-left.
    if (fromCentre)
    {
        // Positions the centre of the texture to the given positions.
        posRect.x = posX - (int)(roundf(width * .5f));
        posRect.y = posY - (int)(roundf(height * .5f));
    }
    else
    {
        // Positions the top-left corner of the texture to the given positions.
        posRect.x = posX;
        posRect.y = posY;
    }
    posRect.w = width;
    posRect.h = height;

    // Like SDL_RenderCopy but allows rotation.
    SDL_RenderCopyEx(m_renderer, texture, NULL, &posRect, rotation, NULL, SDL_FLIP_NONE);

    return true;
}

// Creates a new texture with the given image and returns it.
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

bool Drawer::DrawText(const char* fontName, const char* text, float size, int posX, int posY)
{
    // Attempts to get a cached font with the given font name.
    STBTTF_Font* stbFont = (STBTTF_Font*)textures->GetFont(fontName);

    // No cached font with the given image name.
    if (stbFont == nullptr)
    {
        stbFont = STBTTF_OpenFont(m_renderer, fontName, size);

        if (!stbFont)
        {
            SDL_Log("Error loading font: %s", fontName);
            return false;
        }

        textures->AddFont(fontName, (void*)stbFont);
    }

    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
    STBTTF_RenderText(m_renderer, stbFont, posX, posY, text);
    return true;
}
