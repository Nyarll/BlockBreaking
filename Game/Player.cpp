#include "Player.h"
#include "Debug.h"

Player::Player()
{
	key = new InputKeyBoard;

	Vector2 ipos, isize;
	int a = 0;
	ipos.Set((float)SCREEN_CENTER_X, (float)SCREEN_CENTER_Y);
	isize.Set(100, 100);
	this->SetAliveFlag(true);
	this->SetSprite(&a, ipos, isize, 1.0f);
	this->SetPosition(ipos);
}


Player::~Player()
{

}


void Player::Update()
{
	key->Update();
	Debug debug;

	Vector2 vel;
	Vector2 buf;
	buf.Set(0.0f, 0.0f);
	vel.Set(0.0f, 0.0f);


	/*GetMousePoint(&mx, &my);
	buf.Set((float)mx, (float)my);
	debug.Line(this->GetPosition(), buf, 0xffff0000);

	float rad = buf.Angle2(&this->GetPosition());
	vel.x = cosf(rad) * -2.0f;
	vel.y = sinf(rad) * -2.0f;*/

	if (key->GetNow(KEY_INPUT_UP))
	{
		buf.Set(0.0f, -2.0f);
		vel = vel.Add(&buf);
		debug.Log(0, 0, "ª‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}
	if (key->GetNow(KEY_INPUT_DOWN))
	{
		buf.Set(0.0f, 2.0f);
		vel = vel.Add(&buf);
		debug.Log(0, 0, "«‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}
	if (key->GetNow(KEY_INPUT_LEFT))
	{
		buf.Set(-2.0f, 0.0f);
		vel = vel.Add(&buf);
		debug.Log(0, 0, "©‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}
	if (key->GetNow(KEY_INPUT_RIGHT))
	{
		buf.Set(2.0f, 0.0f);
		vel = vel.Add(&buf);
		debug.Log(0, 0, "¨‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}



	this->SetVelocity(vel);
	this->MovePos();
}