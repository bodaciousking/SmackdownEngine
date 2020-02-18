#pragma region INCLUDES
#include "SmackdownEngine.h"
#include "SceneManager.h"
#include "Input.h"
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
}

void SmackdownEngine::Start()
{
	//while (v_Window.isOpen())
	//{

		v_Window.clear(Color::Black);
		//if(input.esc())
			//v_Window.close();

		switch (GAME_STATE)
		{
		case SPLASH:
			scene = SPLASH;
			v_Window.clear(Color::Black);
			v_Window.draw(v_SplashSprite);

			if (input.enter())
				GAME_STATE = MENU;
			break;

			//std::cout << "drawing";

		case MENU:
			scene = MENU;
			v_Window.clear(Color::Black);
			v_Window.draw(v_MenuSprite);
			if (input.enter())
				GAME_STATE = GAME;
			break;
			//std::cout << "drawing";

		case GAME:
			scene = GAME;
			v_Window.clear(Color::Black);
			v_Window.draw(v_GameSprite);
			if (input.enter())
				GAME_STATE = RESULTS;
			break;
			//std::cout << "drawing";

		case RESULTS:
			scene = RESULTS;
			v_Window.clear(Color::Black);
			v_Window.draw(v_ResultsSprite);
			if (input.enter())
				GAME_STATE = MENU;
			break;
			//std::cout << "drawing";
		default:
			break;
		}

		v_Window.display();
	//}
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