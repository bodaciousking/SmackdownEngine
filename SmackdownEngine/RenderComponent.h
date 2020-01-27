#pragma once
#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Rect.hpp"

#include "BaseComponent.h"
#include "TransformComponent.h"
#include "Vector2.h"


struct Bounds
{
public:
	Vector2 center;
	Vector2 extents;
};

class RenderComponent : BaseComponent
{
private: 
	void SetBounds();
public:
	sf::Texture v_Texture;
	Bounds v_Bounds;
	TransformComponent* v_ownerTransform;
	sf::Sprite v_Sprite;

	RenderComponent() {}
	RenderComponent(TransformComponent* ownerTransform, sf::Texture texture) : v_ownerTransform(ownerTransform), v_Texture(texture) {}
	~RenderComponent() {}

	void Start();
	void UpdatePosition();
};
#endif