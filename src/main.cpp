#include "window/window.hpp"
#include "player/player.hpp"
#include "coin/coin.hpp"


#include <vector>
#include <iostream>
#include <string>

int main()
{
    Window window(1280, 720, "Hello");
    Player player;

    std::vector<Coin> coins;

    Texture2D coinTexture = LoadTexture(RES "coin/coin.png");
    if (coinTexture.id == 0) {
        std::cerr << "Error loading coin texture" << std::endl;
        return -1;
    }

    // Generate Coins
    for (int i = 0; i < 10; i++)
    {
        Coin coin;
        coin.texture = coinTexture;
        coin.width = coin.texture.width;
        coin.height = coin.texture.height;
        coin.x = GetRandomValue(0, 1280 / 2);
        coin.y = GetRandomValue(0, 720 / 2);
        coins.push_back(coin);
    }

    while (!window.ShouldClose())
    {
        // Update
        float dt = GetFrameTime();

        // Player update func
        player.Update(dt);
        
        // Remove coins if collected
        coins.erase(std::remove_if(coins.begin(), coins.end(),
            [&player](const Coin& coin) {
                return CheckCollisionRecs(player.getRectangle(), coin.getRectangle());
            }),
            coins.end());
             

        // Draw
        window.BeginDraw();

        for (const Coin& coin : coins) {
            DrawTextureEx(coin.texture, {coin.x, coin.y}, 0.0f, 2.0f, WHITE);
        }

        player.Draw();

        DrawFPS(10, 10);
        DrawText(("Score: " + std::to_string(player.score)).c_str(), 10, 30, 20, WHITE);

        window.EndDraw();
    }

    UnloadTexture(coinTexture);
    return 0;
}