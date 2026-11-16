#include <Application.hpp>
#include <Atelier/OpenGL/VertexLayout.hpp>
#include <Atelier/Graphics/TextureData.hpp>
#include <glad/glad.h>
constexpr float vertices[] = {
    // positions          // colors           // texture coords
    0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
    0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f   // top left
};

constexpr unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};
Application::Application(const int width, const int height, std::string title) : window(width, height, title),
                                                                                 ebo(indices, sizeof(indices)),
                                                                                 vbo(vertices, sizeof(vertices)),
                                                                                 shader("assets/shaders/basic.vert", "assets/shaders/basic.frag"),
                                                                                 texture1(Atelier::Graphics::TextureData("assets/texture/container.jpg"))

{
    Atelier::OpenGL::VertexLayout layout;
    layout.addFloat(3);
    layout.addFloat(3);
    layout.addFloat(2);

    vao.addVertexLayout(layout, vbo);
    vao.setIndexBuffer(ebo);
    vao.unbind();
}

Application::~Application()
{
}

void Application::run()
{
    while (!window.shouldClose())
    {
        renderer.clear(0.2f, 0.3f, 0.3f, 1.0f);

        renderer.draw(vao, shader, texture1);

        window.pollEvents();
        window.swapBuffers();
    }
}