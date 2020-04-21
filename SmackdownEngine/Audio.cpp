#include "Audio.h"


void Audio::setBuffer(std::string _string)
{
	buffer.loadFromFile(_string);
	sound.setBuffer(buffer);
}

void Audio::setTrack(std::string _string)
{
	url = _string;
	music.openFromFile(url);
}

void Audio::playSound(int vol, bool repeat)
{
	sound.setVolume(vol);
	sound.setLoop(repeat);
	sound.play();
}

void Audio::stopSound()
{
	sound.stop();
}

void Audio::pauseSound()
{
	sound.pause();
}

void Audio::playMusic(int vol, bool repeat)
{
	music.setVolume(vol);
	music.setLoop(repeat);
	music.play();
}

void Audio::stopMusic()
{
	music.stop();
}

void Audio::pauseMusic()
{
	music.pause();
}