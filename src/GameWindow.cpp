#include "GameWindow.h"

GameWindow::GameWindow():
	m_window()
{
	m_background.setTexture(TextureHolder::instance().getTextures(BACKGROUND_P)[0]);
	m_background.setPosition(0, GAP);
	initializeText();
}

void GameWindow::openWindow()
{
	m_window.create(sf::VideoMode(SIZE,SIZE+GAP), "Save The King", sf::Style::Close);
}

bool GameWindow::isOpen()
{
	return m_window.isOpen();
}

void GameWindow::finishLevel(int level)
{
	m_window.clear(sf::Color::Black);

	m_message.setString("Congraltion");
	m_message.setPosition(125,300);
	m_window.draw(m_message);

	m_message.setString("on finish");
	m_message.setPosition(225,450);
	m_window.draw(m_message);

	m_message.setString("level "+ std::to_string(level));
	m_message.setPosition(300, 600);
	m_window.draw(m_message);

	m_window.display();

	_sleep(2500);
	
}

void GameWindow::finishGame()
{
	m_window.clear(sf::Color::Black);

	m_message.setString("Veni");
	m_message.setPosition(340, 300);
	m_window.draw(m_message);

	m_message.setString("Vidi");
	m_message.setPosition(350, 450);
	m_window.draw(m_message);

	m_message.setString("Vici");
	m_message.setPosition(350, 600);
	m_window.draw(m_message);


	m_window.display();

	_sleep(3000);
}

void GameWindow::tutorial()
{
	int page = 0;
	sf::Sprite info, back , next;
	info.setTexture(TextureHolder::instance().getTextures(TUTORIAL_P)[page]);
	back.setTexture(TextureHolder::instance().getTextures(TUTORIAL_P)[BACK]);
	next.setTexture(TextureHolder::instance().getTextures(TUTORIAL_P)[NEXT]);
	back.setPosition(50, 850);
	next.setPosition(700, 850);
	m_window.draw(info);
	m_window.draw(next);
	m_window.draw(back);
	m_window.display();

	sf::Event event;
	while (m_window.waitEvent(event))
	{
		auto location = m_window.mapPixelToCoords({ event.mouseButton.x,event.mouseButton.y });
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonReleased:
			
			if (back.getGlobalBounds().contains(location))
				page--;
			if (next.getGlobalBounds().contains(location))
				page++;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				return;
			if (event.key.code == sf::Keyboard::Right)
				page++;
			if (event.key.code == sf::Keyboard::Left)
				page--;
		}
		if (page < 0 || page > 4)
			return;
		info.setTexture(TextureHolder::instance().getTextures(TUTORIAL_P)[page]);
		m_window.draw(info);
		m_window.draw(next);
		m_window.draw(back);
		m_window.display();
	}
}

void GameWindow::gameOver()
{
	sf::Sprite endScreen;
	endScreen.setTexture (TextureHolder::instance().getTextures(END_SCREEN_P)[0]);
	m_window.draw(endScreen);
	m_window.display();

	_sleep(2500);
	m_window.close();
}

void GameWindow::changeSound(bool state)
{
	m_menu.changeSound(state);
}

void GameWindow::close()
{
	m_window.close();
}

void GameWindow::print(const Board& board,int level, int currPlayer)
{
	m_window.clear();
	m_window.draw(m_background);

	printText(board , level ,currPlayer);
	printStatic(board);
	printTeleport(board);
	printPlayers(board);
	printDwarfs(board);
	

	m_window.display();
}

void GameWindow::printStatic(const Board& board)
{
	sf::Sprite temp;

	for (int i = 0; i <board.staticSize(); i++)
	{
		temp = board.getStatic(i);
		m_window.draw(temp);
	}
}

void GameWindow::printTeleport(const Board& board)
{
	sf::Sprite temp;

	for (int i = 0; i < board.teleportSize(); i++)
	{
		temp = board.getTeleport(i);
		m_window.draw(temp);
	}
}

void GameWindow::printPlayers(const Board& board)
{
	sf::Sprite temp;
	// change to num of players
	for (int i = 0; i < 4; i++)
	{
		temp = board.getPlayers(i);
		m_window.draw(temp);
	}
}

void GameWindow::printDwarfs(const Board& board)
{
	sf::Sprite temp;

	for (int i = 0; i < board.dwarfSize(); i++)
	{
		temp = board.getDwarfs(i);
		m_window.draw(temp);
	}
}

bool GameWindow::pollEvent(sf::Event& event)
{
	return m_window.pollEvent(event);
}

int GameWindow::runMenu()
{
	return m_menu.run(m_window);
}
void GameWindow::initializeText()
{
	if (!m_font.loadFromFile("CASTELAR.TTF"))
		exit(EXIT_FAILURE);

	m_time.setFont(m_font);
	m_level.setFont(m_font);
	m_currPlayer.setFont(m_font);
	m_message.setFont(m_font);

	m_time.setCharacterSize(FONT_SIZE);
	m_level.setCharacterSize(FONT_SIZE);
	m_currPlayer.setCharacterSize(FONT_SIZE);
	m_message.setCharacterSize(MESSAGE_SIZE);

	m_level.setPosition(0, 20);
	m_time.setPosition(TIME_POS, 20);
	m_currPlayer.setPosition(PLAYER_POS, 20);

	m_time.setFillColor(sf::Color::White);
	m_level.setFillColor(sf::Color::White);
	m_currPlayer.setFillColor(sf::Color::White);
	m_message.setFillColor(sf::Color::White);
}

void GameWindow::printText(const Board& board, int level, int currPlayer)
{
	std::string time = " ";

	int TimeRemaining = board.TimeRemaining();
	int minutes = TimeRemaining / 60;
	int second = TimeRemaining % 60;
	if (minutes > 0)
	{
		time += std::to_string(minutes);
		time += ":";
	}
	if (second < 10)
		time += "0";
	
	time += std::to_string(second);

	std::string player;

	switch (currPlayer)
	{
	case KING_P:
		player = "King";
		break;
	case MAGE_P:
		player = "Mage";
		break;
	case WARRIOR_P:
		player = "Warrior";
		break;
	case THIEF_P:
		player = "Theif";
		break;

	}

	m_level.setString("level:" + std::to_string (level));
	m_time.setString("time:" + time);
	m_currPlayer.setString("Active player:" + player);

	m_window.draw(m_level);
	m_window.draw(m_time);
	m_window.draw(m_currPlayer);

}