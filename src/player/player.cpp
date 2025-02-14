#include "player.hpp"

Player::Player() 
{
    std::cout << "Player has been init" << std::endl;

    isRunning = false;

    pos = {640, 360};
    speed = 5.0f;
    velocity = {0.0f, 0.0f};

    score = 0;

    // Player Idle
    p_idle.Init(RES "player/crow_idle.png", 4, 2.0f);
    Vector2 player_size = p_idle.getSize();
    p_idle.pos = this->pos;
    p_idle.anim_speed = 0.4f;

    // Player walk
    p_walk.Init(RES "player/crow_walk.png", 4, 2.0f);
    Vector2 p_size = p_walk.getSize();
    p_walk.pos = this->pos;
    p_walk.anim_speed = 0.4f;
}

Player::~Player()
{
    score = 0;
}

void Player::Update(float dt)
{
    movement(dt);

    if (!isRunning)
        p_idle.pos = this->pos;
    else
        p_walk.pos = this->pos;
}

void Player::Draw()
{
    // DrawRectangle(pos.x, pos.y, (float)p_idle.texture.width / 4, (float)p_idle.texture.height, GREEN);
    if (!isRunning)
        p_idle.draw();
    else
        p_walk.draw();
}

Rectangle Player::getRectangle() const
{
    if (!isRunning)
        return Rectangle{pos.x, pos.y, (float)p_idle.texture.width / 4, (float)p_idle.texture.height};
    else
        return Rectangle{pos.x, pos.y, (float)p_walk.texture.width / 4, (float)p_walk.texture.height};
}

void Player::movement(float dt)
{
    
    Vector2 direction = {0.0f, 0.0f};

    // Movement using wasd
    if (IsKeyDown(KEY_W)) direction.y -= 1.0f;
    if (IsKeyDown(KEY_S)) direction.y += 1.0f;
    if (IsKeyDown(KEY_A)) direction.x -= 1.0f;
    if (IsKeyDown(KEY_D)) direction.x += 1.0f;

    // Normalize direction to ensure consistent speed
    if (Vector2Length(direction) != 0) {
        direction = Vector2Normalize(direction);
        isRunning = true;
    }
    else
        isRunning = false;

    // Apply acceleration
    Vector2 acceleration = {direction.x * speed * dt, direction.y * speed * dt};
    velocity = Vector2Add(velocity, acceleration);

    // Apply friction
    float friction = 0.98f;
    velocity = Vector2Scale(velocity, friction);

    // Update position
    pos = Vector2Add(pos, velocity);
}