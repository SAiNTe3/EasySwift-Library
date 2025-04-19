#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include<CircleShape.hpp>

CircleShape::CircleShape() :Shape()
{
	m_pointCount = 30;
	m_radius = 8;
	updateGeometry();
	setupOpenGLBuffers();
}

CircleShape::CircleShape(size_t count, float radius) :Shape()
{
	m_pointCount = count;
	m_radius = radius;
	updateGeometry();
	setupOpenGLBuffers();
}

void CircleShape::setRadius(float radius)
{
	m_radius = radius;
	updateGeometry();
	setupOpenGLBuffers();
}

void CircleShape::setPointCount(size_t count)
{
	m_pointCount = count;
	updateGeometry();
	setupOpenGLBuffers();
}

float CircleShape::getRadius() const
{
	return m_radius;
}

size_t CircleShape::getPointCount() const
{
	return m_pointCount;
}

void CircleShape::updateGeometry()
{
	m_vertices.clear();
	m_vertices.reserve(m_pointCount + 1);
	m_vertices.push_back(glm::vec2(0.f, 0.f));
	const float angleStep = 2.0f * glm::pi<float>() / m_pointCount;
	for (size_t i = 0; i <=m_pointCount; ++i) {
		float angle = i * angleStep;
		m_vertices.push_back(glm::vec2(
			m_radius * cos(angle),
			m_radius * sin(angle)
		));
	}
}

void CircleShape::setupOpenGLBuffers()
{
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(glm::vec2), m_vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &m_borderVBO);
	glGenVertexArrays(1, &m_borderVAO);
	glBindVertexArray(m_borderVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_borderVBO);
	glBufferData(GL_ARRAY_BUFFER, (m_vertices.size() - 1) * sizeof(glm::vec2), &m_vertices[1], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(glm::vec2), (void*)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

}

glm::vec2 CircleShape::getPoint(size_t index)
{
	return m_vertices[index];
}

void CircleShape::draw(float right, float top)
{
	shapeShader->load();

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));
	model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(scale, 1.0f));

	glm::mat4 projection = glm::ortho(0.0f, right, 0.0f, top, -1.0f, 1.0f);

	shapeShader->setMat4("projection", projection);
	shapeShader->setMat4("model", model);
	shapeShader->setVec4("color", color);

	if (isShapeFilled) {
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, m_vertices.size());
	}
	else {
		glBindVertexArray(m_borderVAO);
		glLineWidth(borderWidth);
		glDrawArrays(GL_LINE_LOOP, 0, m_pointCount);
	}

	glBindVertexArray(0);
	shapeShader->unload();
}
