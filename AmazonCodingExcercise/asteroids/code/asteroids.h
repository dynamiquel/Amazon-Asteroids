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
    
    void OnStart();
    void OnUpdate(const float deltaTime);
    void UserInput(const float deltaTime);
    void Fire(const float deltaTime);
    void CheckCollisions();
    void Draw();

    Object CreateEnemy(const Vector2Int& position);
    Object CreateAsteroid(const Vector2Int& position);
    Object CreateShot(const Vector2Int& position);

private:
    Drawer* drawer;

    Object* ship;
    std::list<Object> shots;
    std::list<Object> asteroids;
    std::list<Object> enemies;

    const float fireDelay = .5f;
    float fireDelayTimer = .0f;
    const float fastFireDelay = .1f;
    float fastFireDelayTimer = .0f;
    const float fastFireChargeDelay = 5.0f;
    float fastFireChargeDelayTimer = .0f;

    const short maxLives = 3;
    short lives = maxLives;

    const short normalMoveVelocity = 1;
    const short thrustMoveVelocity = 3;
    short moveVelocity = normalMoveVelocity;
};