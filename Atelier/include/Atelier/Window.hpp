#pragma once

#include <string>
#include <functional>

struct GLFWwindow;

namespace Atelier
{
    class Window
    {
    private:
        GLFWwindow *m_window = nullptr;

        std::function<void(int, int)> m_onresize;
        std::function<void(int, bool)> m_onkey;
        std::function<void(double, double)> m_onmouse;
        std::function<void(double, double)> m_onscroll;
        std::function<void(int, bool)> m_onmousebutton;
        int m_width;
        int m_height;

    public:
        Window(int width, int height, std::string title);
        ~Window();

        Window(const Window &) = delete;
        Window &operator=(const Window &) = delete;

        void setTitle(std::string title);

        void setResizeCallback(std::function<void(int, int)> cb);

        void setKeyCallback(std::function<void(int, bool)> cb);

        void setMouseCallback(std::function<void(double, double)> cb);

        void setScrollCallback(std::function<void(double, double)> cb);

        void setMouseButtonCallback(std::function<void(double, double)> cb);

        int getWidth();
        int getHeight();

        bool shouldClose();
        void pollEvents();
        void swapBuffers();
        void requestClose();

        GLFWwindow *getWindowHandle();
    };
}
