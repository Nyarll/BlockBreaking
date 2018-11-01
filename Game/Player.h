#pragma once
#include "GameObject.h"
//#include "Input.h"

class InputManager;

class Player extends public GameObject
{
public:
	Player(Vector2 initpos);
	~Player();

	void Update(InputManager* input);
	void AutoPlay(GameObject* ball);
};