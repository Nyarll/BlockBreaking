#include "Block.h"

Block::Block(Vector2 pos, Vector2 size, UINT color)
{
	this->SetPosition(pos);
	
	int gh = 0;
	gh = MakeScreen(size.x, size.y, true);
	SetDrawScreen(gh);
	DrawBox(0, 0, size.x, size.y, COLOR_WHITE, TRUE);
	DrawBox(1, 1, size.x - 1, size.y - 1, color, TRUE);

	SetDrawScreen(DX_SCREEN_BACK);

	this->SetSprite(&gh, pos, size);

	this->flag = true;
}

Block::~Block()
{

}

bool Block::GetFlag()
{
	return this->flag;
}

void Block::SetFlag(bool flag)
{
	this->flag = flag;
}