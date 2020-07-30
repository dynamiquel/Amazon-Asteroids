// Amazon Game Coding exercise
// Disclaimer: This code is intentionally written to a substandard quality and
// is not representative of Amazon coding standards or Amazon best practices.

#pragma once

class Drawer;

class Asteroids
{
public:
    static Asteroids* Create(Drawer* drawer);
    
    void Update(float deltaTime);
    void Draw();

private:
    Drawer* drawer;
};