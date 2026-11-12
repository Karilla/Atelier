#include <Atelier/Window.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

namespace Atelier
{

    Window::Window(int width, int height, std::string title)
    {
        std::cout << "lol2" << std::endl;
        if (!glfwInit())
        {
            std::cout << "lol init" << std::endl;
            throw std::runtime_error("Cannot initalise GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_window)
        {

            glfwTerminate();
            throw std::runtime_error("Cannot create openg Window");
        }

        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "lol" << std::endl;
            glfwDestroyWindow(m_window);
            glfwTerminate();
            throw std::runtime_error("Cannot load glad");
        }

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *, int w, int h)
                                       { glViewport(0, 0, w, h); });
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::setTitle(std::string title)
    {
        glfwSetWindowTitle(m_window, title.c_str());
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::requestClose()
    {
        glfwSetWindowShouldClose(m_window, true);
    }

    GLFWwindow *Window::getWindowHandle()
    {
        return m_window;
    }
}