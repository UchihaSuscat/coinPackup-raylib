#include "window.hpp"

Window::Window(int widht, int height, const char* title) 
    :widht(widht), height(height), title(title) {
        InitWindow(widht, height, title);
    }

Window::~Window()
{
    CloseWindow();
}

bool Window::ShouldClose() const
{
    return WindowShouldClose();
}

void Window::BeginDraw() const
{
    BeginDrawing();

    ClearBackground(BLACK);
}

void Window::EndDraw() const
{
    EndDrawing();
}

int Window::GetScreenWidth() const
{
    return GetScreenWidth();
}

int Window::GetScreenHeight() const
{
    return GetScreenHeight();
}
