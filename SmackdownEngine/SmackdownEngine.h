#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SceneManager.h"
#include "resource.h"
#include "Input.h"

using namespace sf;

class SmackdownEngine {
public:
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

	sf::RenderWindow v_Window;
	sf::Texture v_ExampleTexture;
	sf::Clock v_Clock;
	//void Input();
	void Update(float dtAsSeconds);
	void Draw();
	float p1Score, p2Score;
	SCENE scene = SPLASH;
	int GAME_STATE = SPLASH;

public:
	SmackdownEngine();
	void CheckSystemReqs();
	void Start();
	void InitializeGame();
	Input input;

};