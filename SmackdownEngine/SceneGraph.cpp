#include "SceneGraph.h"

int SceneGraph::nextObjectID = 0;

GameObject* SceneGraph::CreateObject(sf::Texture texture, bool isKinematic, sf::Vector2f pos)
{
	std::cout << "SceneGraph is creating a gameobject." << std::endl;

	GameObject* obj = new GameObject(nextObjectID, texture, isKinematic, pos);
	v_Objects.insert(std::make_pair(nextObjectID, obj));

	nextObjectID++;

	renderComponents.push_back(obj->v_Render);

	return obj;
}

void SceneGraph::Start()
{
	for (std::map<int, GameObject*>::iterator i = v_Objects.begin(); i != v_Objects.end(); ++i)
	{
		(i->second)->Start();
	}
	std::cout << "SceneGraph Initialized!" << std::endl;
}

void SceneGraph::Update(sf::Time deltatime)
{
	for (std::map<int, GameObject*>::iterator i = v_Objects.begin(); i != v_Objects.end(); ++i)
	{
		(i->second)->Update(deltatime);
	}
	//std::cout << "SceneGraph Updated with dt "; std::cout << deltatime.asMilliseconds << std::endl;
}
