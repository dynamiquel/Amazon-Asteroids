// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"
#include "drawer.h"

#include <SDL.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

Asteroids::~Asteroids()
{
    delete ship;
    shots.clear();
    asteroids.clear();
    enemies.clear();
    timedImages.clear();
}

void Asteroids::Draw()
{
    DrawImages();
    DrawText();
}

void Asteroids::DrawImages()
{
    drawer->DrawImageCached("bg.png", 0, 0, false);
    drawer->DrawImageCached("ship.png", ship->rect.position);

    for (Object& asteroid : asteroids)
        drawer->DrawImageCached("asteroid.png", asteroid.rect.position);
    for (Object& shot : shots)
        drawer->DrawImageCached("shot.png", shot.rect.position);
    for (Object& enemy : enemies)
        drawer->DrawImageCached("ship_enemy.png", enemy.rect.position);
    for (TimedImage& timedImage : timedImages)
        drawer->DrawImageCached(timedImage.imageName, timedImage.position);
}

void Asteroids::DrawText()
{
    char formattedString[22];

    sprintf(formattedString, scoreString, score);
    drawer->DrawText("arial.ttf", formattedString, 40, 20, 50);

    sprintf(formattedString, livesString, lives);
    drawer->DrawText("arial.ttf", formattedString, 40, 20, 100);

    sprintf(formattedString, thrustString, (int)roundf((1 - (thrustTimeTimer * 1 / thrustTime)) * 100), thrustRechargeDelay - thrustRechargeDelayTimer);
    drawer->DrawText("arial.ttf", formattedString, 25, 20, 150);
}

void Asteroids::OnStart()
{
    ship = new Object( {640, 850}, {40, 40} );

    asteroids.push_back(CreateAsteroid( {200, 100} ));
    enemies.push_back(CreateEnemy( {640, 100} ));
}

void Asteroids::OnUpdate(const float deltaTime)
{
    fireDelayTimer += deltaTime;

    UserInput(deltaTime);
    UpdateThrust(deltaTime);
    UpdateHoverEffect(deltaTime);
    UpdateTimedImages(deltaTime);
    CheckCollisions();

    if (lives <= 0)
    {
        SDL_Log("Player dead.");
        // Respawn player.
    }
}

void Asteroids::UserInput(const float deltaTime)
{
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    const Uint32 mouseState = SDL_GetMouseState(NULL, NULL);

    if (keyState[SDL_SCANCODE_LSHIFT] && (thrustTimeTimer + deltaTime) <= thrustTime)
    {
        moveVelocity = thrustMoveVelocity;
        thrustTimeTimer += deltaTime;
    }
    else
        moveVelocity = normalMoveVelocity;    
    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_KP_4] || keyState[SDL_SCANCODE_A])
    {
        if (ship->rect.position.x > 10)
            ship->rect.position.x -= moveVelocity;
    }
    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_KP_6] || keyState[SDL_SCANCODE_D])
    {
        if (ship->rect.position.x < 1270)
            ship->rect.position.x += moveVelocity;
    }
    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_KP_8] || keyState[SDL_SCANCODE_W])
    {
        if (ship->rect.position.y > 10)
            ship->rect.position.y -= moveVelocity;
    }
    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_KP_5] || keyState[SDL_SCANCODE_S])
    {
        if (ship->rect.position.y < 1014)
            ship->rect.position.y += normalMoveVelocity;
    }
    if (keyState[SDL_SCANCODE_KP_7] || keyState[SDL_SCANCODE_Q])
    {
        // Rotate left.
    }
    if (keyState[SDL_SCANCODE_KP_9] || keyState[SDL_SCANCODE_E])
    {
        // Rotate right.
    }
    if (keyState[SDL_SCANCODE_SPACE] || keyState[SDL_SCANCODE_KP_0] || mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        Fire(deltaTime);
    }
}

void Asteroids::Fire(const float deltaTime)
{
    if (fireDelayTimer >= fireDelay)
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

    // Destroys shots that are out of range. Prevents memory issues.
    for (auto itr = shots.begin(); itr != shots.end();)
    {
        if ((itr->rect.position.y--) <= INT_MIN)
            shots.erase(itr++);
        else
            ++itr;        
    }

    // Checks collisions between shots and enemies, and destroys objects if required.
    for (auto shotItr = shots.begin(); shotItr != shots.end();)
    {
        bool shotDestroyed = false;

        for (auto itr = asteroids.begin(); itr != asteroids.end();)
        {
            if (itr->IsColliding(*shotItr))
            {
                shots.erase(shotItr++);
                shotDestroyed = true;

                if ((itr->health--) <= 1)
                {
                    asteroids.erase(itr++);
                    score++;
                }
                
                break;
            }
            else
            {
                ++itr;
            }
        }

        if (shotDestroyed)
            continue;

        for (auto itr = enemies.begin(); itr != enemies.end();)
        {
            if (itr->IsColliding(*shotItr))
            {
                shots.erase(shotItr++);
                shotDestroyed = true;
                
                if ((itr->health--) <= 1)
                {
                    CreateExplosion(itr->rect.position);
                    enemies.erase(itr++);
                    score += 2;
                }

                break;
            }
            else
            {
                ++itr;
            }
        }

        if (shotDestroyed)
            continue;

        ++shotItr;
    }
}

// Checks if the player's thrust needs replenishing, if so, it is gradually replenished.
void Asteroids::UpdateThrust(const float deltaTime)
{
    if (thrustTimeTimer > .0f && (thrustRechargeDelayTimer += deltaTime) >= thrustRechargeDelay)
    {
        if (thrustTimeTimer < prevThrustTime)
        {
            prevThrustTime = thrustTimeTimer;
            thrustTimeTimer -= deltaTime * .25f;

            if (thrustTimeTimer <= .0f)
            {
                thrustRechargeDelayTimer = .0f;
                prevThrustTime = 1000.f;
            }
        }
        else
        {
            thrustRechargeDelayTimer = .0f;
            prevThrustTime = 1000.f;
        }
    }
}

// Sequentially moves the player's ship slightly in a square pattern.
void Asteroids::UpdateHoverEffect(const float deltaTime)
{
    if ((hoverDirectionDelayTimer += deltaTime) >= hoverDirectionDelay)
    {
        switch (hoverDirection)
        {
            case 0:
                ship->rect.position.x -= 2;
                break;
            case 1:
                ship->rect.position.y -= 2;
                break;
            case 2:
                ship->rect.position.x += 2;
                break;
            case 3:
                ship->rect.position.y += 2;
                break;
        }

        if ((hoverDirection++) > 3)
            hoverDirection = 0;

        hoverDirectionDelayTimer = .0f;
    }
}

// Updates the life-time on the timedImages.
// If image has run out of life-time, destroy it.
void Asteroids::UpdateTimedImages(const float deltaTime)
{
    for (auto itr = timedImages.begin(); itr != timedImages.end();)
    {
        if ((itr->lifeTime -= deltaTime) <= .0f)
            timedImages.erase(itr++);
        else
            ++itr;
    }
}

// Chooses a random explosion image and adds it to the timedImages list.
void Asteroids::CreateExplosion(const Vector2Int& position)
{
    int index = rand() % 9;
    char* formattedString = new char[19];
    sprintf(formattedString, explosionImageString, index);
    timedImages.push_back(TimedImage {formattedString, position, .25f});
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