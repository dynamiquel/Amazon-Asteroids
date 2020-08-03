#pragma once

#include "object.h"

#include <stdint.h>

class Ship : public Object
{
    public:
        Ship(const Vector2& position, const float rotation);
        void OnUpdate(const float deltaTime);
        void Move(const Vector2& moveBy);
        Object Fire();

    protected:
        static Object CreateShot(const Vector2& position, const float rotation);
        void UpdateHoverEffect(const float deltaTime);

        // Hover effect.
        uint8_t hoverDirection = 0; // Left, Top, Right, Bottom.
        const float hoverDirectionDelay = .25f;
        float hoverDirectionDelayTimer = .0f;
};