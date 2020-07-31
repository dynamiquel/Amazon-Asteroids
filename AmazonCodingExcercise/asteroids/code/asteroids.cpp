// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"
#include "drawer.h"

#include <SDL.h>
#include <limits.h>

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

void Asteroids::OnStart()
{
    ship = new Object( {640, 850}, {40, 40} );

    asteroids.push_back(CreateAsteroid( {200, 100} ));
    enemies.push_back(CreateEnemy( {640, 100} ));
}

void Asteroids::OnUpdate(const float deltaTime)
{
    UserInput(deltaTime);
    CheckCollisions();

    if (lives <= 0)
    {
        SDL_Log("Player dead.");
        // Respawn player.
    }
}

void Asteroids::UserInput(const float deltaTime)
{
    const Uint8* keystate = SDL_GetKeyboardState(nullptr);

    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_KP_4] || keystate[SDL_SCANCODE_A])
    {
        if (ship->rect.position.x > 0)
            ship->rect.position.x -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_KP_6] || keystate[SDL_SCANCODE_D])
    {
        if (ship->rect.position.x < 1280)
            ship->rect.position.x += moveVelocity;
    }
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_KP_8] || keystate[SDL_SCANCODE_W])
    {
        if (ship->rect.position.y > 0)
            ship->rect.position.y -= moveVelocity;
    }
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_KP_5] || keystate[SDL_SCANCODE_S])
    {
        if (ship->rect.position.y < 1024)
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
        Fire(deltaTime);
    }
}

void Asteroids::Fire(const float deltaTime)
{
    if ((fireDelayTimer += deltaTime) >= fireDelay)
    {
        shots.push_back(CreateShot( {ship->rect.position.x, ship->rect.Top()} ));
        fireDelayTimer = 0.0f;
    }
}

void Asteroids::CheckCollisions()
{
    // TODO: Refactor this
    for (Object& asteroid : asteroids)
    {
        if (asteroid.IsColliding(*ship))
        {
            lives--;
            ship->rect.position = Vector2Int { 640, 850 };
        }
    }

    for (Object& enemy : enemies)
    {
        if (enemy.IsColliding(*ship))
        {
            lives--;
            ship->rect.position = Vector2Int { 640, 850 };
        }
    }

    for (auto itr = shots.begin(); itr != shots.end();)
    {
        // Destroys the shot if it's out of range.
        if ((itr->rect.position.y--) <= INT_MIN)
            shots.erase(itr++);
        else
            ++itr;
            
    }

    for (auto shotItr = shots.begin(); shotItr != shots.end();)
    {
        bool increase = true;

        for (auto itr = asteroids.begin(); itr != asteroids.end();)
        {
            if (itr->IsColliding(*shotItr))
            {
                asteroids.erase(itr++);
                shots.erase(shotItr++);
                increase = false;
                break;
            }
            else
            {
                ++itr;
            }
        }

        for (auto itr = enemies.begin(); itr != enemies.end();)
        {
            if (itr->IsColliding(*shotItr))
            {
                enemies.erase(itr++);
                shots.erase(shotItr++);
                increase = false;
                break;
            }
            else
            {
                ++itr;
            }
        }

        if (increase)
            ++shotItr;
    }
}

void Asteroids::Draw()
{
    drawer->DrawImageCached("bg.png", 0, 0, false);
    drawer->DrawImageCached("ship.png", ship->rect.position);

    for (Object& asteroid : asteroids)
    {
        drawer->DrawImageCached("asteroid.png", asteroid.rect.position);
    }
    for (Object& shot : shots)
    {
        drawer->DrawImageCached("shot.png", shot.rect.position);
    }
    for (Object& enemy : enemies)
    {
        drawer->DrawImageCached("ship_enemy.png", enemy.rect.position);
    }
    //drawer->DrawText("arial.ttf", "Score: 0", 40, 20, 50);
}

Object Asteroids::CreateEnemy(const Vector2Int& position)
{
    Object enemy(position, {40, 40});
    enemy.health = 1;
    
    return enemy;
}

Object Asteroids::CreateAsteroid(const Vector2Int& position)
{
    Object asteroid(position, {120, 100});
    asteroid.health = 3;

    return asteroid;
}

Object Asteroids::CreateShot(const Vector2Int& position)
{
    Object shot(position, {15, 25});

    return shot;
}