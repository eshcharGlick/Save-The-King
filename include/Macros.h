#pragma once

// for read/write on board

const auto THIEF = 't';
const auto MAGE = 'm';
const auto KING = 'k';
const auto WARRIOR = 'w';
const auto DWARF = '^';
const auto THRONE = '@';
const auto KEY = 'f';
const auto FIRE = '*';
const auto WALL = '=';
const auto ORC = '!';
const auto GATE = '#';
const auto TELEPORT = 'x';
const auto GIFT = '$';
const auto EMPTY = '.';
const auto BACKGROUND = 'b';
const auto MENU = 'u';
const auto END_SCREEN = 'e';

// for texture place
const auto KING_P = 0;
const auto MAGE_P = 1;
const auto WARRIOR_P = 2;
const auto THIEF_P = 3;
const auto DWARF_P = 4;
const auto THRONE_P = 5;
const auto KEY_P = 6;
const auto FIRE_P = 7;
const auto WALL_P = 8;
const auto ORC_P = 9;
const auto GATE_P = 10;
const auto TELEPORT_P = 11;
const auto GIFT_P = 12;
const auto BACKGROUND_P = 13;
const auto MENU_P = 14;
const auto END_SCREEN_P = 15;
const auto TUTORIAL_P = 16;

// for menu buttons
const auto MENU_BACKGROUND = 0;
const auto NEW_GAME = 1;
const auto CONTINUE = 2;
const auto TUTORIAL = 3;
const auto EXIT = 4;
const auto LOGO = 5;
const auto SOUND = 6;
const auto SOUND_ON = 6;
const auto SOUND_OFF = 7;
const auto ELEMENTS = 7;
const auto BACK = 5;
const auto NEXT = 6;
const auto START = 0;
const auto QUIT = -1;
const auto NOTHING = 404;

// for general settings
const float SPEED = 200.0;
const float ICON_SIZE = 512.0;
const int SIZE = 900;
const float GAP = 80;
const int MENUWIDTH = 700;
const int MENUHEIGHT = 400;
const float PLAYERS_DECREASE = 0.85;

//for audio
const auto AUDIO = 4;
const auto AUDIO_GAME = 0;
const auto AUDIO_MENU = 1;
const auto AUDIO_FINISH_GAME = 2;
const auto AUDIO_FINISH_LEVEL = 3;

//for font
const auto FONT_SIZE = 35;
const auto MESSAGE_SIZE = 80;
const auto TIME_POS = 165;
const auto PLAYER_POS = 375;

// for game state
const auto CLOSE = 0;
const auto RESTART = 1;
const auto WIN = 2;