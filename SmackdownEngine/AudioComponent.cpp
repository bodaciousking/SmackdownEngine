#include "AudioComponent.h"
#include <iostream>

sf::SoundBuffer AudioComponent::buffer;
sf::Music AudioComponent::music;
sf::Sound AudioComponent::sound;



AudioComponent::AudioComponent()
{
	std::cout << "Audio Component constructor called..." << std::endl;

}


AudioComponent::~AudioComponent()
{
}

void AudioComponent::Initialize()
{
	std::cout << "Audio Engine Started" << "\n";
}

void AudioComponent::PlayMusic(std::string filename)
{
	if (!music.openFromFile("../Assets/" + filename))
	{
		printf("AUDIO ERROR\n");
		return;
	}
	music.setVolume(50.0f);
	music.play();
}

//
//void AudioComponent::StopMusic()
//{
//	music.stop();
//}