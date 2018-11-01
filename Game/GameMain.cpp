//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "Debug.h"
#include "Player.h"
#include "Input.h"
#include "Ball.h"
#include "Block.h"



// <Gameクラス> ****************************************************************

// メンバ関数の定義 ========================================================
//------------------------------------------------------------------
//! @brief デフォルトコンストラクタ
//!
//! @param[in] なし
//------------------------------------------------------------------
Game::Game()
{
	this->input = new InputManager;
	this->player = new Player({ FLOAT_CAST SCREEN_CENTER_X,FLOAT_CAST(SCREEN_CENTER_Y + SCREEN_CENTER_Y / 2) });
	this->ball = new Ball(10.0f, { 5.0f,5.0f });

	const float bw = SCREEN_WIDTH / BLOCK_NUM_X;
	const float bh = bw / 4;
	
	int num = 0;
	int colornum = 0;

	for (int i = 0; i < BLOCK_NUM; i++)
	{
		Vector2 pos;
		pos.y = (bh) + (FLOAT_CAST(i / BLOCK_NUM_X) * FLOAT_CAST(BLOCK_NUM_Y)) * 6.0f;
		pos.x = bw * FLOAT_CAST(i % BLOCK_NUM_X + 1) - bw / 2;

		if (((i / BLOCK_NUM_X)) > num)
		{
			num += 1;
			colornum += 1;
			if (colornum > 2)
			{
				colornum = 0;
			}
		}

		this->block[i] = new Block(pos, { bw,bh }, color_list[colornum]);
	}
}


//------------------------------------------------------------------
//! @brief デストラクタ
//------------------------------------------------------------------
Game::~Game()
{
	delete this->input;
	delete this->player;
	delete this->ball;

	for (int i = 0; i < BLOCK_NUM; i++)
	{
		delete block[i];
	}
	//	delete[] block;

}



//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Initialize(void)
{
	SetWindowSizeChangeEnableFlag(TRUE);
}

bool BoxCollision(Vector2 a1, Vector2 a2, Vector2 b1, Vector2 b2)
{
	float ax1 = a1.x;
	float ay1 = a1.y;
	float ax2 = a2.x;
	float ay2 = a2.y;

	float bx1 = b1.x;
	float by1 = b1.y;
	float bx2 = b2.x;
	float by2 = b2.y;

#if defined(_DEBUG)
	//DrawBox(INT_CAST ax1, INT_CAST ay1, INT_CAST ax2, INT_CAST ay2, COLOR_RED, FALSE);
	//DrawBox(INT_CAST bx1, INT_CAST by1, INT_CAST bx2, INT_CAST by2, COLOR_RED, FALSE);
#endif

	if ((bx1 < ax2) && (by1 < ay2) && (bx2 > ax1) && (by2 > ay1))
	{
		return true;
	}
	return false;
}


//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Update(void)
{
	input->Update();
	//player->Update(input);
	player->AutoPlay(ball);
	ball->Update();

	{
		Vector2 p1, p2, p3, p4;
		p1 = player->GetPosition().Sub(&player->GetHitSizeV().Div(2.0f));
		p4 = player->GetPosition().Add(&player->GetHitSizeV().Div(2.0f));
		p2 = p1;	p2.x = p4.x;
		p3 = p4;	p3.x = p1.x;

		Vector2 b1, b4;
		b1 = ball->GetPosition().Sub(&ball->GetHitSizeV().Div(2.0f));
		b4 = ball->GetPosition().Add(&ball->GetHitSizeV().Div(2.0f));

		{
			Vector2 oldballpos = ball->GetPosition().Sub(&ball->GetVelocity());

			if (BoxCollision(p1, p2, b1, b4))
			{
				if (ball->GetVelocity().y > 0)
				{
					ball->VelocityFlipY();
				}
				ball->SetPosition(oldballpos);
			}
			else if (BoxCollision(p1, p3, b1, b4))
			{
				if (ball->GetVelocity().x > 0)
				{
					ball->VelocityFlipX();
				}
				ball->SetPosition(oldballpos);
			}
			else if (BoxCollision(p2, p4, b1, b4))
			{
				if (ball->GetVelocity().x < 0)
				{
					ball->VelocityFlipX();
				}
				ball->SetPosition(oldballpos);
			}
			else if (BoxCollision(p3, p4, b1, b4))
			{
				if (ball->GetVelocity().y < 0)
				{
					ball->VelocityFlipY();
				}
				ball->SetPosition(oldballpos);
			}
		}
	}

	{
		Vector2 oldballpos = ball->GetPosition().Sub(&ball->GetVelocity());

		Vector2 b1, b4;
		b1 = ball->GetPosition().Sub(&ball->GetHitSizeV().Div(2.0f));
		b4 = ball->GetPosition().Add(&ball->GetHitSizeV().Div(2.0f));

		for (int i = 0; i < BLOCK_NUM; i++)
		{
			if (block[i]->GetFlag())
			{
				Vector2 p1, p2, p3, p4;
				p1 = block[i]->GetPosition().Sub(&block[i]->GetHitSizeV().Div(2.0f));
				p4 = block[i]->GetPosition().Add(&block[i]->GetHitSizeV().Div(2.0f));
				p2 = p1;	p2.x = p4.x;
				p3 = p4;	p3.x = p1.x;

				if (BoxCollision(p1, p2, b1, b4))
				{
					if (ball->GetVelocity().y > 0)
					{
						ball->VelocityFlipY();
					}
					ball->SetPosition(oldballpos);
					block[i]->SetFlag(false);
				}
				else if (BoxCollision(p1, p3, b1, b4))
				{
					if (ball->GetVelocity().x > 0)
					{
						ball->VelocityFlipX();
					}
					ball->SetPosition(oldballpos);
					block[i]->SetFlag(false);
				}
				else if (BoxCollision(p2, p4, b1, b4))
				{
					if (ball->GetVelocity().x < 0)
					{
						ball->VelocityFlipX();
					}
					ball->SetPosition(oldballpos);
					block[i]->SetFlag(false);
				}
				else if (BoxCollision(p3, p4, b1, b4))
				{
					if (ball->GetVelocity().y < 0)
					{
						ball->VelocityFlipY();
					}
					ball->SetPosition(oldballpos);
					block[i]->SetFlag(false);
				}
			}
		}
	}
}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Render(void)
{
	player->Render();
	ball->Render();

	for (int i = 0; i < BLOCK_NUM; i++)
	{
		if (block[i]->GetFlag())
		{
			block[i]->Render();
		}
	}
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Finalize(void)
{

}
