#pragma once
#include <SFML/Audio.hpp>
#include "Macros.h"

class AudioHolder
{
public:

	~AudioHolder();

	static AudioHolder& instance();

	void playSound(int element);
	void pauseSound(int element);
	void stopSound(int element);

private:

	AudioHolder();

	sf::SoundBuffer m_tracks[AUDIO];
	sf::Sound m_sound[AUDIO];
};
