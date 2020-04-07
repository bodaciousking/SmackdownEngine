#pragma region INCLUDES
#include "SmackdownEngine.h"
#include "SceneManager.h"
#include "SceneGraph.h"
#include "Input.h"
#include <SFML/System/Clock.hpp>
#include <windows.h>
#include <winnt.h>
#include <iostream>
#include <string>
#include <sstream>
#include <tchar.h>
#include <random>
#include <functional>
#include <cstdlib>
#include <cmath>
#include <SFML/Graphics.hpp>

extern "C" {
#include <Powrprof.h>
}
#pragma comment(lib, "Powrprof.lib")
typedef struct _PROCESSOR_POWER_INFORMATION
{
	ULONG num;
	ULONG maxMhz;
	ULONG currMhz;
	ULONG limitMhz;
	ULONG maxIdle;
	ULONG currIdle;
}PROCESSOR_POWER_INFORMATION, *PPROCESSOR_POWER_INFORMATION;

#pragma endregion INCLUDES

Vector2f resolution;
//float splashTimer = 30.0f;

//Input input;

SceneGraph sceneGraph;

sf::IntRect v_P1MoveSpriteRect(20, 50, 46, 75);
sf::IntRect v_P1AttackSpriteRect(10, 120, 65, 75);


sf::Clock v_P1Interval;
float p1Interval;

SmackdownEngine::SmackdownEngine()
{
	//GET MONITOR RESOLUTION
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	//OPEN WINDOW
	v_Window.create(VideoMode(resolution.x, resolution.y),
		"This engine's layin the Smackdown.",
		Style::Fullscreen);

	v_Window.setMouseCursorVisible(false);

	//SPLASH SCREEN STUFF
	v_SplashTexture.loadFromFile("../Assets/Splash.jpg");
	v_SplashSprite.setTexture(v_SplashTexture);

	v_MenuTexture.loadFromFile("../Assets/Menu.jpg");
	v_MenuSprite.setTexture(v_MenuTexture);

	v_GameTexture.loadFromFile("../Assets/Game.jpg");
	v_GameSprite.setTexture(v_GameTexture);

	v_ResultsTexture.loadFromFile("../Assets/Results.jpg");
	v_ResultsSprite.setTexture(v_ResultsTexture);

	v_Player1Texture.loadFromFile("../Assets/Ninja Run.png");
	v_Player1AttackTexture.loadFromFile("../Assets/Ninja Attack.png");
	
	//v_Player1Sprite.setTextureRect(sf::IntRect(20, 15, 32, 50));
	//v_Player1Sprite.setTextureRect(v_P1SpriteRect);
	//v_Player1Sprite.setTextureRect(v_P1AttackSpriteRect);

	//v_Player1Sprite.setScale(10, 10);

	


	//EXAMPLE GAMEOBJECT
	v_ExampleTexture.loadFromFile("../Assets/unnamed.png");

	// sceneGraph.CreateObject(v_ExampleTexture, true, (resolution.x / 2, resolution.y / 2));
}

