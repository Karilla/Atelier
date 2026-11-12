#pragma once

#include <vector>

namespace Atelier::OpenGL
{
    class VertexLayout
    {
    private:
        std::vector<unsigned int> m_attributes;

        unsigned int m_stride = 0;

    public:
        void addFloat(unsigned int value);

        const std::vector<unsigned int> getAttributes();

        unsigned int getStride();
    };
}