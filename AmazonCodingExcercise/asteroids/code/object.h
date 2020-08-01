#pragma once

#include <math.h>
#include "vector2int.h"

class Object
{
    public:
        struct Rect
        {
            Vector2Int position;
            // Size is solely for collider.
            Vector2Int size;
            int Top() const
            {return position.y - (int)roundf(size.y * .5f);}
            int Bottom() const {return position.y + (int)roundf(size.y * .5f);}
            int Left() const {return position.x - (int)roundf(size.x * .5f);}
            int Right() const {return position.x + (int)roundf(size.x * .5f);}
        };

        Rect rect;
        float rotation = .0f;
        bool phasable;
        short health = -1;

        Object(const Vector2Int& position, const Vector2Int& size, const bool fromCentre = true);
        bool IsColliding(const Object& object) const;
};