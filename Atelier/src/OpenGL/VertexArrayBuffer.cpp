#include <Atelier/OpenGL/VertexArrayBuffer.hpp>
#include <glad/glad.h>

namespace Atelier::OpenGL
{

    VertexArrayBuffer::VertexArrayBuffer()
    {
        glGenVertexArrays(1, &m_uid);
    }

    VertexArrayBuffer::~VertexArrayBuffer()
    {
        glDeleteVertexArrays(1, &m_uid);
    }

    void VertexArrayBuffer::addVertexLayout(VertexLayout layouts, VertexBufferObject &vbo)
    {
        bind();
        vbo.bind();
        size_t offset = 0;
        for (auto attribute : layouts.getAttributes())
        {
            glEnableVertexAttribArray(m_layout_count);
            glVertexAttribPointer(m_layout_count, attribute, GL_FLOAT, GL_FALSE, layouts.getStride(), reinterpret_cast<const void *>(offset));
            offset += attribute * sizeof(float);
            m_layout_count++;
        }
    }

    void VertexArrayBuffer::setIndexBuffer(ElementBufferObject &ebo)
    {
        bind();
        ebo.bind();
    }

    void VertexArrayBuffer::bind()
    {
        glBindVertexArray(m_uid);
    }

    void VertexArrayBuffer::unbind()
    {
        glBindVertexArray(0);
    }

}