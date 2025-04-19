#pragma once
#include "Sprite.hpp"
#include "Camera.hpp"
class Sprite3D : public Sprite
{
protected:
	glm::vec3 m_Rotation3D = glm::vec3(1.f, 1.f, 1.f);
	glm::quat m_Rotation3DQuat = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	Camera* m_Camera = nullptr;
	glm::vec3 m_Origin3D = glm::vec3(0.f, 0.f, 0.f);
public:
	Sprite3D();
	Sprite3D(Texture* texture);
	void bindCamera(Camera* camera);
	void setRotation(glm::vec3 angles);
	void setPosition(glm::vec3 pos);
	void setOrigin(glm::vec3 pos);
	glm::vec3 getRotation()const;
	glm::vec3 getPosition()const;
	glm::vec3 getOrigin()const;
	void setPosition(glm::vec2 pos) = delete;
	void setRotation(float) = delete;
	void setOrigin(glm::vec2) = delete;
protected:
	virtual void draw(float right, float top)override;
	friend class Window;
};