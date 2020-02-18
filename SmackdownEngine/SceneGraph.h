#pragma once
#include <list>
#include <map>
#include <iostream>

#include "GameObject.h"


class SceneGraph
{
public:
	GameObject* CreateObject(sf::Texture texture, bool isKinematic, sf::Vector2f pos);

	void Start();
	void Update(sf::Time deltaTime);

	std::list<RenderComponent*> renderComponents;

private:
	std::map<int, GameObject*> v_Objects;
	static int nextObjectID;
};