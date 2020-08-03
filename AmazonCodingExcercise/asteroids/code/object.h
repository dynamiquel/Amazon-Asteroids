#pragma once

#include <math.h>
#include "vector2.h"

class Object
{
    public:
        struct Rect
        {
            Vector2 position;
            // Size is solely for collider.
            Vector2 size;
            float rotation = .0f;

            int Top() const
            {return position.y - (int)roundf(size.y * .5f);}
            int Bottom() const {return position.y + (int)roundf(size.y * .5f);}
            int Left() const {return position.x - (int)roundf(size.x * .5f);}
            int Right() const {return position.x + (int)roundf(size.x * .5f);}
        };

        Rect rect;
        bool phasable;
        short health = -1;

        Object(const Vector2& position, const Vector2& size, const float rotation = .0f, const bool fromCentre = true);
        bool IsColliding(const Object& object) const;
};