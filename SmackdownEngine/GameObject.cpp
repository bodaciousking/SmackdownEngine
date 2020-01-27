#include "GameObject.h"
#include <iostream>

using std::cout;
using std::endl;

void GameObject::Start()
{
	for (std::vector<GameObject*>::iterator i = v_Children.begin(); i != v_Children.end(); i++)
	{
		(*i)->Start();
	}
}


void GameObject::Update(sf::Time deltaTime)
{
	if (v_Parent)
	{
		worldTransform = v_Parent->worldTransform * v_Transform->transformMatrix;
	}

	else
	{
		worldTransform = v_Transform->transformMatrix;
	}

	v_Transform->Update();
	v_Render->UpdatePosition();
	for (std::vector<GameObject*>::iterator i = v_Children.begin(); i != v_Children.end(); i++)
	{
		(*i)->Update(deltaTime);
	}
}

void GameObject::SetParent(GameObject& parent)
{
	v_Parent = &parent;
}

void GameObject::AddChild(GameObject* child)
{
	v_Children.push_back(child);
}