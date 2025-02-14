#include "animation.hpp"

void Animation::setFrame(int frame)
{
    current_frame = frame;
}

Vector2 Animation::getSize() const
{
    return Vector2{(texture.width / frames) * scale, texture.height * scale};
}

void Animation::Init(const char* file_name, int frames, float scale)
{
    texture = LoadTexture(file_name);
    this->frames = frames;
    rect = { 0.0f, 0.0f, (float)texture.width / frames, (float)texture.height };
    this->scale = scale;
}

void Animation::draw()
{
    frame_counter++;

    if (frame_counter >= (60 / anim_speed))
    {
        frame_counter = 0;
        if (animated) current_frame++;

        if (current_frame > frames - 1)
            current_frame = 0;

        rect.x = (float)current_frame * (float)texture.width / frames;
    }

    // Create a copy of rect to modify for flipping
    Rectangle source_rect = rect;

    if (flipped)
    {
        source_rect.width = -source_rect.width;  // Flip horizontally
        source_rect.x += rect.width;            // Shift x to keep correct frame
    }

    // Destination rectangle for drawing
    Rectangle dest = { pos.x, pos.y, rect.width * scale, rect.height * scale };
    Vector2 origin = { 0.0f, 0.0f };

    DrawTexturePro(texture, source_rect, dest, origin, 0.0f, WHITE);
}


