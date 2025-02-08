#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "raylib.h"

class Window{

    public:
        Window(int width, int height, const char* title);
        ~Window();

        bool ShouldClose() const;
        void BeginDraw() const;
        void EndDraw() const;

        int GetScreenWidth() const;
        int GetScreenHeight() const;

    private:
        int widht, height;
        const char* title;

};

#endif // WINDOW_HPP