#include "ship.h"

Ship::Ship(const Vector2Int& position, const float rotation) : Object(position, {40, 40}, rotation, true)
{
    health = 1;
}

Object Ship::Fire()
{
    Object shot(rect.position, {15, 25});

    return shot;
}

void Ship::Move(const Vector2Int& moveBy)
{
    rect.position.x += moveBy.x;
    rect.position.y += moveBy.y;
}