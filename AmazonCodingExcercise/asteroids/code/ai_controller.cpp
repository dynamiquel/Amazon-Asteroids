#include "ai_controller.h"
#include "asteroids.h"

AIController::AIController(const Vector2Int& position, const float rotation)
{
    ship = new Ship(position, rotation);
}

void AIController::OnUpdate(const float deltaTime)
{
    fireDelayTimer += deltaTime;

    ship->rect.position.y++;

    if (fireDelayTimer >= fireDelay)
    {
        Asteroids::enemyShots.push_back(ship->Fire());
        fireDelayTimer = 0.0f;
    }

    ship->OnUpdate(deltaTime);
}