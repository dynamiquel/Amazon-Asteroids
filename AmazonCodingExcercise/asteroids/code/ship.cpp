#include "ship.h"
#include "asteroids.h"

Ship::Ship(const Vector2Int& position, const float rotation) : Object(position, {40, 40}, rotation, true)
{
    health = 1;
}

/*static*/ Object Ship::CreateShot(const Vector2Int& position)
{
    Object shot(position, {15, 25});

    return shot;
}

Object& Ship::Fire()
{
    Asteroids::shots.push_back(CreateShot(rect.position));
    
    return Asteroids::shots.back();
}

void Ship::Move(const Vector2Int& moveBy)
{
    rect.position.x += moveBy.x;
    rect.position.y += moveBy.y;
}