#include "TextureHolder.h"

TextureHolder::TextureHolder()
{
	m_texture.push_back(std::vector<sf::Texture>());
	uploadFiles();
}

void TextureHolder::uploadFiles()
{
	sf::Texture temp;

	uploadKing(temp);
	uploadMage(temp);
	uploadWarrior(temp);
	uploadTheif(temp);
	uploadDwarf(temp);
	uploadThrone(temp);
	uploadKey(temp);
	uploadFire(temp);
	uploadWall(temp);
	uploadOrc(temp);
	uploadGate(temp);
	uploadTeleport(temp);
	uploadGift(temp);
	uploadBackground(temp);
	uploadMenu(temp);
	uploadEndScreen(temp);
	uploadTutorial(temp);

}

void TextureHolder::uploadKing(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("king.png");
	m_texture[KING_P].push_back(temp);
	temp.loadFromFile("king2.png");
	m_texture[KING_P].push_back(temp);
}

void TextureHolder::uploadMage(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("mage.png");
	m_texture[MAGE_P].push_back(temp);
	temp.loadFromFile("mage2.png");
	m_texture[MAGE_P].push_back(temp);
}

void TextureHolder::uploadWarrior(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Warrior.png");
	m_texture[WARRIOR_P].push_back(temp);
	temp.loadFromFile("Warrior2.png");
	m_texture[WARRIOR_P].push_back(temp);
}

void TextureHolder::uploadTheif(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Theif.png");
	m_texture[THIEF_P].push_back(temp);
	temp.loadFromFile("Theif2.png");
	m_texture[THIEF_P].push_back(temp);
	temp.loadFromFile("Theif3.png");
	m_texture[THIEF_P].push_back(temp);
	temp.loadFromFile("Theif4.png");
	m_texture[THIEF_P].push_back(temp);
}

void TextureHolder::uploadDwarf(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("dwarf.png");
	m_texture[DWARF_P].push_back(temp);
}

void TextureHolder::uploadThrone(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("throne.png");
	m_texture[THRONE_P].push_back(temp);
}

void TextureHolder::uploadKey(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Key.png");
	m_texture[KEY_P].push_back(temp);
}

void TextureHolder::uploadFire(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Fire.png");
	m_texture[FIRE_P].push_back(temp);
}

void TextureHolder::uploadWall(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("wall.png");
	m_texture[WALL_P].push_back(temp);
}

void TextureHolder::uploadOrc(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Orc.png");
	m_texture[ORC_P].push_back(temp);
}

void TextureHolder::uploadGate(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("gate_close.png");
	m_texture[GATE_P].push_back(temp);
	temp.loadFromFile("gate_open.png");
	m_texture[GATE_P].push_back(temp);
}

void TextureHolder::uploadTeleport(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("Teleport.png");
	m_texture[TELEPORT_P].push_back(temp);
}

void TextureHolder::uploadGift(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("gift.png");
	m_texture[GIFT_P].push_back(temp);
}

void TextureHolder::uploadBackground(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("gamebg.png");
	m_texture[BACKGROUND_P].push_back(temp);
}

void TextureHolder::uploadMenu(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());

	temp.loadFromFile("menubg.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("new_game.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("countinue.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("tutorial.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("exit.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("save_the_king.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("sound_on.png");
	m_texture[MENU_P].push_back(temp);
	temp.loadFromFile("sound_off.png");
	m_texture[MENU_P].push_back(temp);
}

void TextureHolder::uploadEndScreen(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("endScreen.png");
	m_texture[END_SCREEN_P].push_back(temp);
}

void TextureHolder::uploadTutorial(sf::Texture temp)
{
	m_texture.push_back(std::vector<sf::Texture>());
	temp.loadFromFile("tutorial1.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("tutorial2.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("tutorial3.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("tutorial4.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("tutorial5.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("back.png");
	m_texture[TUTORIAL_P].push_back(temp);
	temp.loadFromFile("next.png");
	m_texture[TUTORIAL_P].push_back(temp);
}

const std::vector<sf::Texture>& TextureHolder::getTextures(int element) const
{
 	std::vector<sf::Texture> temp;

	switch (element)
	{
	case KING_P:
		return m_texture[KING_P];
		break;

	case MAGE_P:
		return m_texture[MAGE_P];
		break;

	case WARRIOR_P:
		return m_texture[WARRIOR_P];
		break;

	case THIEF_P:
		return m_texture[THIEF_P];
		break;

	case DWARF_P:
		return m_texture[DWARF_P];
		break;

	case THRONE_P:
		return m_texture[THRONE_P];
		break;

	case KEY_P:
		return m_texture[KEY_P];
		break;

	case FIRE_P:
		return m_texture[FIRE_P];
		break;

	case WALL_P:
		return m_texture[WALL_P];
		break;

	case ORC_P:
		return m_texture[ORC_P];
		break;

	case GATE_P:
		return m_texture[GATE_P];
		break;

	case TELEPORT_P:
		return m_texture[TELEPORT_P];
		break;

	case GIFT_P:
		return m_texture[GIFT_P];
		break;

	case BACKGROUND_P:
		return m_texture[BACKGROUND_P];
		break;
	
	case MENU_P:
		return m_texture[MENU_P];
		break;
	
	case END_SCREEN_P:
		return m_texture[END_SCREEN_P];
		break;

	case TUTORIAL_P:
		return m_texture[TUTORIAL_P];
		break;

	}

	return temp;
}

//-----------------------------------------------------------------------------
TextureHolder& TextureHolder::instance()
{
	static TextureHolder instance;
	return instance;
}
