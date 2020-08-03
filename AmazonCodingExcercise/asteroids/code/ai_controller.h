#pragma once

#include "ship.h"

class AIController
{
    public:
        Ship* ship;
        AIController(const Vector2Int& position, const float rotation);

        void OnUpdate(const float deltaTime);

    protected:
        // Firing.
        const float fireDelay = .5f;
        float fireDelayTimer = .0f;
};