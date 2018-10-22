#include "GameObject.h"

const int NOT_FOUND_TEXTURE = (-1);


GameObject::GameObject()
{
	alive = false;
	state = 0;
	position = { 0,0 };
	velocity = { 0,0 };
	speed = { 0,0 };

	sprite.pos = { 0,0 };
	sprite.rota = 0;
	sprite.scale = 0;
	sprite.size = { 0,0 };
	sprite.texture = NOT_FOUND_TEXTURE;

	color = { 0,0,0 };

	rad_vel = 0;
	rotate = 0;
	scale = 0;

	hitsize = { 0,0 };
	r = 0;

	cnt = 0;
}


GameObject::~GameObject()
{
	
}

void GameObject::SetPosition(Vector2 pos)
{
	this->position = pos;
}

Vector2 GameObject::GetPosition()
{
	return this->position;
}

void GameObject::SetVelocity(Vector2 vel)
{
	this->velocity = vel;
}

void GameObject::SetSpeed(Vector2 spd)
{
	this->speed = spd;
}

void GameObject::SetSprite(int* graph_handle, Vector2 pos, Vector2 size, float scale)
{

	if ((*graph_handle == NOT_FOUND_TEXTURE)||(*graph_handle == 0))	// グラフィックハンドルが読み込めていなければ、Nullを表示させる
	{
		*graph_handle = MakeScreen(size.x, size.y);
		SetDrawScreen(*graph_handle);

		DrawBox(0, 0, size.x, size.y, 0xffff00ff, TRUE);
		DrawBox(size.x / 2, 0, size.x, size.y / 2, 0xff000000, TRUE);
		DrawBox(0, size.y / 2, size.x / 2, size.y, 0xff000000, TRUE);

		DrawCircle(size.x / 2, size.y / 2, size.x / 2, 0xffff0000, FALSE, 5);

		DrawBox(0, 0, size.x, size.y, COLOR_WHITE, FALSE);

		SetDrawScreen(DX_SCREEN_BACK);
	}

	this->sprite.texture = *graph_handle;
	this->sprite.pos = pos;
	this->sprite.size = size;
	this->sprite.scale = scale;

	this->hitsize = size;
	if (hitsize.x == hitsize.y)
	{
		this->r = hitsize.x;
	}
}
void GameObject::GameObjectRotate(float rad)
{
	this->rotate = rad;
	this->sprite.rota = this->rotate;
}

void GameObject::MovePos()
{
	this->position = this->position.Add(&this->velocity);
	this->sprite.pos = this->position;
}

void GameObject::Render()
{
	DrawRotaGraph(sprite.pos.x, sprite.pos.y, sprite.scale, sprite.rota, sprite.texture, TRUE);
}

bool GameObject::GetAliveFlag()
{
	return this->alive;
}
void GameObject::SetAliveFlag(bool flag)
{
	this->alive = flag;
}