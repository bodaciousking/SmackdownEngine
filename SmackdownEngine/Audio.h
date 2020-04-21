#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>

class Audio
{
private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

	std::string url;

public:
	void setBuffer(std::string _string);
	void setTrack(std::string _string);

	void playSound(int vol, bool repeat);
	void stopSound();
	void pauseSound();

	void playMusic(int vol, bool repeat);
	void stopMusic();
	void pauseMusic();

};

