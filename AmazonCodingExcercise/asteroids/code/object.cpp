#include "object.h"

#include <math.h>

Object::Object(const Vector2& position, const Vector2& size, const float rotation, const bool fromCentre)
{
    if (fromCentre)
    {
        this->rect.position = position;
    }
    else
    {
        this->rect.position.x = position.x + (int)roundf(size.x * .5f);
        this->rect.position.y = position.y + (int)roundf(size.y * .5f);
    }

    this->rect.size = size;
    this->rect.rotation = rotation;
}

bool Object::IsColliding(const Object& object) const
{
    return rect.Left() < object.rect.Right()
           && rect.Right() > object.rect.Left()
           && rect.Top() < object.rect.Bottom()
           && rect.Bottom() > object.rect.Top();
}