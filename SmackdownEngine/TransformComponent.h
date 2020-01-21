#pragma once
#include "vec2.h"
#include "BaseComponent.h"
class TransformComponent : public BaseComponent
{
public:
	vec2 position;
	vec2 scale;

	TransformComponent();
	~TransformComponent();
};

