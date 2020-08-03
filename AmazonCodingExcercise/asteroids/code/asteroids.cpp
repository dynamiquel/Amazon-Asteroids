// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "asteroids.h"
#include "drawer.h"
#include "main.h"

#include <SDL.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

std::list<Object> Asteroids::shots = std::list<Object>();
std::list<Object> Asteroids::enemyShots = std::list<Object>();

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
    for (Object& shot : enemyShots)
        drawer->DrawImage("shot.png", shot);
    for (AIController& enemy : enemies)
        drawer->DrawImage("ship_enemy.png", *(enemy.ship));
    for (TimedImage& timedImage : timedImages)
        drawer->DrawImage(timedImage.imageName, timedImage.position);

    if (lives <= 0)
        drawer->DrawText("arial.ttf", "Game Over!", 80, 450, 400);
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
}

// All OnUpdates = once per frame.
void Asteroids::OnUpdate(const float deltaTime)
{
    if (lives <= 0)
        return OnEnd();

    // Reduces the immunity time the player has.
    immunityTimeTimer -= deltaTime;

    player->OnUpdate(deltaTime);
    
    for (auto itr = enemies.begin(); itr != enemies.end();)
    {
        itr->OnUpdate(deltaTime);

        // Destroys enemy ships that are out of range.
        if (itr->ship->rect.position.y >= 1040)
        {
            enemies.erase(itr++);
            lives--;
        }
        else
            ++itr;
    }

    for (auto itr = asteroids.begin(); itr != asteroids.end();)
    {
        itr->rect.position.y += 30.f * deltaTime;
        // Destroys enemy ships that are out of range.
        if (itr->rect.position.y >= 1040)
        {
            asteroids.erase(itr++);
        }
        else
            ++itr;
    }

    UpdateTimedImages(deltaTime);
    CheckCollisions();
    
    if ((enemySpawnRateTimer -= deltaTime) <= 0)
        SpawnEnemy();
}

void Asteroids::CheckCollisions()
{
    // If player has no immunity left.
    if (immunityTimeTimer <= 0)
    {
        // Player hits asteroid.
        for (Object& asteroid : asteroids)
        {
            if (asteroid.IsColliding(*(player->ship)))
                KillPlayer();
        }

        // Player hits enemy ship.
        for (AIController& enemy : enemies)
        {
            if (enemy.ship->IsColliding(*(player->ship)))
                KillPlayer();
        }
    }

    // Destroys shots that are out of range. Prevents memory issues.
    for (auto itr = shots.begin(); itr != shots.end();)
    {
        if ((itr->rect.position.y--) <= FLT_MIN)
            shots.erase(itr++);
        else
            ++itr;        
    }

    for (auto itr = enemyShots.begin(); itr != enemyShots.end();)
    {
        if ((itr->rect.position.y++) >= FLT_MAX)
            enemyShots.erase(itr++);
        else
            ++itr;        
    }

    // Checks collisions between player shots and (enemies and asteroids), and destroys objects if required.
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
            if (itr->ship->IsColliding(*shotItr))
            {
                shots.erase(shotItr++);
                shotDestroyed = true;
                
                if ((itr->ship->health--) <= 1)
                {
                    CreateExplosion(itr->ship->rect.position);
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

    // Checks collisions between enemy shots and (player and asteroids), and destroys objects if required.
    for (auto shotItr = enemyShots.begin(); shotItr != enemyShots.end();)
    {
        bool shotDestroyed = false;

        for (auto itr = asteroids.begin(); itr != asteroids.end();)
        {
            if (itr->IsColliding(*shotItr))
            {
                enemyShots.erase(shotItr++);
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

        // Only damage player if the player is no longer immune.
        if (immunityTimeTimer <= 0 && shotItr->IsColliding(*(player->ship)))
        {
            enemyShots.erase(shotItr++);
            shotDestroyed = true;
            
            if ((player->ship->health--) <= 1)
                KillPlayer();

            break;
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

void Asteroids::KillPlayer()
{
    lives--;
    CreateExplosion(player->ship->rect.position);
    // Moves the player's ship back to spawn.
    player->ship->rect.position = Vector2 { 640, 850 };
    // Makes the player immune for a bit to prevent spawn-killing.
    immunityTimeTimer = immunityTime;
}

// Responsible for spawning in an enemy ship or asteroid.
// A delay is then chosen before spawning the next enemy.
// Difficulty is increased.
void Asteroids::SpawnEnemy()
{
    // Chooses a random X position for the enemy to spawn at.
    float randomXPos = static_cast<float>(rand() % 1270 + 10);

    // 1 in 4 chance of an asteroid spawning.
    // 3 in 4 chance of an enemy ship spawning.
    if ((rand() % 4) >= 1)
        enemies.push_back(CreateEnemyShip({randomXPos, -40}));
    else
        asteroids.push_back(CreateAsteroid({randomXPos, -40}));

    // Chooses when the next enemy spawns by choosing a random number between enemyMaxSpawnRate and enemyMinSpawnRate.
    // Result is then divided by difficulty to make enemies spawn faster as time goes on.
    enemySpawnRateTimer = (enemyMinSpawnRate 
        + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(enemyMaxSpawnRate - enemyMinSpawnRate))))
        / difficulty;

    difficulty *= 1.02f;
}

void Asteroids::OnEnd()
{
    
}

// Chooses a random explosion image and adds it to the timedImages list.
void Asteroids::CreateExplosion(const Vector2& position)
{
    int index = rand() % 9;
    char* formattedString = new char[19];
    sprintf(formattedString, explosionImageString, index);
    timedImages.push_back(TimedImage {formattedString, position, .25f});
}

AIController Asteroids::CreateEnemyShip(const Vector2& position)
{
    return AIController(position, 180);
}

Object Asteroids::CreateAsteroid(const Vector2& position)
{
    Object asteroid(position, {120, 100});
    asteroid.health = 3;

    return asteroid;
}