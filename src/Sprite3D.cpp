#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include "Sprite3D.hpp"

Sprite3D::Sprite3D():Sprite()
{
}

Sprite3D::Sprite3D(Texture* texture):Sprite(texture)
{
}

void Sprite3D::bindCamera(Camera* camera)
{
	m_Camera = camera;
}

void Sprite3D::setRotation(glm::vec3 angles)
{
	m_Rotation3D = angles;
	m_Rotation3DQuat = glm::quat(glm::radians(angles));
}

void Sprite3D::setPosition(glm::vec3 pos)
{
	m_Position = pos;
}

void Sprite3D::setOrigin(glm::vec3 pos)
{
	m_Origin3D = pos;
}

glm::vec3 Sprite3D::getRotation() const
{
	return m_Rotation3D;
}

glm::vec3 Sprite3D::getPosition()const
{
	return m_Position;
}
glm::vec3 Sprite3D::getOrigin() const
{
	return m_Origin3D;
}
void Sprite3D::draw(float right, float top)
{
	m_Shader->load();
	m_Texture->bind();
	glm::mat4 projection;
	glm::mat4 view(1.f);
	if (m_Camera)
	{
		projection = glm::perspective(glm::radians(m_Camera->m_FieldOfView), right / top, m_Camera->m_Near, m_Camera->m_Far);
		view = glm::lookAt(m_Camera->m_Pos, m_Camera->m_Target, m_Camera->m_UpVector);
	}
	else
	{
		projection = glm::ortho(0.0f, right, 0.0f, top, -1.0f, 1.0f);
	}
	m_Shader->setMat4("projection", projection);
	m_Shader->setMat4("view", view);
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::translate(transform, m_Position);
	transform = glm::translate(transform, m_Origin3D);

	glm::mat4 rotationMatrix = glm::mat4_cast(m_Rotation3DQuat);
	transform = transform * rotationMatrix;
	transform = glm::translate(transform, -m_Origin3D);
	glm::vec2 scaledSize = m_Size * m_Scale * m_RectScale * m_RepeatScale;
	transform = glm::scale(transform, glm::vec3(scaledSize.x, scaledSize.y, 1.0f));

	m_Shader->setMat4("transform", transform);
	m_Shader->setVec4("spriteColor", m_Color);
	m_Shader->setVec2("uvScale", m_RepeatScale);


	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	m_Shader->unload();
}