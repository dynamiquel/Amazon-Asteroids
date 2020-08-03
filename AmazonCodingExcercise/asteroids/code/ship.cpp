#include "ship.h"

Ship::Ship(const Vector2Int& position, const float rotation) : Object(position, {40, 40}, rotation, true)
{
    health = 1;
}

/*static*/ Object Ship::CreateShot(const Vector2Int& position, const float rotation)
{
    return Object(position, {15, 25}, rotation);
}

void Ship::OnUpdate(const float deltaTime)
{
    UpdateHoverEffect(deltaTime);
}

Object Ship::Fire()
{
    return CreateShot(rect.position, rect.rotation);
}

void Ship::Move(const Vector2Int& moveBy)
{
    rect.position.x += moveBy.x;
    rect.position.y += moveBy.y;
}

// Sequentially moves the player's ship slightly in a square pattern.
void Ship::UpdateHoverEffect(const float deltaTime)
{
    if ((hoverDirectionDelayTimer += deltaTime) >= hoverDirectionDelay)
    {
        switch (hoverDirection)
        {
            case 0:
                rect.position.x -= 2;
                break;
            case 1:
                rect.position.y -= 2;
                break;
            case 2:
                rect.position.x += 2;
                break;
            case 3:
                rect.position.y += 2;
                break;
        }

        if ((hoverDirection++) > 3)
            hoverDirection = 0;

        hoverDirectionDelayTimer = .0f;
    }
}