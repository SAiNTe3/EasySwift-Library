#pragma once
#include <iostream>
#include "CharacterMap.hpp"
#include <vector>
class Text
{
	CharacterMap* m_CharMap = nullptr;
	std::string m_Content;
	std::vector<Sprite*> m_SpriteVector;
	glm::vec2 m_Pos={ 0,0 };
	glm::vec2 m_Scale={ 1,1 };
	float m_Angle = 0;
	float m_Space = 0;
	void update();
	friend class Window;
public:
	Text() = default;
	Text(const std::string& text);
	~Text();
	void setText(const std::string& text);
	const std::string getText() const;
	void bindMap(CharacterMap& charMap);
	void unbindMap();
	std::string operator+(const std::string& rv);
	std::string operator+(int rv);
	std::string operator+=(const std::string& rv);
	std::string operator+=(int rv);
	const char operator[](size_t index);
	void setPosition(glm::vec2 pos);
	void setScale(glm::vec2 scale);
	void setRotation(float angle);
	glm::vec2 getPosition() const;
	glm::vec2 getScale() const;
	float getRotation() const;
	void setCharacterSpace(float space);
};