#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SceneManager.h"
#include "resource.h"

using namespace sf;

class SmackdownEngine {
private:
	sf::RenderWindow v_Window;
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

};