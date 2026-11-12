#include <Atelier/OpenGL/VertexLayout.hpp>

namespace Atelier::OpenGL
{

    void VertexLayout::addFloat(unsigned int value)
    {
        m_attributes.push_back({value});
        m_stride += value * sizeof(float);
    }

    const std::vector<unsigned int> VertexLayout::getAttributes()
    {
        return m_attributes;
    }

    unsigned int VertexLayout::getStride()
    {
        return m_stride;
    }
}