#pragma once

#include "object.h"

class Ship : public Object
{
    public:
        Ship(const Vector2Int& position, const float rotation);
        void Move(const Vector2Int& moveBy);
        Object& Fire();

    protected:
        static Object CreateShot(const Vector2Int& position);
};