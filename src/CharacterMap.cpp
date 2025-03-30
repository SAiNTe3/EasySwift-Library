#include "../include/CharacterMap.hpp"

void CharacterMap::loadFromFile(const std::string& filePath)
{
	m_MapTexture = new Texture(filePath.c_str());
}

CharacterMap::CharacterMap(const std::string& filePath)
{
	this->loadFromFile(filePath);
}

CharacterMap::~CharacterMap()
{
	delete m_MapTexture;
	for (auto& pair : m_CharacterMap) 
	{
		delete pair.second;
	}
	this->clearMap();
}

void CharacterMap::bindCharacter(char ch, glm::vec2 pos, glm::vec2 size)
{
	Sprite* charSprite = new Sprite(m_MapTexture);
	charSprite->setTextureRect(pos, size);
	m_CharacterMap[ch] = charSprite;
}

void CharacterMap::unbindCharacter(char ch)
{
	m_CharacterMap[ch] = nullptr;
}

Sprite& CharacterMap::getCharacterSprite(char ch)
{
	return *m_CharacterMap[ch];
}

void CharacterMap::clearMap()
{
	m_CharacterMap.clear();
}
