#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"

#include <iostream>

#include "../animation/animation.hpp"

class Player
{
    public:
        Player();
        ~Player();

        void Update(float dt);
        void Draw();

        Rectangle getRectangle() const;

        int score;
    
    private:
        void movement(float dt);

        bool isRunning;

        Vector2 pos;
        Vector2 velocity;
        float speed;

        // Animations
        Animation p_idle;
        Animation p_walk;



};

#endif // PLAYER_HPP