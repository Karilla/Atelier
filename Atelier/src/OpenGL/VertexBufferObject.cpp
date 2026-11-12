#include <Atelier/OpenGL/VertexBufferObject.hpp>
#include <glad/glad.h>

namespace Atelier::OpenGL
{

    VertexBufferObject::VertexBufferObject(const float *data, const unsigned int size) : m_size{size}
    {
        glGenBuffers(1, &m_uid);
        glBindBuffer(GL_ARRAY_BUFFER, m_uid);
        glBufferData(GL_ARRAY_BUFFER, m_size, data, GL_STATIC_DRAW);
    }

    VertexBufferObject::~VertexBufferObject()
    {
        glDeleteBuffers(1, &m_uid);
    }

    void VertexBufferObject::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_uid);
    }

    void VertexBufferObject::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    unsigned int VertexBufferObject::getSize()
    {
        return m_size;
    }
}