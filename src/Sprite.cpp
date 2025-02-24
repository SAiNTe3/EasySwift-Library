#include "../include/Sprite.hpp"

Sprite::Sprite()
{
	setup();
}
Sprite::Sprite(Texture *texture)
{
	setup();
	m_Texture = texture;
	m_Size = {texture->getWidth(), texture->getHeight()};
}
void Sprite::setup()
{
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	unsigned int indices[] = {0, 1, 2, 1, 2, 3};
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f};
	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	const std::string vstring = {
		"#version 460 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"layout(location = 2) in vec2 aUV;\n"
		"out vec2 uv;\n"
		"uniform mat4 transform;\n"
		"uniform mat4 projection;\n"
		"void main() {\n"
		"gl_Position = projection * transform * vec4(aPos, 1.0);\n"
		"uv = aUV;\n"
		"}\0"};
	const std::string fstring = {
		"#version 460 core\n"
		"in vec2 uv;\n"
		"out vec4 fragColor;\n"
		"uniform sampler2D sampler;\n"
		"uniform vec4 spriteColor;\n"
		"void main() {\n"
		"fragColor = texture(sampler,uv)*spriteColor;\n"
		"}\0"};
	m_Shader = new Shader(vstring, fstring);
	m_Shader->setInt("sampler", 0);
}
void Sprite::setPosition(int x, int y)
{
	m_Position = {x, y};
}
void Sprite::setPosition(glm::vec2 pos)
{
	m_Position = pos;
}
void Sprite::setTexture(Texture *texture)
{
	m_Texture = texture;
}
Texture *Sprite::getTexture() const
{
	return m_Texture;
}
glm::vec2 Sprite::getPosition() const
{
	return m_Position;
}
void Sprite::setRotation(float angle)
{
	m_Rotation = {angle};
}
float Sprite::getRotation() const
{
	return m_Rotation;
}
void Sprite::setColor(float r, float g, float b, float a)
{
	m_Color = {r, g, b, a};
}
void Sprite::setColor(int r, int g, int b, int a)
{
	m_Color.r = static_cast<float>(r) / 255;
	m_Color.g = static_cast<float>(g) / 255;
	m_Color.b = static_cast<float>(b) / 255;
	m_Color.a = static_cast<float>(a) / 255;
}
glm::vec4 Sprite::getColor() const
{
	return m_Color;
}
void Sprite::setScale(float ax, float ay)
{
	m_Scale = {ax, ay};
}
glm::vec2 Sprite::getScale() const
{
	return m_Scale;
}
void Sprite::setOrigin(float x, float y)
{
	m_Origin = {x, y};
}
void Sprite::setOrigin(glm::vec2 pos)
{
	m_Origin = pos;
}
glm::vec2 Sprite::getOrigin() const
{
	return m_Origin;
}
glm::vec2 Sprite::getGlobalSize()
{
	return m_Size * m_Scale;
}
void Sprite::move(float x, float y)
{
	m_Position += glm::vec2{x, y};
}
void Sprite::draw(float right, float top)
{
	m_Shader->load();
	m_Texture->bind();
	glm::mat4 projection = glm::ortho(0.f, right, 0.f, top, -1.f, 1.f);
	m_Shader->setMat4("projection", projection);
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, glm::vec3(m_Position, 0.0f));
	transform = glm::translate(transform, glm::vec3(m_Origin, 0.0f));
	transform = glm::rotate(transform, glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	transform = glm::translate(transform, glm::vec3(-m_Origin, 0.0f));
	glm::vec2 scaledSize = m_Size * m_Scale;
	transform = glm::scale(transform, glm::vec3(scaledSize.x, scaledSize.y, 1.0f));
	m_Shader->setMat4("transform", transform);
	m_Shader->setVec4("spriteColor", m_Color);
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	m_Shader->unload();
}