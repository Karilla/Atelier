#include <Atelier/OpenGL/Texture.hpp>
#include <utility>
#include <glad/glad.h>
#include <stdexcept>

namespace Atelier::OpenGL
{
    // TODO : maybe we donnt need to store the texture data, can optimize a little bit later after we are sure its working
    Texture::Texture(Graphics::TextureData &&texture) : m_textureData{std::move(texture)}
    {
        if (!m_textureData.getData())
        {
            throw std::runtime_error("Texture has not been loaded");
        }
        glGenTextures(1, &m_uid);
        glBindTexture(GL_TEXTURE_2D, m_uid);

        // TODO : Change this on separate fonction or add a way to configure this
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        GLint format;
        switch (m_textureData.getNrChannels())
        {
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            throw std::runtime_error("Texture format not supported");
        }

        glTexImage2D(GL_TEXTURE_2D, 0, format, m_textureData.getWidth(), m_textureData.getHeight(), 0, format, GL_UNSIGNED_BYTE, m_textureData.getData());
        glGenerateMipmap(GL_TEXTURE_2D);
        // TODO: see if i free the image data now
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &m_uid);
    }

    void Texture::bind(unsigned int slot)
    {
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, m_uid);
    }

    void Texture::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }

}