#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SceneManager.h"
#include "resource.h"
#include "Input.h"
#include <windows.h>

#include <string>

using namespace sf;

class SmackdownEngine {
private:

	/*
	Sprite v_SplashSprite;
	Sprite v_MenuSprite;
	Sprite v_GameSprite;
	Sprite v_ResultsSprite;
	Texture v_SplashTexture;
	Texture v_MenuTexture;
	Texture v_GameTexture;
	Texture v_ResultsTexture;
	Text v_SplashText;
	Font font;
	*/

	//sf::RenderWindow v_Window;

	sf::Texture v_ExampleTexture;
	sf::Text v_SplashText;
	sf::Font font;
	sf::Clock v_Clock;

	sf::Sprite v_Player1Sprite;
	sf::Texture v_Player1Texture;
	sf::Texture v_Player1AttackTexture;

	//void Input();
	void Update(float dtAsSeconds);
	void InitializeGame();

public:
	SmackdownEngine();
	void CheckSystemReqs();
	bool isRunning();
	void close();
	void clearWindow();
	void displayWindow();
	void draw(sf::Sprite sprite);
	void draw(sf::Text _text);
	std::string intToString(int i);
	Input input;
	sf::RenderWindow v_Window;
	sf::Color color;
};