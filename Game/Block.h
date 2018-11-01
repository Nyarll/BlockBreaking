#pragma once
#include "GameObject.h"

class Block extends public GameObject
{
private:
	bool flag;

public:
	Block(Vector2 pos, Vector2 size, UINT color);
	~Block();

	bool GetFlag();
	void SetFlag(bool flag);

};