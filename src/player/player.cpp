#include "player.hpp"

Player::Player()
{
    std::cout << "Player has been init" << std::endl;

    texture = LoadTexture(RES "player/player.png");
    if (texture.id == 0) {
        std::cerr << "Error loading player texture" << std::endl;
    } else {
        std::cout << "Player texture loaded" << std::endl;
    }

    pos = {640, 360};
    speed = 10.0f;
    velocity = {0.0f, 0.0f};

    score = 0;

    }

Player::~Player()
{
    UnloadTexture(texture);
    score = 0;
}

void Player::Update(float dt)
{
    movement(dt);
}

void Player::Draw()
{
    DrawTextureEx(texture, pos, 0.0f, 2.0f, WHITE);
}

Rectangle Player::getRectangle() const
{
    return Rectangle{pos.x, pos.y, (float)texture.width, (float)texture.height};
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
    }

    // Apply acceleration
    Vector2 acceleration = {direction.x * speed * dt, direction.y * speed * dt};
    velocity = Vector2Add(velocity, acceleration);

    // Apply friction
    float friction = 0.98f;
    velocity = Vector2Scale(velocity, friction);

    // Update position
    pos = Vector2Add(pos, velocity);
}
