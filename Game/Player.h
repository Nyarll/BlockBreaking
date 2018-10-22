#pragma once
#include "GameObject.h"
#include "Input.h"

class Player extends public GameObject
{
private:
	InputKeyBoard* key;

public:
	Player();
	~Player();

	void Update();
};