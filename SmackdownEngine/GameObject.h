#pragma once
#ifndef GAMEOBJECv_H
#define GAMEOBJECv_H

#pragma once
#include <vector>
#include <list>
#include <iterator>

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Vector2.h"
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "RenderComponent.h"

class GameObject
{
private:
	GameObject* v_Parent;
	std::vector<GameObject*> v_Children;

	sf::Texture v_Texture;

	sf::Transform identityMatrix;
	sf::Transform worldTransform;

public:
	TransformComponent* v_Transform;
	RenderComponent* v_Render;

	int v_ID;

	GameObject() {}
	GameObject(int objID, sf::Texture texture, bool isKinematic, sf::Vector2f pos) : v_ID(objID), v_Parent(NULL), v_Texture(texture)
	{
		v_Transform = new TransformComponent();
		v_Transform-> v_Position = pos;
		v_Render = new RenderComponent(v_Transform, v_Texture);
		v_Render->Start();
	}

	void SetParent(GameObject& parent);
	void AddChild(GameObject* child);

	void Start();
	void Update(sf::Time deltaTime);

};

#endif