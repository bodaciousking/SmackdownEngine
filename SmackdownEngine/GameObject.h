#pragma once
#include <vector>
#include <list>
class GameObject
{
public:
	std::string objectName;

	void Update() {};
	void UpdateChildren() {};

	std::list<GameObject> childObjects;

	GameObject();
	~GameObject();
};

