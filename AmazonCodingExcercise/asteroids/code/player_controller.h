#pragma once

#include "ship.h"

#include <stdint.h>

class PlayerController
{
    public:
        Ship* ship;

        PlayerController();

        void OnUpdate(const float deltaTime);
        int GetThrustPerc();
        float GetThrustRecharge();
    
    protected:
        // Firing.
        const float fireDelay = .5f;
        float fireDelayTimer = .0f;
        const float fastFireDelay = .1f;
        float fastFireDelayTimer = .0f;
        const float fastFireChargeDelay = 5.0f;
        float fastFireChargeDelayTimer = .0f;

        // Movement.
        const uint8_t normalMoveVelocity = 1;
        const uint8_t thrustMoveVelocity = 3;
        uint8_t moveVelocity = normalMoveVelocity;
        const float thrustTime = 1.f;
        float thrustTimeTimer = .0f;
        const float thrustRechargeDelay = 4.f;
        float thrustRechargeDelayTimer = .0f;
        float prevThrustTime = 1000.f;

        void UserInput(const float deltaTime);
        void Fire();
        void UpdateThrust(const float deltaTime);
};