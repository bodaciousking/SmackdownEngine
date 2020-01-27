#pragma once

#include "SFML/Graphics/Transform.hpp"
#include "BaseComponent.cpp"
#include "Vector2.h"

class TransformComponent : BaseComponent
{
public:
	TransformComponent() : v_Position(), v_Rotation(), v_Scale(1.0f, 1.0f) {}

	void Start();
	void Update();

	sf::Transform transformMatrix;
	Vector2 v_Position;
	Vector2 v_Rotation;
	Vector2 v_Scale;
};