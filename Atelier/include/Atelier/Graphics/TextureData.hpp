#pragma once

namespace Atelier::Graphics
{
    class TextureData
    {
    private:
        unsigned char *m_imageData;
        int m_width;
        int m_height;
        int m_nrChannels;

    public:
        TextureData(const char *path);
        ~TextureData();

        TextureData(const TextureData &) = delete;
        TextureData &operator=(const TextureData &) = delete;

        TextureData(TextureData &&other) noexcept;
        TextureData &operator=(TextureData &&other) noexcept;

        unsigned char *getData();

        int getWidth();

        int getHeight();

        int getNrChannels();
    };
}