// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include "drawer.h"
#include "object.h"
#include "vector2int.h"
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

    void Draw();
    void DrawImages();
    void DrawText();

    void OnStart();
    void OnUpdate(const float deltaTime);
    
    void UpdateTimedImages(const float deltaTime);
    void CheckCollisions();
    void KillPlayer();
    void SpawnEnemy();

    void CreateExplosion(const Vector2Int& position);
    AIController CreateEnemy(const Vector2Int& position);
    Object CreateAsteroid(const Vector2Int& position);

private:
    Drawer* drawer;

    PlayerController* player;
    std::list<Object> asteroids;
    std::list<AIController> enemies;
    std::list<TimedImage> timedImages;

    // Text labels.
    const char scoreString[10] = "Score: %d";
    const char livesString[10] = "Lives: %d";
    const char thrustString[21] = "Thrust: %d%% (%.1fs)";
    const char explosionImageString[19] = "explosion_00%d.png";

    // Player stats.
    const uint8_t maxLives = 3;
    int8_t lives = maxLives;
    uint16_t score = 0;

    // Player immunity / spawn protection.
    const float immunityTime = 1.f;
    float immunityTimeTimer = .0f;

    // Enemy spawner.
    const float enemyMinSpawnRate = 4.f;
    const float enemyMaxSpawnRate = 10.f;
    float enemySpawnRateTimer = .0f;
    // The higher the difficulty, the faster enemies spawn.
    float difficulty = 1.f;
};