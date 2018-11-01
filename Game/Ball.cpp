#include "Ball.h"
#include "Debug.h"

Ball::Ball(float r, Vector2 vel)
{
	this->SetPosition({ FLOAT_CAST SCREEN_CENTER_X, FLOAT_CAST SCREEN_CENTER_Y });
	this->SetVelocity(vel);

	{
		int gh = 0;
		gh = MakeScreen(INT_CAST(r) + 1, INT_CAST(r) + 1, true);
		SetDrawScreen(gh);
		DrawCircle(INT_CAST (r / 2), INT_CAST (r / 2), INT_CAST (r / 2), COLOR_WHITE);
		SetDrawScreen(DX_SCREEN_BACK);
		this->SetSprite(&gh, GetPosition(), { r,r });
	}
}

Ball::~Ball()
{

}

void Ball::Update()
{
	float r = this->GetHitSizeF();
	Vector2 now_pos = this->GetPosition();
	Debug debug;

	if (now_pos.x - (r) < SCREEN_LEFT)
	{
		this->VelocityFlipX();
		//debug.Log(0, SCREEN_BOTTOM - 40, " BallClass : ScreenLeft HIT",0xffffffff);
	}
	if (now_pos.x + (r) > SCREEN_RIGHT)
	{
		this->VelocityFlipX();
		//debug.Log(0, SCREEN_BOTTOM - 40, " BallClass : ScreenRight HIT", 0xffffffff);
	}
	if (now_pos.y - (r) < SCREEN_TOP)
	{
		this->VelocityFlipY();
		//debug.Log(0, SCREEN_BOTTOM - 40, " BallClass : ScreenTop HIT", 0xffffffff);
	}
	if (now_pos.y + (r) > SCREEN_BOTTOM)
	{
		this->VelocityFlipY();
		//debug.Log(0, SCREEN_BOTTOM - 40, " BallClass : ScreenBottom HIT", 0xffffffff);
	}

	this->MovePos();
}

void Ball::VelocityFlipX()
{
	Vector2 vel = this->GetVelocity();
	vel.x *= (-1);
	this->SetVelocity(vel);
}
void Ball::VelocityFlipY()
{
	Vector2 vel = this->GetVelocity();
	vel.y *= (-1);
	this->SetVelocity(vel);
}