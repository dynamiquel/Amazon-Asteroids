// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"
#include "drawer.h"

#include <SDL.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

std::list<Object> Asteroids::shots = std::list<Object>();

/*static*/ Asteroids* Asteroids::Create(Drawer* drawer)
{
    Asteroids* newAsteroids = new Asteroids();
    newAsteroids->drawer = drawer;
    return newAsteroids;
}

Asteroids::~Asteroids()
{
    delete player;
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
    drawer->DrawImage("bg.png", 0, 0, 0, false);
    drawer->DrawImage("ship.png", *(player->ship));

    for (Object& asteroid : asteroids)
        drawer->DrawImage("asteroid.png", asteroid);
    for (Object& shot : shots)
        drawer->DrawImage("shot.png", shot);
    for (Object& enemy : enemies)
        drawer->DrawImage("ship_enemy.png", enemy);
    for (TimedImage& timedImage : timedImages)
        drawer->DrawImage(timedImage.imageName, timedImage.position);
}

void Asteroids::DrawText()
{
    char formattedString[22];

    sprintf(formattedString, scoreString, score);
    drawer->DrawText("arial.ttf", formattedString, 40, 20, 50);

    sprintf(formattedString, livesString, lives);
    drawer->DrawText("arial.ttf", formattedString, 40, 20, 100);

    sprintf(formattedString, thrustString, player->GetThrustPerc(), player->GetThrustRecharge());
    drawer->DrawText("arial.ttf", formattedString, 25, 20, 150);
}

void Asteroids::OnStart()
{
    player = new PlayerController();

    asteroids.push_back(CreateAsteroid( {200, 100} ));
    enemies.push_back(CreateEnemy( {640, 100} ));
}

void Asteroids::OnUpdate(const float deltaTime)
{
    player->OnUpdate(deltaTime);
    UpdateTimedImages(deltaTime);
    CheckCollisions();

    if (lives <= 0)
    {
        SDL_Log("Player dead.");
        // Respawn player.
    }
}

void Asteroids::CheckCollisions()
{
    // TODO: Refactor this
    for (Object& asteroid : asteroids)
    {
        if (asteroid.IsColliding(*(player->ship)))
        {
            lives--;
            player->ship->rect.position = Vector2Int { 640, 850 };
        }
    }

    for (Object& enemy : enemies)
    {
        if (enemy.IsColliding(*(player->ship)))
        {
            lives--;
            player->ship->rect.position = Vector2Int { 640, 850 };
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
    Object enemy(position, {40, 40}, 45.f);
    enemy.health = 1;
    
    return enemy;
}

Object Asteroids::CreateAsteroid(const Vector2Int& position)
{
    Object asteroid(position, {120, 100});
    asteroid.health = 3;

    return asteroid;
}