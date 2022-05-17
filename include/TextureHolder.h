#pragma once

#include <SFML/Graphics.hpp>
#include "Macros.h"

// This is a singleton class.
class TextureHolder
{
public:
	static TextureHolder& instance();
	const std::vector<sf::Texture>& getTextures(int element) const;

private:
	TextureHolder();
	TextureHolder(const TextureHolder&) = default;
	TextureHolder& operator=(const TextureHolder&) = default;

	void uploadFiles();

	void uploadKing(sf::Texture temp);
	void uploadMage(sf::Texture temp);
	void uploadWarrior(sf::Texture temp);
	void uploadTheif(sf::Texture temp);
	void uploadFire(sf::Texture temp);
	void uploadWall(sf::Texture temp);
	void uploadThrone(sf::Texture temp);
	void uploadDwarf(sf::Texture temp);
	void uploadGift(sf::Texture temp);
	void uploadGate(sf::Texture temp);
	void uploadKey(sf::Texture temp);
	void uploadOrc(sf::Texture temp);
	void uploadTeleport(sf::Texture temp);
	void uploadBackground(sf::Texture temp);
	void uploadMenu(sf::Texture temp);
	void uploadEndScreen(sf::Texture temp);
	void uploadTutorial(sf::Texture temp);

	std::vector<std::vector<sf::Texture>> m_texture;
	sf::Texture tryking;
};