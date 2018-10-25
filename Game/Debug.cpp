#include "Debug.h"
#include <iostream>
#include <string>
using namespace std;

void Debug::Log(int x, int y, string m, unsigned int color)
{
	DrawFormatString(x, y, color, m);
}

void Debug::Line(Vector2 pos1, Vector2 pos2, UINT color)
{
	DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, color);
}
