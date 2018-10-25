#pragma once
#include "GameObject.h"
#include "Input.h"

class Player extends public GameObject
{
private:
	Input* input;

public:
	Player();
	~Player();

	void Update();
};