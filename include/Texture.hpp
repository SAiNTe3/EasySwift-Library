#pragma once
#include<iostream>
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "../include/stbImage/stb_image.h"
typedef unsigned int uint;
typedef unsigned char uchar;
class Texture {
	uint m_Texture = 0;
	int m_Width = 0;
	int m_Height = 0;
	int m_Channel = 0;
	struct Size {
		int w;
		int h;
		Size(int x, int y) :w(x), h(y) {};
	};
public:
	Texture(const char* path);
	Size getSize();
private:
	void bind();
	int getWidth() const;
	int getHeight() const;
	int getChannel()const;
	friend class Sprite;
};