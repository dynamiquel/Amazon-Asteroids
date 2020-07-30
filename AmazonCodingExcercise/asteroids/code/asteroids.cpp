// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"

#include <SDL.h>
#include <list>

#include "drawer.h"

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

struct Position
{
    int x;
    int y;
};

static int px = 200;
static int py = 300;
static std::list<Position> shots;
static std::list<Position> asteroids = { Position{ 200, 100 } };

void Asteroids::Update(float deltatime)
{
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);
    if (keystate[SDL_SCANCODE_LEFT])
    {
        px -= 5;
    }
    if (keystate[SDL_SCANCODE_RIGHT])
    {
        px += 5;
    }
    if (keystate[SDL_SCANCODE_UP])
    {
        py -= 5;
    }
    if (keystate[SDL_SCANCODE_DOWN])
    {
        py += 5;
    }

    if (keystate[SDL_SCANCODE_SPACE])
    {
        shots.push_back(Position{ px, py });
    }

    for (Position& shot : shots)
    {
        shot.y -= 1;
    }

    for (Position shot : shots)
    {
        for (std::list<Position>::iterator itr = asteroids.begin(); itr != asteroids.end(); )
        {
            if (shot.x == itr->x && shot.y == itr->y)
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

    for (Position asteroid : asteroids)
    {
        drawer->DrawImageCached("asteroid.png", asteroid.x - 100, asteroid.y - 100);
    }
    for (Position shot : shots)
    {
        drawer->DrawImageCached("shot.png", shot.x - 14, shot.y - 16);
    }
    //drawer->DrawText("arial.ttf", "Score: 0", 40, 20, 50);
}