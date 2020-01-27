#include "RenderComponent.h"
#include <iostream>

void RenderComponent::UpdatePosition()
{
	v_Sprite.setPosition(v_ownerTransform->v_Position.x, v_ownerTransform->v_Position.y);
}

void RenderComponent :: Start()
{
	v_Sprite = sf::Sprite(v_Texture);

	SetBounds();

	v_Sprite.setPosition(v_ownerTransform->v_Position.x, v_ownerTransform->v_Position.y);

	std::cout << "sprite created" << std::endl;
}

void RenderComponent::SetBounds()
{
	sf::Rect<float> r = v_Sprite.getLocalBounds();

	std::cout << "Rect: T(" << r.top << "), L(" << r.left << "), H(" << r.height << "), W(" << r.width << ")" << std::endl;

	v_Bounds.center = Vector2(v_Sprite.getOrigin().x, v_Sprite.getOrigin().y);
	v_Bounds.extents = Vector2(r.width * 0.5f, r.height * 0.5f);
}