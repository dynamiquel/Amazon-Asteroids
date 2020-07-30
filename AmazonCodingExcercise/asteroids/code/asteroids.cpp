// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"
#include <SDL.h>
#include <list>
#include "drawer.h"
#include "object.h"

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

static int px = 200;
static int py = 300;
static int moveVelocity = 5;
static std::list<Object> shots;
static std::list<Object> asteroids = { Object{ {200, 200} } };

void Asteroids::Update(float deltatime)
{
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_KP_4] || keystate[SDL_SCANCODE_A])
    {
        px -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_KP_6] || keystate[SDL_SCANCODE_D])
    {
        px += moveVelocity;
    }
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_KP_8] || keystate[SDL_SCANCODE_W])
    {
        py -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_KP_5] || keystate[SDL_SCANCODE_S])
    {
        py += moveVelocity;
    }
    if (keystate[SDL_SCANCODE_KP_7] || keystate[SDL_SCANCODE_Q])
    {
        // Rotate left.
    }
    if (keystate[SDL_SCANCODE_KP_9] || keystate[SDL_SCANCODE_E])
    {
        // Rotate right.
    }

    if (keystate[SDL_SCANCODE_SPACE] || keystate[SDL_SCANCODE_KP_0])
    {
        if ((fireDelayTimer += deltatime) >= fireDelay)
        {
            shots.push_back(Object{ {px, py} });
            fireDelayTimer = 0.0f;
        }
    }

    for (Object& shot : shots)
    {
        shot.position.y -= 1;
    }

    for (Object& shot : shots)
    {
        for (auto itr = asteroids.begin(); itr != asteroids.end(); )
        {
            /*if ((shot.x >= itr.x && shot.x + shot.width <= itr.x + itr.width)
            && shot.y)*/

            if (shot.position.x == itr->position.x && shot.position.y == itr->position.y)
            {
                itr = asteroids.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
    }
}

void Asteroids::Draw()
{
    drawer->DrawImageCached("bg.png", 0, 0);
    drawer->DrawImageCached("ship.png", px - 20, py - 20);

    for (Object& asteroid : asteroids)
    {
        drawer->DrawImageCached("asteroid.png", asteroid.position.x - 100, asteroid.position.y - 100);
    }
    for (Object& shot : shots)
    {
        drawer->DrawImageCached("shot.png", shot.position.x - 14, shot.position.y - 16);
    }
    //drawer->DrawText("arial.ttf", "Score: 0", 40, 20, 50);
}