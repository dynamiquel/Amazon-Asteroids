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
        const float fireMinDelay = .5f;
        const float fireMaxDelay = 1.5f;
        float fireDelayTimer = .0f;
};