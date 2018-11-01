#pragma once
#include "GameObject.h"

class Ball extends public GameObject
{
public:
	Ball(float r, Vector2 vel);
	~Ball();

	void Update();
	void VelocityFlipX();
	void VelocityFlipY();
};