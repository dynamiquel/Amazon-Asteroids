#pragma once

#include <math.h>

class Object
{
    public:
        struct Vector2Int
        {
            int x;
            int y;
        };

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
        float rotation;
        const char* textureId;

        Object(const Vector2Int& position, const Vector2Int& size, const bool fromCentre = true);
        bool IsColliding(const Object& object) const;
};