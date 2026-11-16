#include <Atelier/Graphics/Renderer.hpp>
#include <glad/glad.h>

namespace Atelier::Graphics
{
    Renderer::Renderer()
    {
    }

    Renderer::~Renderer()
    {
    }

    void Renderer::draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture)
    {
        texture.bind(0);
        shader.use();
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndiceCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}