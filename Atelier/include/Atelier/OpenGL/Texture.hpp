#pragma once

#include <Atelier/Graphics/TextureData.hpp>

namespace Atelier::OpenGL
{
    class Texture
    {
    private:
        unsigned int m_uid;
        Graphics::TextureData m_textureData;

    public:
        Texture(Graphics::TextureData &&data);
        ~Texture();

        void bind(unsigned int slot);
        void unbind();
    };
}
