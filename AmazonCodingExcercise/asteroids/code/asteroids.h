// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include "drawer.h"
#include "object.h"
#include "vector2.h"
#include "timed_image.h"
#include "player_controller.h"
#include "ai_controller.h"

#include <list>

class Asteroids
{
public:
    static Asteroids* Create(Drawer* drawer);
    ~Asteroids();
    
    static std::list<Object> shots;
    static std::list<Object> enemyShots;

    // Called from external object.
    void OnStart();
    void OnUpdate(const float deltaTime);

    void OnEnd();
    void OnRestart();
    void OnDestroy();
    
    void UpdateTimedImages(const float deltaTime);
    void DestroyOutOfRangeObjects(const float deltaTime);
    void CheckCollisions();
    void KillPlayer();
    void SpawnEnemy();
    void CreateExplosion(const Vector2& position, const bool enemyShip = true);
    AIController CreateEnemyShip(const Vector2& position);
    Object CreateAsteroid(const Vector2& position);

    void Draw();
    void DrawImages();
    void DrawText();

private:
    Drawer* drawer;

    PlayerController* player;
    std::list<Object> asteroids;
    std::list<AIController> enemies;
    std::list<TimedImage> timedImages;

    // Text labels.
    const char scoreString[10] = "SCORE: %d";
    const char livesString[10] = "LIVES: %d";
    const char thrustString[21] = "THRUST: %d%% (%.1fs)";
    const char shipExplosionImageString[19] = "explosion_00%d.png";
    const char explosionImageString[18] = "explosion_0%d.png";

    // Player stats.
    const uint8_t maxLives = 2;
    int8_t lives = maxLives;
    uint16_t score;

    // Player immunity / spawn protection.
    const float immunityTime = 1.f;
    float immunityTimeTimer;

    // Enemy spawner.
    const float enemyMinSpawnRate = 4.f;
    const float enemyMaxSpawnRate = 10.f;
    float enemySpawnRateTimer;
    // The higher the difficulty, the faster enemies spawn.
    float difficulty;

    float startMessageTimer;
};