// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "drawer.h"
#include "object.h"
#include "asteroids.h"

#include <SDL.h>
#include <limits.h>
#include <list>

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

Object* ship = new Object({640, 850}, {40, 40});
static int moveVelocity = 1;
static std::list<Object> shots;
static std::list<Object> asteroids = { Object({500, 500}, {40, 40}) };

void Asteroids::Update(float deltatime)
{
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_KP_4] || keystate[SDL_SCANCODE_A])
    {
        ship->rect.position.x -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_KP_6] || keystate[SDL_SCANCODE_D])
    {
        ship->rect.position.x += moveVelocity;
    }
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_KP_8] || keystate[SDL_SCANCODE_W])
    {
        ship->rect.position.y -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_KP_5] || keystate[SDL_SCANCODE_S])
    {
        ship->rect.position.y += moveVelocity;
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
            shots.push_back(Object({ship->rect.position.x, ship->rect.Top()}, {15, 25}));
            fireDelayTimer = 0.0f;
        }
    }

    for (auto itr = shots.begin(); itr != shots.end();)
    {
        // Destroys the shot if it's out of range.
        if ((itr->rect.position.y--) <= INT_MIN)
            itr = shots.erase(itr);
        else
            ++itr;
            
    }

    for (Object& shot : shots)
    {
        for (auto itr = asteroids.begin(); itr != asteroids.end(); )
        {
            /*if ((shot.x >= itr.x && shot.x + shot.width <= itr.x + itr.width)
            && shot.y)*/
            if (itr->IsColliding(shot))
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
    drawer->DrawImageCached("bg.png", 0, 0, false);
    drawer->DrawImageCached("ship.png", *ship);

    for (Object& asteroid : asteroids)
    {
        drawer->DrawImageCached("ship_enemy.png", asteroid);
    }
    for (Object& shot : shots)
    {
        drawer->DrawImageCached("shot.png", shot);
    }
    //drawer->DrawText("arial.ttf", "Score: 0", 40, 20, 50);
}