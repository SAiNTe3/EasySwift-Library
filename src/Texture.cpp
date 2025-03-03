#define STB_IMAGE_IMPLEMENTATION
#include "../include/Texture.hpp"


Texture::Texture(const char *path)
{
	glGenTextures(1, &m_Texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_set_flip_vertically_on_load(true);
	uchar *data = stbi_load(path, &m_Width, &m_Height, &m_Channel, 0);
	if (data)
	{
		switch (m_Channel)
		{
		case 3:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			break;
		case 4:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			break;
		default:
			std::cout << "Unsupported format!" << std::endl;
			stbi_image_free(data);
			return;
		}
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}
Texture::Size Texture::getSize()
{
	return Size(m_Width, m_Height);
}
void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_Texture);
}
int Texture::getWidth() const
{
	return m_Width;
}
int Texture::getHeight() const
{
	return m_Height;
}
int Texture::getChannel() const
{
	return m_Channel;
}