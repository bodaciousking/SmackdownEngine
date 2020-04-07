#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SceneManager.h"
#include "resource.h"
#include "Input.h"

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
	sf::Sprite v_SplashSprite;
	sf::Sprite v_MenuSprite;
	sf::Sprite v_GameSprite;
	sf::Sprite v_ResultsSprite;
	sf::Texture v_SplashTexture;
	sf::Texture v_MenuTexture;
	sf::Texture v_GameTexture;
	sf::Texture v_ResultsTexture;
	sf::Texture v_ExampleTexture;
	sf::Text v_SplashText;
	sf::Font font;
	sf::Clock v_Clock;

	sf::Sprite v_Player1Sprite;
	sf::Texture v_Player1Texture;
	sf::Texture v_Player1AttackTexture;

	//void Input();
	void Update(float dtAsSeconds);
	void Draw();
	void InitializeGame();
	float p1Score, p2Score;
	SCENE scene = SPLASH;
	int GAME_STATE = SPLASH;

public:
	SmackdownEngine();
	void CheckSystemReqs();
	void Start();
	Input input;
	sf::RenderWindow v_Window;

};