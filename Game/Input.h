#pragma once
#include "Define.h"
#include "Vector.h"

class InputKeyBoard
{
private:
	char key[256] = { 0 };
	char key_old[256] = { 0 };

public:
	InputKeyBoard() {};
	~InputKeyBoard() {};

	void Update();
	bool GetDown(int key_id);
	bool GetNow(int key_id);
	bool GetUp(int key_id);
};

class InputMouse
{
private:
	Vector2 position;
	int now;
	int old;

public:
	InputMouse();
	~InputMouse() {};

	void Update();
	bool GetDown(int bottun);
	bool GetNow(int bottun);
	bool GetUp(int bottun);

	Vector2 GetPosition();
};


class Input
{
public:
	InputKeyBoard* key;
	InputMouse* mouse;

public:
	Input();
	~Input();

	void Update();
};