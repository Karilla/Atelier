#pragma once

namespace Atelier::OpenGL
{
    class ElementBufferObject
    {
    private:
        unsigned int m_uid;
        unsigned int m_count;

    public:
        ElementBufferObject(const unsigned int *data, const unsigned int size);
        ~ElementBufferObject();

        ElementBufferObject(const ElementBufferObject &) = delete;
        ElementBufferObject *operator=(const ElementBufferObject &) = delete;

        void bind();
        void unbind();

        unsigned int getCount();
    };
}