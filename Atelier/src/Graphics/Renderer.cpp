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

    void Renderer::draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture, glm::mat4 model, glm::mat4 view, glm::mat4 projection)
    {
        texture.bind(0);
        shader.use();
        shader.setMat4("model", model);
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndiceCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture)
    {
        texture.bind(0);
        shader.use();
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndiceCount(), GL_UNSIGNED_INT, 0);
    }

    void Renderer::setViewport(int w, int h)
    {
        glViewport(0, 0, w, h);
    }

    void Renderer::clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}