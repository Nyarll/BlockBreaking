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

Vector2 GameObject::GetVelocity()
{
	return this->velocity;
}

void GameObject::SetSpeed(Vector2 spd)
{
	this->speed = spd;
}

Vector2 GameObject::GetHitSizeV()
{
	return this->hitsize;
}
float GameObject::GetHitSizeF()
{
	return this->r;
}

void GameObject::SetSprite(int* graph_handle, Vector2 pos, Vector2 size, float scale)
{

	if ((*graph_handle == NOT_FOUND_TEXTURE) || (*graph_handle == 0))	// グラフィックハンドルが読み込めていなければ、Nullを表示させる
	{
		*graph_handle = MakeScreen(INT_CAST size.x, INT_CAST size.y);
		SetDrawScreen(*graph_handle);

		DrawBox(0, 0, INT_CAST size.x, INT_CAST size.y, 0xffff00ff, TRUE);
		DrawBox(INT_CAST size.x / 2, 0, INT_CAST size.x, INT_CAST size.y / 2, 0xff000000, TRUE);
		DrawBox(0, INT_CAST size.y / 2, INT_CAST size.x / 2, INT_CAST size.y, 0xff000000, TRUE);

		DrawCircle(INT_CAST size.x / 2, INT_CAST size.y / 2, INT_CAST size.x / 2, 0xffff0000, FALSE, 5);

		DrawBox(0, 0, INT_CAST size.x, INT_CAST size.y, COLOR_WHITE, FALSE);

		SetDrawScreen(DX_SCREEN_BACK);
	}

	this->sprite.texture = *graph_handle;
	this->sprite.pos = pos;
	this->sprite.size = size;
	this->sprite.scale = scale;

	this->hitsize = size;
	if (hitsize.x == hitsize.y)
	{
		this->r = hitsize.x / 2;
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
	DrawRotaGraph(INT_CAST sprite.pos.x, INT_CAST sprite.pos.y, sprite.scale, sprite.rota, sprite.texture, TRUE);
}

bool GameObject::GetAliveFlag()
{
	return this->alive;
}
void GameObject::SetAliveFlag(bool flag)
{
	this->alive = flag;
}

bool GameObject::CircleCollision(const GameObject* obj)
{
	float hlength = this->r + obj->r;
	float xlength = this->position.x - obj->position.x;
	float ylength = this->position.y - obj->position.y;

	if (hlength * hlength >= xlength * xlength + ylength * ylength)
	{
		return true;
	}
	return false;

}

bool GameObject::BoxCollision(const GameObject* obj)
{
	float ax1 = this->position.x - this->hitsize.x / 2;
	float ay1 = this->position.y - this->hitsize.y / 2;
	float ax2 = this->position.x + this->hitsize.x / 2;
	float ay2 = this->position.y + this->hitsize.y / 2;

	float bx1 = obj->position.x - obj->hitsize.x / 2;
	float by1 = obj->position.y - obj->hitsize.y / 2;
	float bx2 = obj->position.x + obj->hitsize.x / 2;
	float by2 = obj->position.y + obj->hitsize.y / 2;

#if defined(_DEBUG)
	DrawBox(INT_CAST ax1, INT_CAST ay1, INT_CAST ax2, INT_CAST ay2, COLOR_RED, FALSE);
	DrawBox(INT_CAST bx1, INT_CAST by1, INT_CAST bx2, INT_CAST by2, COLOR_RED, FALSE);
#endif

	if ((bx1 < ax2) && (by1 < ay2) && (bx2 > ax1) && (by2 > ay1))
	{
		return true;
	}
	return false;
}

void GameObject::Clamp(int xmax, int xmin, int ymax, int ymin)
{
	float px1 = this->position.x - this->hitsize.x / 2;
	float py1 = this->position.y - this->hitsize.y / 2;
	float px2 = this->position.x + this->hitsize.x / 2;
	float py2 = this->position.y + this->hitsize.y / 2;

	if (px1 < xmin)
	{
		this->position.x = this->hitsize.x / 2;
	}
	if (py1 < ymin)
	{
		this->position.y = this->hitsize.y / 2;
	}

	if (px2 > xmax)
	{
		this->position.x = xmax - this->hitsize.x / 2;
	}
	if (py2 > ymax)
	{
		this->position.y = ymax - this->hitsize.y / 2;
	}
}