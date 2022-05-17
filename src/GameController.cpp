#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

#include "GameController.h"


GameController::GameController() : m_window () 
{
   
}

void GameController::run()
{
    m_window.openWindow();

    while (m_window.isOpen())
    {
        if (m_sound)
            AudioHolder::instance().playSound(AUDIO_MENU);
        int action = m_window.runMenu();
        switch (action)
        {
        case NEW_GAME:
            runGame(1);
            break;
        case CONTINUE:
            runGame(m_level);
            break;
        case TUTORIAL:
            tutorial();
            break;
        case SOUND:
            changeSound();
            break;
        case QUIT:
            close();
            break;
        }
    }
}


int GameController::runLevel(int level)
{
    int timeRemained = 1;

    sf::Time deltaTime;
    sf::Clock clock;
    sf::Clock clockMovements;


    m_board.InitializeLevel(level);

    if (m_board.getTime() == -1)
        m_timeLimit = false;

    clock.restart();

    m_window.print(m_board,level ,m_currPlayer);

    while (m_window.isOpen())
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if ((event.type == sf::Event::Closed))
            {
                m_window.close();
                return CLOSE;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                return CLOSE;
            }
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R))
            {
                return RESTART;
            }

            if ((event.type == sf::Event::KeyPressed) && 
                ((event.key.code == sf::Keyboard::P)|| (event.key.code == sf::Keyboard::Space)))
            {
                m_board.choosePlayer(m_currPlayer);
                m_currPlayer = (m_currPlayer + 1) % 4;
            }
        }

        float deltaTime = clock.restart().asSeconds();

        m_board.moveThePlayer(deltaTime , m_currPlayer);

        m_board.moveDwarfs(deltaTime);

        m_board.handleCollisions(m_currPlayer);

        if (m_board.isWin())
            return WIN;

        if (!m_board.handleTime(deltaTime))
            return RESTART;

        m_board.setLastPos(m_currPlayer);

        m_window.print(m_board,level ,m_currPlayer);
        
    }

    return -1;
}

int GameController::readNumOfLevel() const
{
    auto lvl = "NumOfLevel.txt";

    std::ifstream level (lvl);
    std::string line = std::string();
   
    std::getline(level, line);
    return std::stoi(line);
}

void GameController::finishLevel(int level)
{
    m_level++;
    if (m_sound)
    {
        AudioHolder::instance().pauseSound(AUDIO_GAME);
        AudioHolder::instance().playSound(AUDIO_FINISH_LEVEL);
    }
    m_window.finishLevel(level);
    if (m_sound)
        AudioHolder::instance().playSound(AUDIO_GAME);
    m_board.clearObjects();
}

void GameController::runGame(int level)
{
    if (m_sound)
    {
        AudioHolder::instance().stopSound(AUDIO_MENU);
        AudioHolder::instance().playSound(AUDIO_GAME);
    }
    int numOfLevel = readNumOfLevel();
    //m_level = level;
    for (; level <= numOfLevel;  level++)
    {
        restartPlayer();
        switch (runLevel(level))
        {
            case CLOSE:
                if (m_sound)
                    AudioHolder::instance().pauseSound(AUDIO_GAME);
                return;
                break;
            case RESTART:
                level--;
                break;
            case WIN:
                finishLevel(level);
                break;
        }
    }
    finishGame();
    if (m_sound)
        AudioHolder::instance().pauseSound(AUDIO_GAME);
}

void GameController::tutorial()
{
    m_window.tutorial();
}

void GameController::restartPlayer()
{
    m_currPlayer = 0;
}

void GameController::changeSound()
{
    m_sound = !m_sound;
    if (!m_sound)
        AudioHolder::instance().stopSound(AUDIO_MENU);
    m_window.changeSound(m_sound);
}

void GameController::close()
{
    gameOver();
}

void GameController::finishGame()
{
    m_level = 1;
    if (m_sound)
    {
        AudioHolder::instance().stopSound(AUDIO_GAME);
        AudioHolder::instance().playSound(AUDIO_FINISH_GAME);
    }
    m_window.finishGame();
}

void GameController::gameOver()
{
    m_window.gameOver();
}


