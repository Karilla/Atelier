#pragma once

#include <vector>
#include <Atelier/OpenGL/VertexLayout.hpp>
#include <Atelier/OpenGL/ElementBufferObject.hpp>
#include <Atelier/OpenGL/VertexBufferObject.hpp>

namespace Atelier::OpenGL
{
    class VertexArrayBuffer
    {
    private:
        unsigned int m_uid = 0;
        unsigned int m_layout_count = 0;

    public:
        VertexArrayBuffer();
        ~VertexArrayBuffer();

        VertexArrayBuffer(const VertexArrayBuffer &) = delete;
        VertexArrayBuffer &operator=(const VertexArrayBuffer &) = delete;

        void addVertexLayout(VertexLayout layout, VertexBufferObject &vbo);
        void setIndexBuffer(ElementBufferObject &ebo);

        void bind();
        void unbind();
    };

}
