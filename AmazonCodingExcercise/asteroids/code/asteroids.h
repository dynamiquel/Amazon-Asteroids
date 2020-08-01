// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include "drawer.h"
#include "object.h"
#include "vector2int.h"

#include <list>

class Asteroids
{
public:
    static Asteroids* Create(Drawer* drawer);
    ~Asteroids();
    
    void Draw();
    void DrawImages();
    void DrawText();
    void OnStart();
    void OnUpdate(const float deltaTime);
    void UserInput(const float deltaTime);
    void Fire(const float deltaTime);
    void UpdateThrust(const float deltaTime);
    void UpdateHoverEffect(const float deltaTime);
    void CheckCollisions();

    Object CreateEnemy(const Vector2Int& position);
    Object CreateAsteroid(const Vector2Int& position);
    Object CreateShot(const Vector2Int& position);

private:
    Drawer* drawer;

    Object* ship;
    std::list<Object> shots;
    std::list<Object> asteroids;
    std::list<Object> enemies;

    const char scoreString[10] = "Score: %d";
    const char livesString[10] = "Lives: %d";
    const char thrustString[21] = "Thrust: %d%% (%.1fs)";

    const float fireDelay = .5f;
    float fireDelayTimer = .0f;
    const float fastFireDelay = .1f;
    float fastFireDelayTimer = .0f;
    const float fastFireChargeDelay = 5.0f;
    float fastFireChargeDelayTimer = .0f;

    const short maxLives = 3;
    short lives = maxLives;
    short score = 0;

    const short normalMoveVelocity = 1;
    const short thrustMoveVelocity = 3;
    short moveVelocity = normalMoveVelocity;
    const float thrustTime = 1.f;
    float thrustTimeTimer = .0f;
    const float thrustRechargeDelay = 5.f;
    float thrustRechargeDelayTimer = .0f;
    float prevThrustTime = 1000.f;

    Uint8 hoverDirection = 0; // Left, Top, Right, Bottom.
    const float hoverDirectionDelay = .25f;
    float hoverDirectionDelayTimer = .0f;
};