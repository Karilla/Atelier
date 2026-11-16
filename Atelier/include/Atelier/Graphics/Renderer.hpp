#include <Atelier/OpenGL/VertexArrayBuffer.hpp>
#include <Atelier/OpenGL/Shader.hpp>
#include <Atelier/OpenGL/Texture.hpp>
#include <Atelier/Core/Log.hpp>
namespace Atelier::Graphics
{
    class Renderer
    {
    private:
        Core::Logger logger{"Renderer"};

    public:
        Renderer();
        ~Renderer();

        Renderer(const Renderer &) = delete;
        Renderer &operator=(const Renderer &) = delete;

        void draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture);
        void clear(float r, float g, float b, float a);
    };
}