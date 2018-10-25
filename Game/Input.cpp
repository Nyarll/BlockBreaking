#include "Input.h"


// <Key Board>

void InputKeyBoard::Update()
{
	for (int i = 0; i < 256; i++)
	{
		key_old[i] = key[i];
	}
	GetHitKeyStateAll(key);
}

bool InputKeyBoard::GetDown(int key_id)
{
	if (this->key[key_id] && this->key_old[key_id])
	{
		return true;
	}
	return false;
}

bool InputKeyBoard::GetNow(int key_id)
{
	if (this->key[key_id])
	{
		return true;
	}
	return false;
}

bool InputKeyBoard::GetUp(int key_id)
{
	if (!this->key[key_id] && !this->key_old[key_id])
	{
		return true;
	}
	return false;
}


// <Mouse>

InputMouse::InputMouse()
{
	this->now = 0;
	this->old = 0;
}

void InputMouse::Update()
{
	old = now;
	now = GetMouseInput();

	int x, y;
	GetMousePoint(&x, &y);
	this->position.Set((float)x, (float)y);
}

bool InputMouse::GetDown(int bottun)
{
	if (((now & bottun) == bottun) && ((old & bottun) != bottun))
	{
		return true;
	}
	return false;
}

bool InputMouse::GetNow(int bottun)
{
	if ((now & bottun) == bottun)
	{
		return true;
	}
	return false;
}

bool InputMouse::GetUp(int bottun)
{
	if (((now & bottun) != bottun) && ((old & bottun) == bottun))
	{
		return true;
	}
	return false;
}

Vector2 InputMouse::GetPosition()
{
	return this->position;
}


// <Input>
Input::Input()
{
	key = new InputKeyBoard;
	mouse = new InputMouse;
}

Input::~Input()
{
	delete key;
	delete mouse;
}

void Input::Update()
{
	key->Update();
	mouse->Update();
}