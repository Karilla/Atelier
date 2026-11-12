#pragma once

namespace Atelier::OpenGL
{
    class VertexBufferObject
    {
    private:
        unsigned int m_uid;
        unsigned int m_size;

    public:
        VertexBufferObject(const float *data, const unsigned int size);
        ~VertexBufferObject();

        VertexBufferObject(const VertexBufferObject &) = delete;
        VertexBufferObject &operator=(const VertexBufferObject &) = delete;

        void bind();
        void unbind();

        unsigned int getSize();
    };

}