void SmackdownEngine::Start()
{

	//while (v_Window.isOpen())
	//{


	
	while (v_Window.isOpen())
	{
		v_Window.clear(Color::Black);
		if(input.esc())
			v_Window.close();

		switch (GAME_STATE)
		{
		case SPLASH:
			scene = SPLASH;
			//v_Window.clear(Color::Black);
			//v_Window.draw(v_SplashSprite);

			v_Window.clear(Color::Green);
			v_Window.draw(v_Player1Sprite);

			p1Interval = v_P1Interval.getElapsedTime().asSeconds();

			if (input.right() || input.left())
			{
				v_Player1Sprite.setScale(10, 10);
				float speed;

				if (input.right())
				{
					if (v_Player1Sprite.getScale().x <= -0.0f)
					{
						v_Player1Sprite.setScale(-v_Player1Sprite.getScale().x, v_Player1Sprite.getScale().y);
					}
					speed = 150;
				}
				else if (input.left())
				{
					if (v_Player1Sprite.getScale().x > 0.0f)
					{
						v_Player1Sprite.setScale(-v_Player1Sprite.getScale().x, v_Player1Sprite.getScale().y);

					}
					speed = -150;
				}

				v_Player1Sprite.setTexture(v_Player1Texture);

				if (p1Interval >= 0.1f)
				{
					if (v_P1MoveSpriteRect.left >= 170)
						v_P1MoveSpriteRect.left = 20;
					else
					{
						v_P1MoveSpriteRect.left += 50;
						v_Player1Sprite.setPosition(v_Player1Sprite.getPosition().x + speed, v_Player1Sprite.getPosition().y);
					}

					v_P1Interval.restart();
				}

					v_Player1Sprite.setTextureRect(v_P1MoveSpriteRect);
			}

/*			if (input.left())
			{
				if(v_Player1Sprite.getScale().x > 0.0f)
				v_Player1Sprite.setScale(-v_Player1Sprite.getScale().x, v_Player1Sprite.getScale().y);

				v_Player1Sprite.setTexture(v_Player1Texture);

				if (p1Interval >= 0.1f)
				{
					if (v_P1MoveSpriteRect.left >= 170)
						v_P1MoveSpriteRect.left = 20;
					else
					{
						v_P1MoveSpriteRect.left += 50;
						v_Player1Sprite.setPosition(v_Player1Sprite.getPosition().x - 150, v_Player1Sprite.getPosition().y);
					}

					v_P1Interval.restart();
				}

				v_Player1Sprite.setTextureRect(v_P1MoveSpriteRect);
			}*/

			else if (input.space())
			{
				v_Player1Sprite.setScale(15, 15);
				v_Player1Sprite.setTexture(v_Player1AttackTexture);

				if (p1Interval >= 0.1f)
				{
					if (v_P1AttackSpriteRect.left >= 360)
						v_P1AttackSpriteRect.left = 10;
					else
						v_P1AttackSpriteRect.left += 70;

					v_P1Interval.restart();
				}
				//v_P1AttackSpriteRect.left = 150;
				v_Player1Sprite.setTextureRect(v_P1AttackSpriteRect);
			}

			else {
				v_Player1Sprite.setScale(11, 11);
				v_Player1Sprite.setTexture(v_Player1AttackTexture);
				v_P1AttackSpriteRect.left = 10;
				v_Player1Sprite.setTextureRect(v_P1AttackSpriteRect);
			}

			if (input.enter())
				GAME_STATE = MENU;
			break;

		case MENU:
			scene = MENU;
			v_Window.clear(Color::Black);
			v_Window.draw(v_MenuSprite);
			if (input.enter())
			{
				GAME_STATE = GAME;
				SmackdownEngine::InitializeGame();
				sceneGraph.Start();
			}
			break;
			//std::cout << "drawing";

		case GAME:
			scene = GAME;
			v_Window.clear(Color::Black);
			v_Window.draw(v_GameSprite);/*
			if (v_Clock.getElapsedTime().asMilliseconds > 1000) {
				v_Clock.restart();
				sceneGraph.Update(v_Clock.getElapsedTime);
			}*/


			if (input.enter())
				GAME_STATE = RESULTS;
			break;

		case RESULTS:
			scene = RESULTS;
			v_Window.clear(Color::Black);
			v_Window.draw(v_ResultsSprite);
			if (input.enter())
				GAME_STATE = MENU;
			break;

		default:
			break;
		}

		v_Window.display();
		//}
	}
}

	void SmackdownEngine::InitializeGame() {
	v_Clock.restart();
}

void SmackdownEngine::CheckSystemReqs()
{
	int requiredSpace = 300;
	SYSTEM_INFO sysInfo;
	ULARGE_INTEGER ulFreeSpace;
	ULARGE_INTEGER ulTotalSpace;
	ULARGE_INTEGER ulTotalFreeSpace;
	std::string msgTxt;

	GetDiskFreeSpaceEx(_T("C:"), &ulFreeSpace, &ulTotalSpace, &ulTotalFreeSpace);

	int totalFreeSpaceInMb = (ulTotalFreeSpace.QuadPart / (1024 * 1024));

	if (requiredSpace < totalFreeSpaceInMb)
	{
		std::cout << "Sufficient space. \nDisk space required: " << requiredSpace << "MB" << ".\nDisk space available: " << totalFreeSpaceInMb << "MB" << std::endl;
	}
	else
	{
		std::cout << "Insufficient space. \nDisk space required: " << requiredSpace << "MB" << ".\nDisk space available: " << totalFreeSpaceInMb << "MB" << std::endl;
	}
}
