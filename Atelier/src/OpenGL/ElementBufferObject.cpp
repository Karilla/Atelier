#include <Atelier/OpenGL/ElementBufferObject.hpp>
#include <glad/glad.h>

namespace Atelier::OpenGL
{
    ElementBufferObject::ElementBufferObject(const unsigned int *data, const unsigned int size) : m_count{size}
    {
        glGenBuffers(1, &m_uid);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uid);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count, data, GL_STATIC_DRAW);
    }

    ElementBufferObject::~ElementBufferObject()
    {
        glDeleteBuffers(1, &m_uid);
    }

    void ElementBufferObject::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_uid);
    }

    void ElementBufferObject::unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    unsigned int ElementBufferObject::getCount()
    {
        return m_count / sizeof(unsigned int);
    }
}