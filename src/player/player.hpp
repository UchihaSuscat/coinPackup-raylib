#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "raylib.h"
#include "raymath.h"

#include <iostream>

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

        Texture2D texture;

        Vector2 pos;
        Vector2 velocity;
        float speed;



};

#endif // PLAYER_HPP