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
#include "GameObject.h"

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
SceneManager sceneManager;

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

	//EXAMPLE GAMEOBJECT
	v_ExampleTexture.loadFromFile("../Assets/unnamed.png");
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

bool SmackdownEngine::isRunning()
{
	return v_Window.isOpen();
}

void SmackdownEngine::close()
{
	v_Window.close();
}

void SmackdownEngine::clearWindow()
{
	v_Window.clear(sf::Color::Black);
}

void SmackdownEngine::displayWindow()
{
	v_Window.display();
}

void SmackdownEngine::draw(sf::Sprite sprite)
{
	v_Window.draw(sprite);
}

void SmackdownEngine::draw(sf::Text _text)
{
	v_Window.draw(_text);
}

std::string SmackdownEngine::intToString(int i)
{
	std::string s = std::to_string(i);
	return s;
}
