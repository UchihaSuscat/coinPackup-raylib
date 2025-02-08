#ifndef COIN_HPP
#define COIN_HPP

#include "raylib.h"
#include "raymath.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

class Coin {
    public:
        float x, y, width, height;
        Texture2D texture;

        Rectangle getRectangle() const {
            return Rectangle{x, y, width, height};
        }
    
    private:
        


};

#endif // COIN_HPP