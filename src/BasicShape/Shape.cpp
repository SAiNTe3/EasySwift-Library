#include<Shape.hpp>

Shape::Shape()
{
	const std::string vertexShader = R"(
		#version 460 core
		layout(location = 0) in vec2 aPos;
		uniform mat4 projection;
		uniform mat4 model;
		void main() {
			gl_Position = projection * model * vec4(aPos, 0.0, 1.0);
		}
	)";

	const std::string fragmentShader = R"(
		#version 460 core
		out vec4 fragColor;
		uniform vec4 color;
		void main() {
			fragColor = color;
		}
	)";
	shapeShader = new Shader(vertexShader, fragmentShader);
}

Shape::~Shape()
{
	if (this->shapeShader)
	{
		delete shapeShader;
	}
}

void Shape::setColor(glm::vec4 color)
{
	this->color = color;
}

void Shape::setFill(bool isFilled)
{
	this->isShapeFilled = isFilled;
}

void Shape::setPosition(glm::vec2 pos)
{
	this->position = pos;
}

void Shape::setScale(glm::vec2 scale)
{
	this->scale = scale;
}

void Shape::setRotation(float angle)
{
	this->rotation = angle;
}

glm::vec4 Shape::getColor() const
{
	return this->color;
}

bool Shape::isFilled() const
{
	return this->isShapeFilled;
}

glm::vec2 Shape::getPosition() const
{
	return this->position;
}

glm::vec2 Shape::getScale() const
{
	return this->scale;
}

float Shape::getRotation() const
{
	return this->rotation;
}

void Shape::move(glm::vec2 delta)
{
	this->position += delta;
}
