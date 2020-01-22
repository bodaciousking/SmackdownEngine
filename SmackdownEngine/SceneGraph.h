#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "GameObject.h"

class SceneGraph
{
public:
	std::string sceneName;

	//std::list<GameObject> gOChain;
	std::vector<GameObject> gameObjectChain;

	void UpdateAllGameObjects() {};

	SceneGraph(std::string _sceneName);


	~SceneGraph();
};

