#pragma once
#include "Define.h"
#include "Vector.h"

class Input
{
public:
	Input() {};

	~Input() {};

	virtual void Update() = 0;
};

class InputKeyBoard extends public Input
{
private:
	char key[256] = { 0 };
	char key_old[256] = { 0 };

public:
	InputKeyBoard() {};
	~InputKeyBoard() {};

	void Update() override;
	bool GetDown(int key_id);
	bool GetNow(int key_id);
	bool GetUp(int key_id);
};

class InputMouse extends public Input
{
private:
	Vector2 position;
	int now;
	int old;

public:
	InputMouse();
	~InputMouse() {};

	void Update() override;
	bool GetDown(int bottun);
	bool GetNow(int bottun);
	bool GetUp(int bottun);

	Vector2 GetPosition();
};