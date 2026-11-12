#include <Atelier/Graphics/TextureData.hpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <utility>

namespace Atelier::Graphics
{
    TextureData::TextureData(const char *path)
    {
        stbi_set_flip_vertically_on_load(true);
        m_imageData = stbi_load(path, &m_width, &m_height, &m_nrChannels, 0);
    }

    TextureData::~TextureData()
    {
        stbi_image_free(m_imageData);
    }

    TextureData::TextureData(TextureData &&other) noexcept : m_imageData{std::exchange(other.m_imageData, nullptr)},
                                                             m_height{std::exchange(other.m_height, 0)},
                                                             m_nrChannels{std::exchange(other.m_nrChannels, 0)},
                                                             m_width{std::exchange(other.m_width, 0)}
    {
    }

    TextureData &TextureData::operator=(TextureData &&other) noexcept
    {
        if (this != &other)
        {
            stbi_image_free(m_imageData);
            m_imageData = std::exchange(other.m_imageData, nullptr);
            m_height = std::exchange(other.m_height, 0);
            m_width = std::exchange(other.m_width, 0);
            m_nrChannels = std::exchange(other.m_nrChannels, 0);
        }

        return *this;
    }

    unsigned char *TextureData::getData()
    {
        return m_imageData;
    }

    int TextureData::getHeight()
    {
        return m_height;
    }

    int TextureData::getWidth()
    {
        return m_width;
    }

    int TextureData::getNrChannels()
    {
        return m_nrChannels;
    }

}
