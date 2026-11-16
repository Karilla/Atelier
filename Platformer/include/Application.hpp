#pragma once
#include <Atelier/Window.hpp>
#include <Atelier/OpenGL/ElementBufferObject.hpp>
#include <Atelier/OpenGL/VertexArrayBuffer.hpp>
#include <Atelier/OpenGL/VertexBufferObject.hpp>
#include <Atelier/OpenGL/Shader.hpp>
#include <Atelier/OpenGL/Texture.hpp>
#include <Atelier/Graphics/Renderer.hpp>
#include <string>

class Application
{
private:
    Atelier::Window window;
    Atelier::OpenGL::ElementBufferObject ebo;
    Atelier::OpenGL::VertexArrayBuffer vao;
    Atelier::OpenGL::VertexBufferObject vbo;
    Atelier::OpenGL::Shader shader;
    Atelier::OpenGL::Texture texture1;
    Atelier::Graphics::Renderer renderer;

public:
    Application(const int width, const int height, std::string title);
    ~Application();

    void run();
};