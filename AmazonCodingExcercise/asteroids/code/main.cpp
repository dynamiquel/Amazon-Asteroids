// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#include "drawer.h"
#include "asteroids.h"

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

SDL_Window* window;
SDL_Renderer* renderer;
Drawer* drawer;
Asteroids* asteroids;
float lastFrame;
bool running;

bool OnStart()
{
    // Initialise a random seed for rand().
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    const int width = 1280;
    const int height = 1024;
    window = SDL_CreateWindow(
        "Asteroids",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    drawer = Drawer::Create(window, renderer);
    asteroids = Asteroids::Create(drawer);

    asteroids->OnStart();

    lastFrame = (float) SDL_GetTicks() * 0.001f;
    running = true;

    return true;
}

void OnUpdate()
{
    SDL_Event currentEvent;

    // Checks if the user pressed the Close button.
    if (SDL_PollEvent(&currentEvent) && currentEvent.type == SDL_QUIT)
    {
        running = false;
        return;
    }
    
    float currentFrame = (float) SDL_GetTicks() * 0.001f;
    float elapsedTime = currentFrame - lastFrame;

    SDL_RenderClear(renderer);

    asteroids->OnUpdate(elapsedTime);
    asteroids->Draw();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    
    lastFrame = currentFrame;

    SDL_RenderPresent(renderer);
    // 200 fps cap.
    SDL_Delay(1000 / 200);
}

void OnEnd()
{

}

int OnExit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete asteroids;
    delete drawer;

    return 0;
}

int main(int argc, char *argv[])
{
    if (OnStart())
        while (running)
            OnUpdate();
    
    return OnExit();
}