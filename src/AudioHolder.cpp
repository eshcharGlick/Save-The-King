#include "AudioHolder.h"

void AudioHolder::playSound(int element)
{
	m_sound[element].play();
}

void AudioHolder::pauseSound(int element)
{
	m_sound[element].pause();
}

void AudioHolder::stopSound(int element)
{
	m_sound[element].stop();
}


AudioHolder::AudioHolder()
{
	m_tracks[AUDIO_GAME].loadFromFile("game.wav");
	m_tracks[AUDIO_MENU].loadFromFile("menu.wav");
	m_tracks[AUDIO_FINISH_GAME].loadFromFile("finishGame.wav");
	m_tracks[AUDIO_FINISH_LEVEL].loadFromFile("finishLevel.wav");

	m_sound[AUDIO_GAME].setBuffer(m_tracks[AUDIO_GAME]);
	m_sound[AUDIO_MENU].setBuffer(m_tracks[AUDIO_MENU]);
	m_sound[AUDIO_FINISH_GAME].setBuffer(m_tracks[AUDIO_FINISH_GAME]);
	m_sound[AUDIO_FINISH_LEVEL].setBuffer(m_tracks[AUDIO_FINISH_LEVEL]);

	m_sound[AUDIO_GAME].setLoop(true);
	m_sound[AUDIO_MENU].setLoop(true);
}

AudioHolder::~AudioHolder()
{
}

AudioHolder& AudioHolder::instance()
{
	static AudioHolder instance;
	return instance;
}