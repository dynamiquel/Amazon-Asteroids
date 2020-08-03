#pragma once

#include "ship.h"

class AIController
{
    public:
        Ship* ship;
        AIController(const Vector2& position, const float rotation);

        void OnUpdate(const float deltaTime);

    protected:
        // Firing.
        const float fireMinDelay = 2.5f;
        const float fireMaxDelay = 7.5f;
        float fireDelayTimer = .0f;

        // Movement.
        float moveVelocity = 100.f;
};