#pragma once

#include <string>

struct GLFWwindow;

namespace Atelier
{
    class Window
    {
    private:
        GLFWwindow *m_window = nullptr;

    public:
        Window(int width, int height, std::string title);
        ~Window();

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        void setTitle(std::string title);

        bool shouldClose();
        void pollEvents();
        void swapBuffers();
        void requestClose();

        GLFWwindow *getWindowHandle();
    };
}
