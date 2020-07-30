// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

#include "drawer.h"

class Asteroids
{
public:
    static Asteroids* Create(Drawer* drawer);
    
    void Update(float deltaTime);
    void Draw();

private:
    Drawer* drawer;
    const float fireDelay = .5f;
    float fireDelayTimer = .0f;
    const float fastFireDelay = .1f;
    float fastFireDelayTimer = .0f;
    const float fastFireChargeDelay = 5.0f;
    float fastFireChargeDelayTimer = .0f;
};