#pragma once
#include "Board.h"

#include "MovingObject.h"
#include "Player.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Dwarf.h"

#include "StaticObject.h"
#include "Wall.h"
#include "Gate.h"
#include "Throne.h"
#include "Orc.h"
#include "Fire.h"
#include "Key.h"
#include "TeleportCell.h"
#include "Gift.h"

Board::Board()
{
    srand((int)time(NULL));
}

void Board::InitializeLevel(int level)
{
    readLevel(level);
    createObjects();
}

int Board::getRows()const
{
    return m_rows;
}

int Board::getCols() const
{
    return m_cols;
}

int Board::getTime() const
{
    return m_time;
}

int Board::TimeRemaining() const
{
    if (m_time > 0)
    {
        return m_time - m_timePassed;
    }
    return m_timePassed;
}

int Board::staticSize() const
{
    return m_static.size();
}

int Board::teleportSize() const
{
    return m_teleport.size();
}

int Board::dwarfSize() const
{
    return m_dwarfs.size();
}

void Board::moveThePlayer(float deltaTime, int currPlayer)
{
    m_players[currPlayer][0]->move(deltaTime);
}

void Board::moveDwarfs(float deltaTime)
{
    for (int i = 0; i < m_dwarfs.size(); i++)
        m_dwarfs[i]->move(deltaTime);
}

void Board::clearObjects()
{
    m_win = false;
    m_timePassed = 0;
    m_static.clear();
    m_teleport.clear();
    m_players.clear();
    m_players.resize(4);
    m_dwarfs.clear();
}

void Board::choosePlayer(int oldPlayer)
{
    m_players[oldPlayer][0]->choose(false);
    m_players[(oldPlayer + 1) % 4][0]->choose(true);
}

void Board::handleCollisions(int currPlayer)
{
    // active player with static object
    for (auto& unmovable : m_static)
        if (m_players[currPlayer][0]->checkCollision(unmovable->getGlobalBounds()))
            unmovable->handleCollision(*m_players[currPlayer][0]);

    bool teleportCollision = false;
    // active player with teleport
    for (auto& teleport : m_teleport)
        if (m_players[currPlayer][0]->checkCollision(teleport->getGlobalBounds()))
        {
            teleport->handleCollision(*m_players[currPlayer][0]);
            teleportCollision = true;
        }

    if (!teleportCollision)
        m_players[currPlayer][0]->notOnTeleport();

    for (int i = 0; i < 4; i++)
    {
        // active player with other player
        if (m_players[currPlayer][0]->checkCollision(m_players[i][0]->getGlobalBounds()))
            m_players[currPlayer][0]->handleCollision(*m_players[i][0]);
        
        // dwarfs with all players
        for (auto& dwarfs : m_dwarfs)
            if (m_players[i][0]->checkCollision(dwarfs->getGlobalBounds()))
                m_players[i][0]->handleCollision(*dwarfs);
    }
    
    // dwarfs with static objects
    for (auto& dwarfs : m_dwarfs)
        for (auto& unmovable : m_static)
            if (dwarfs->checkCollision(unmovable->getGlobalBounds()))
                unmovable->handleCollision(*dwarfs);

    updateCollision();
}

void Board::setLastPos(int currPlayer)
{
    m_players[currPlayer][0]->setLastPos();
    for (auto& dwarfs : m_dwarfs)
        dwarfs->setLastPos();
}

void Board::updateCollision()
{
    for (int k = 0; k < m_static.size(); k++)
    {
        auto& unmovable = m_static[k];
        if (!unmovable->isExsit())
        {
            auto orc = dynamic_cast <Orc*>(unmovable.get());
            auto gift = dynamic_cast <GiftAddDwarf*>(unmovable.get());

            unmovable.release();
            m_static.erase(m_static.begin() + k);
            
            if (orc)
            {
                int i, j;
                j = (orc->getGlobalBounds().left) /m_size;
                i = ((orc->getGlobalBounds().top) - GAP) /m_size;
                std::unique_ptr<StaticObject> key = std::make_unique<Key>(m_scale, i, j, m_size);
                m_static.push_back(std::move(key));
            }

            if (gift)
            {
                int i, j;
                j = (gift->getGlobalBounds().left) / m_size;
                i = ((gift->getGlobalBounds().top) - GAP) / m_size;
                std::unique_ptr<MovingObject> dwarf = std::make_unique<Dwarf>(m_scale, i, j, m_size);
                m_dwarfs.push_back(std::move(dwarf));
            }
        }
    }
    auto king = static_cast<King*> (m_players[0][0].get());

    if (king->win())
    {
        m_win = true;
    }

    if (king->moreTime())
    {
        m_time += ((rand() % 6) + 5);
    }

    if (king->lessTime())
    {
        m_time -= ((rand() % 5)+1);
    }

    if (king->removeDwarf())
    {
        m_dwarfs.clear();
    }
}

bool Board::isWin()
{
    return m_win;
}

bool Board::handleTime(float deltaTime)
{
    m_timePassed += deltaTime;
   if(m_time > 0)
       if (m_time <= m_timePassed)
           return false;
   return true;
}

sf::Sprite Board::getStatic(int i) const
{
    return m_static[i]->draw();
}

sf::Sprite Board::getTeleport(int i) const
{
    return m_teleport[i]->draw();
}

sf::Sprite Board::getPlayers(int i) const
{
    return m_players[i][0]->draw();
}

sf::Sprite Board::getDwarfs(int i) const
{
    return m_dwarfs[i]->draw();
}

