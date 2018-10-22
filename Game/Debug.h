#pragma once
#include "Vector.h"

class Debug
{
public:
	void Log(int x, int y, const char* m, unsigned int color);
	void Line(Vector2 pos1, Vector2 pos2, UINT color);
};