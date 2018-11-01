#include "Player.h"
#include "Debug.h"

#include "Input.h"

static const float PLAYER_SPEED = 8.0f;

Player::Player(Vector2 initpos)
{
	Vector2 isize;
	static int gh = 0;

	isize.Set(100, 10);

	if (gh == 0)
	{
		gh = MakeScreen(INT_CAST isize.x, INT_CAST isize.y);
		SetDrawScreen(gh);
		DrawBox(0, 0, 100, 10, COLOR_WHITE, TRUE);
		SetDrawScreen(DX_SCREEN_BACK);
	}

	this->SetAliveFlag(true);
	this->SetSprite(&gh, initpos, isize, 1.0f);
	this->SetPosition(initpos);

}


Player::~Player()
{

}


void Player::Update(InputManager* input)
{
	Debug debug;

	Vector2 vel = { 0.0f, 0.0f };
	Vector2 buf = { 0.0f, 0.0f };

	/*Vector2 mpos = input->mouse->GetPosition();
	this->SetPosition(mpos);*/

	if (input->key->GetNow(KEY_INPUT_LEFT))
	{
		buf.Set(-PLAYER_SPEED, 0.0f);
		vel = vel.Add(&buf);
		debug.Log(0, SCREEN_BOTTOM - 20, " PlayerClass : ©‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}
	if (input->key->GetNow(KEY_INPUT_RIGHT))
	{
		buf.Set(PLAYER_SPEED, 0.0f);
		vel = vel.Add(&buf);
		debug.Log(0, SCREEN_BOTTOM - 20, " PlayerClass : ¨‰Ÿ‚³‚ê‚Ä‚¢‚Ü‚·", 0xffffffff);
	}

	this->SetVelocity(vel);
	this->MovePos(); 
	this->Clamp(SCREEN_RIGHT, SCREEN_LEFT, SCREEN_BOTTOM, SCREEN_TOP);

}

void Player::AutoPlay(GameObject* ball)
{
	float pleft, pright;
	float bleft, bright;
	pleft = this->GetPosition().x - this->GetHitSizeV().x / 2;
	pright = this->GetPosition().x + this->GetHitSizeV().x / 2;

	bleft = ball->GetPosition().x - ball->GetHitSizeV().x / 2;
	bright = ball->GetPosition().x + ball->GetHitSizeV().x / 2;


	Vector2 vel = { 0,0 };
	if (pleft > bleft)
	{
		vel.x = -PLAYER_SPEED;
	}
	else if (pright < bright)
	{
		vel.x = PLAYER_SPEED;
	}

	this->SetVelocity(vel);
	this->MovePos();
}