void Board::readLevel(int level)
{
    m_board.clear();

    auto lvl = std::to_string(level) + ".txt";

    std::ifstream board(lvl);
    std::string line = std::string();

    board >> m_rows >> m_cols >> m_time;

    if (board.peek() == '\n')
        board.get();

    for (int i = 0; i < m_rows; i++)
    {
        std::getline(board, line);
        m_board.push_back(line);

        if (board.peek() == '\n')
            board.get();

    }
}

void Board::createObjects()
{
    sf::Sprite sprite_temp;

    clearObjects();
 
    calculateScale();   
    m_size = SIZE / (std::max(m_rows, m_cols));

    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            if (m_board[i][j] != EMPTY )
                setObject(m_board[i][j], m_scale ,i,j, m_size);
    
    if (m_teleport.size() > 0)
        sortTeleport();
}

void Board::setObject(char element, sf::Vector2f scale , int i,int j,int size)
{

    std::unique_ptr<MovingObject> movable = createMoveableObject(element,i,j);
    if (movable)
    {
        if (element == DWARF)
        {
            m_dwarfs.push_back(std::move(movable));
            return;
        }
        switch (element)
        {
        case KING:
            m_players[KING_P].push_back(std::move(movable));
            break;
        case MAGE:
            m_players[MAGE_P].push_back(std::move(movable));
            break;
        case THIEF:
            m_players[THIEF_P].push_back(std::move(movable));
            break;
        case WARRIOR:
            m_players[WARRIOR_P].push_back(std::move(movable));
            break;
        }
        return;
    }

    std::unique_ptr<StaticObject> unmovable = createStaticObject(element, i, j);
    if (unmovable)
    {
        if (isdigit(element))
            m_teleport.push_back(std::move(unmovable));
        else
            m_static.push_back(std::move(unmovable));
        return;
    }

    std::cerr << "Unrecognized char in the file: " << element << std::endl;
    exit(EXIT_FAILURE);
}

void Board::calculateScale()
{
    float max = (float)std::max(m_cols, m_rows);
    float scaleVal = (float)SIZE / (float)(ICON_SIZE * max);
    m_scale = sf::Vector2f(scaleVal, scaleVal);
}

void Board::sortTeleport()
{
    // sort
    for (int i = 0; i < m_teleport.size()-1; i++)
        for (int j = 0; j < m_teleport.size() - i - 1; j++)
        {
            auto first = static_cast<TeleportCell*> (m_teleport[j].get());
            auto second = static_cast<TeleportCell*> (m_teleport[j + 1].get());
            if (first->getId() > second->getId())
                std::swap(m_teleport[j], m_teleport[j + 1]);
        }
            
    // link
    for (int i = 0 ; i < m_teleport.size(); i += 2)
    {
        auto first = static_cast<TeleportCell*> (m_teleport[i].get());
        auto second = static_cast<TeleportCell*> (m_teleport[i + 1].get());
        first->setOtherPos(m_teleport[i+1]->getGlobalBounds());
        second->setOtherPos(m_teleport[i]->getGlobalBounds());
    }
}

std::unique_ptr<StaticObject> Board::createStaticObject(char element, int i, int j)
{
    switch (element)
    {
    case WALL:
        return std::make_unique<Wall>(m_scale, i, j, m_size);
        break;

    case GATE:
        return std::make_unique<Gate>(m_scale, i, j, m_size);
        break;

    case FIRE:
        return std::make_unique<Fire>(m_scale, i, j, m_size);
        break;

    case ORC:
        return std::make_unique<Orc>(m_scale, i, j, m_size);
        break;
    
    case THRONE:
        return std::make_unique<Throne>(m_scale, i, j, m_size);
        break;
    
    case GIFT:
        return chooseGift(i,j);
        break;

    case KEY:
        return std::make_unique<Key>(m_scale, i, j, m_size);
        break;
    }
    if (isdigit(element))
        return std::make_unique<TeleportCell>(m_scale, i, j, m_size, element);

    return nullptr;
}

std::unique_ptr<StaticObject> Board::chooseGift(int i, int j)
{
    int type = rand() % 2;
    if (m_time >-1)
        type = rand() % 4;
 
    switch (type)
    {
    case 0:
        return std::make_unique<GiftAddDwarf>(m_scale, i, j, m_size);
        break;
    case 1:
        return std::make_unique<GiftRemoveDwarf>(m_scale, i, j, m_size);
        break;
    case 2:
        return std::make_unique<GiftMoreTime>(m_scale, i, j, m_size);
        break;
    case 3:
        return std::make_unique<GiftLessTime>(m_scale, i, j, m_size);
        break;
    }
    return nullptr;
}

std::unique_ptr<MovingObject> Board::createMoveableObject(char element,int i,int j)
{
    sf::Vector2f playerScale = sf::Vector2f(m_scale.x * PLAYERS_DECREASE , m_scale.y * PLAYERS_DECREASE);
    switch (element)
    {
    case KING:
        return std::make_unique<King>(playerScale,i ,j ,m_size);
        break;
    case MAGE:
        return std::make_unique<Mage>(playerScale, i, j, m_size);
        break;
    case THIEF:
        return std::make_unique<Thief>(playerScale, i, j, m_size);
        break;
    case WARRIOR:
        return std::make_unique<Warrior>(playerScale, i, j, m_size);
        break;
    case DWARF:
        return std::make_unique<Dwarf>(m_scale, i, j, m_size);
        break;
    }
    return nullptr;
}