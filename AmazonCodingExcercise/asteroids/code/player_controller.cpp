#include "player_controller.h"
#include "asteroids.h"

#include <SDL.h>

PlayerController::PlayerController()
{
    ship = new Ship({640, 850}, 0);
}

int PlayerController::GetThrustPerc()
{
    return (int)roundf((1 - (thrustTimeTimer * 1 / thrustTime)) * 100);
}

float PlayerController::GetThrustRecharge()
{
    return thrustRechargeDelay - thrustRechargeDelayTimer;
}

void PlayerController::OnUpdate(const float deltaTime)
{
    fireDelayTimer += deltaTime;

    UserInput(deltaTime);
    UpdateThrust(deltaTime);
    UpdateHoverEffect(deltaTime);
}

void PlayerController::UserInput(const float deltaTime)
{
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    const Uint32 mouseState = SDL_GetMouseState(NULL, NULL);

    if (keyState[SDL_SCANCODE_LSHIFT] && (thrustTimeTimer + deltaTime) <= thrustTime)
    {
        moveVelocity = thrustMoveVelocity;
        thrustTimeTimer += deltaTime;
    }
    else
        moveVelocity = normalMoveVelocity;    
    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_KP_4] || keyState[SDL_SCANCODE_A])
    {
        if (ship->rect.position.x > 10)
            ship->rect.position.x -= moveVelocity;
    }
    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_KP_6] || keyState[SDL_SCANCODE_D])
    {
        if (ship->rect.position.x < 1270)
            ship->rect.position.x += moveVelocity;
    }
    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_KP_8] || keyState[SDL_SCANCODE_W])
    {
        if (ship->rect.position.y > 10)
            ship->rect.position.y -= moveVelocity;
    }
    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_KP_5] || keyState[SDL_SCANCODE_S])
    {
        if (ship->rect.position.y < 1014)
            ship->rect.position.y += normalMoveVelocity;
    }
    if (keyState[SDL_SCANCODE_KP_7] || keyState[SDL_SCANCODE_Q])
    {
        // Rotate left.
    }
    if (keyState[SDL_SCANCODE_KP_9] || keyState[SDL_SCANCODE_E])
    {
        // Rotate right.
    }
    if (keyState[SDL_SCANCODE_SPACE] || keyState[SDL_SCANCODE_KP_0] || mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        Fire();
    }
}

void PlayerController::Fire()
{
    if (fireDelayTimer >= fireDelay)
    {
        ship->Fire();
        fireDelayTimer = 0.0f;
    }
}

// Checks if the player's thrust needs replenishing, if so, it is gradually replenished.
void PlayerController::UpdateThrust(const float deltaTime)
{
    if (thrustTimeTimer > .0f && (thrustRechargeDelayTimer += deltaTime) >= thrustRechargeDelay)
    {
        if (thrustTimeTimer < prevThrustTime)
        {
            prevThrustTime = thrustTimeTimer;
            thrustTimeTimer -= deltaTime * .25f;

            if (thrustTimeTimer <= .0f)
            {
                thrustRechargeDelayTimer = .0f;
                prevThrustTime = 1000.f;
            }
        }
        else
        {
            thrustRechargeDelayTimer = .0f;
            prevThrustTime = 1000.f;
        }
    }
}

// Sequentially moves the player's ship slightly in a square pattern.
void PlayerController::UpdateHoverEffect(const float deltaTime)
{
    if ((hoverDirectionDelayTimer += deltaTime) >= hoverDirectionDelay)
    {
        switch (hoverDirection)
        {
            case 0:
                ship->rect.position.x -= 2;
                break;
            case 1:
                ship->rect.position.y -= 2;
                break;
            case 2:
                ship->rect.position.x += 2;
                break;
            case 3:
                ship->rect.position.y += 2;
                break;
        }

        if ((hoverDirection++) > 3)
            hoverDirection = 0;

        hoverDirectionDelayTimer = .0f;
    }
}