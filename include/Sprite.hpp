#pragma once
#include<iostream>
#include"Texture.hpp"
#include"Shader.hpp"


class Sprite {
	Texture* m_Texture = nullptr;
	Shader* m_Shader = nullptr;
	glm::vec2 m_Position = glm::vec2(0.f, 0.f);
	glm::vec2 m_Size = glm::vec2(0.f, 0.f);
	float m_Rotation = 0;
	glm::vec4 m_Color = glm::vec4(1.f, 1.f, 1.f, 1.f);
	uint m_VAO = 0;
	uint m_VBO = 0;
	uint m_EBO = 0;
	glm::vec2 m_Scale = glm::vec2(1.f, 1.f);
	glm::vec2 m_Origin = glm::vec2(0.f, 0.f);
public:
	Sprite();
	Sprite(Texture* texture);
	void setup();
	void setPosition(int x, int y);
	void setPosition(glm::vec2 pos);
	void setTexture(Texture* texture);
	Texture* getTexture() const;
	glm::vec2 getPosition() const;
	void setRotation(float angle);
	float getRotation() const;
	void setColor(float r, float g, float b, float a);
	void setColor(int r, int g, int b, int a);
	glm::vec4 getColor() const;
	void setScale(float ax, float ay);
	glm::vec2 getScale() const;
	void setOrigin(float x, float y);
	void setOrigin(glm::vec2 pos);
	glm::vec2 getOrigin() const;
	glm::vec2 getGlobalSize();
	void move(float x, float y);
private:
	void draw(float right, float top);
	friend class Window;
};