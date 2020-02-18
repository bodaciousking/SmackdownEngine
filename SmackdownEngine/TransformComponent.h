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
	sf::Vector2f v_Position;
	sf::Vector2f v_Rotation;
	sf::Vector2f v_Scale;
};