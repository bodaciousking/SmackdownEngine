#include "stdafx.h"
#include "SceneGraph.h"
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;

SceneGraph::SceneGraph(std::string _sceneName)
{
	sceneName = _sceneName;
	gameObjectChain; //= new std::vector<GameObject>();
}


void SceneGraph::UpdateAllGameObjects() {

	cout << "Update all GOs has been called!" << std::endl;
	/*for each (GameObject gO in gameObjectChain)
	{
		cout << "We're doing it" << std::endl;
	}*/
};

SceneGraph::~SceneGraph()
{

}
