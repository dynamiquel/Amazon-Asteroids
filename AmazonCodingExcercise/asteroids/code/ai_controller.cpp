#include "ai_controller.h"
#include "asteroids.h"

#include <stdlib.h>

AIController::AIController(const Vector2Int& position, const float rotation)
{
    ship = new Ship(position, rotation);
}

void AIController::OnUpdate(const float deltaTime)
{
    fireDelayTimer -= deltaTime;

    ship->rect.position.y++;

    if (fireDelayTimer <= 0)
    {
        Asteroids::enemyShots.push_back(ship->Fire());

        // Chooses a random fire delay between fireMinDelay and fireMaxDelay.
        fireDelayTimer = fireMinDelay + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(fireMaxDelay - fireMinDelay)));
    }

    ship->OnUpdate(deltaTime);
}