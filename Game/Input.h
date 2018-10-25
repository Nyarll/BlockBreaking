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

class InputJoypad
{
private:
	int id;
	int now;
	int old;

public:
	// �R���X�g���N�^
	InputJoypad(int pad_id = DX_INPUT_KEY_PAD1);
	// �f�X�g���N�^
	~InputJoypad();

	// ����
	void Update();    // �X�V

	bool GetDown(int bottun);
	bool GetNow(int bottun);
	bool GetUp(int bottun);
};


class InputManager
{
public:
	InputKeyBoard* key;
	InputMouse* mouse;
	InputJoypad* joypad;

public:
	InputManager();
	~InputManager();

	void Update();
};