#pragma once
#include<Shape.hpp>
#include<vector>
class CircleShape :public Shape
{
	float m_radius;
	size_t m_pointCount;
	std::vector<glm::vec2> m_vertices;
	GLuint m_borderVAO, m_borderVBO;
public:
	CircleShape();
	explicit CircleShape(size_t count, float radius);
	void setRadius(float radius);
	void setPointCount(size_t count);

	float getRadius()const;
	size_t getPointCount()const;
	void updateGeometry();
	void setupOpenGLBuffers();
	virtual glm::vec2 getPoint(size_t index);
	virtual void draw(float right, float top)override;
};