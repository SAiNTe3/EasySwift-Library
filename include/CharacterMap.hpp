#pragma once
#include <iostream>
#include "Sprite.hpp"
#include <unordered_map>

class CharacterMap
{
	std::unordered_map<char, Sprite*> m_CharacterMap;
	Texture* m_MapTexture;
public:
	CharacterMap() = default;
	CharacterMap(const std::string& filePath);
	~CharacterMap();
	void loadFromFile(const std::string& filePath);
	void bindCharacter(char ch, glm::vec2 pos, glm::vec2 size);
	void unbindCharacter(char ch);
	Sprite& getCharacterSprite(char ch);
	void clearMap();
};