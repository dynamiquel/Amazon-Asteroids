// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include "drawer.h"
#include "object.h"
#include "vector2int.h"
#include "timed_image.h"

#include <list>

class Asteroids
{
public:
    static Asteroids* Create(Drawer* drawer);
    ~Asteroids();
    
    static std::list<Object> shots;

    void Draw();
    void DrawImages();
    void DrawText();

    void OnStart();
    void OnUpdate(const float deltaTime);
    
    void UserInput(const float deltaTime);
    void Fire(const float deltaTime);
    void UpdateThrust(const float deltaTime);
    void UpdateHoverEffect(const float deltaTime);
    void UpdateTimedImages(const float deltaTime);
    void CheckCollisions();

    void CreateExplosion(const Vector2Int& position);
    Object CreateEnemy(const Vector2Int& position);
    Object CreateAsteroid(const Vector2Int& position);
    Object CreateShot(const Vector2Int& position);

private:
    Drawer* drawer;

    Object* ship;
    std::list<Object> asteroids;
    std::list<Object> enemies;
    std::list<TimedImage> timedImages;

    // Text labels.
    const char scoreString[10] = "Score: %d";
    const char livesString[10] = "Lives: %d";
    const char thrustString[21] = "Thrust: %d%% (%.1fs)";
    const char explosionImageString[19] = "explosion_00%d.png";

    // Player ship firing.
    const float fireDelay = .5f;
    float fireDelayTimer = .0f;
    const float fastFireDelay = .1f;
    float fastFireDelayTimer = .0f;
    const float fastFireChargeDelay = 5.0f;
    float fastFireChargeDelayTimer = .0f;

    // Player stats.
    const uint8_t maxLives = 3;
    int8_t lives = maxLives;
    uint16_t score = 0;

    // Player ship movement.
    const uint8_t normalMoveVelocity = 1;
    const uint8_t thrustMoveVelocity = 3;
    uint8_t moveVelocity = normalMoveVelocity;
    const float thrustTime = 1.f;
    float thrustTimeTimer = .0f;
    const float thrustRechargeDelay = 5.f;
    float thrustRechargeDelayTimer = .0f;
    float prevThrustTime = 1000.f;

    // Player ship hover effect.
    uint8_t hoverDirection = 0; // Left, Top, Right, Bottom.
    const float hoverDirectionDelay = .25f;
    float hoverDirectionDelayTimer = .0f;
};