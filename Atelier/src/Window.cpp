#include <Atelier/Window.hpp>
#include <Atelier/OpenGL/Debug.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <functional>
#include <utility>

namespace Atelier
{

    Window::Window(int width, int height, std::string title)
    {
        m_height = height;
        m_width = width;
        if (!glfwInit())
        {
            throw std::runtime_error("Cannot initalise GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifndef NDEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

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
        glfwSetWindowUserPointer(m_window, this);
#ifndef NDEBUG
        OpenGL::enableDebugOutput();
#endif
        glEnable(GL_DEPTH_TEST);
        glfwSetKeyCallback(m_window, [](GLFWwindow *glfWin, int key, int scancode, int action, int mods)
                           { 
            auto *self = static_cast<Window *>(glfwGetWindowUserPointer(glfWin));
            if(self && self->m_onkey){
            self->m_onkey(key, action != GLFW_RELEASE);
                            } });

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *glfWin, int w, int h)
                                       { 
            auto *self = static_cast<Window *>(glfwGetWindowUserPointer(glfWin)); 
            self->m_height = h;
            self->m_width = w;
            if(self && self->m_onresize){
                self->m_onresize(w,h);
                                    } });

        glfwSetScrollCallback(m_window, [](GLFWwindow *glfWin, double xOffset, double yOffset)
                              {
            auto *self = static_cast<Window *>(glfwGetWindowUserPointer(glfWin));
            if(self && self->m_onscroll){
                self->m_onscroll(xOffset, yOffset);
            } });

        glfwSetCursorPosCallback(m_window, [](GLFWwindow *glfWindow, double xPos, double yPos)
                                 {
            auto *self = static_cast<Window *>(glfwGetWindowUserPointer(glfWindow));
            if(self && self->m_onmouse){
                self->m_onmouse(xPos, yPos);
            } });

        glfwSetMouseButtonCallback(m_window, [](GLFWwindow *glfWindow, int button, int action, int mods)
                                   {
            auto *self = static_cast<Window *>(glfwGetWindowUserPointer(glfWindow));
            if(self && self->m_onmousebutton){
                self->m_onmousebutton(button, action != GLFW_RELEASE);
            } });
    }

    void Window::setKeyCallback(std::function<void(int, bool)> cb)
    {
        m_onkey = std::move(cb);
    }

    void Window::setMouseCallback(std::function<void(double, double)> cb)
    {
        m_onmouse = std::move(cb);
    }

    void Window::setScrollCallback(std::function<void(double, double)> cb)
    {
        m_onscroll = std::move(cb);
    }

    void Window::setMouseButtonCallback(std::function<void(double, double)> cb)
    {
        m_onmousebutton = std::move(cb);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    int Window::getHeight()
    {
        return m_height;
    }

    int Window::getWidth()
    {
        return m_width;
    }

    void Window::setResizeCallback(std::function<void(int, int)> cb)
    {
        m_onresize = std::move(cb);
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