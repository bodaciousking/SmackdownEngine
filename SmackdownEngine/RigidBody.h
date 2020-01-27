#pragma once
#include "TransformComponent.h"
class RigidBody :
	public TransformComponent
{
public:
	RigidBody();
	~RigidBody();

	vec2 c_Pos;
	vec2 c_Vel;
	vec2 c_Accel;
	
	float mass; 
	//void AddForce(const vec2 &force) { v_Forces.push_back(force); }
	void AddImpulse(const vec2 &impulse)
	{
		//v_Impulses.push_back(impulse);
	}
	void OnUpdate(const float time);
};

