#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SceneManager.h"
#include "resource.h"

using namespace sf;

class SmackdownEngine {
private:
	RenderWindow v_Window;
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

};