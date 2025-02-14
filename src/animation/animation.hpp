#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include "raylib.h"
#include "raymath.h"

#include <iostream>


class Animation {

    public:
        bool flipped = false;
        float anim_speed = 10;
        void setFrame(int frame);
        bool animated = true;
        Texture2D texture;

        Vector2 pos = {0, 0};
        Vector2 getSize() const;

        void Init(const char* texture, int frames = 1, float scale = 1.0f);
        ~Animation() { UnloadTexture(texture); }
        void draw();


    private:
        int current_frame = 0;
        int frame_counter = 0;
        Rectangle rect;
        int frames = 1;
        float scale = 1.0f;



};


#endif //ANIMATION_HPP