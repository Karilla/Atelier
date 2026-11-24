#include <Atelier/OpenGL/VertexArrayBuffer.hpp>
#include <Atelier/OpenGL/Shader.hpp>
#include <Atelier/OpenGL/Texture.hpp>
#include <Atelier/Core/Log.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/glm.hpp>

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

        void setViewport(int w, int h);

        void draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture);
        void draw(OpenGL::VertexArrayBuffer &vao, OpenGL::Shader &shader, OpenGL::Texture &texture, glm::mat4 model, glm::mat4 view, glm::mat4 projection);
        void clear(float r, float g, float b, float a);
    };
}