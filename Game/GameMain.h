//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  ゲーム関連のヘッダファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once

#include "Define.h"
//#include "Player.h"

class InputManager;
class Player;
class Ball;
class Block;

// ブロックサイズ w = 640 / 8, h = w / 4,
const int BLOCK_NUM_X = 8;
const int BLOCK_NUM_Y = 6;
const int BLOCK_NUM = (BLOCK_NUM_X * BLOCK_NUM_Y);

const UINT color_list[3] = { 0xffff0000,0xff00ff00,0xff0000ff };

// クラスの定義 ============================================================

// <ゲーム> ------------------------------------------------------------
class Game
{
	// データメンバの宣言
private:
	InputManager* input;
	Player* player;
	Ball* ball;
	Block* block[BLOCK_NUM];

	// メンバ関数の宣言
public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();

public:
	// 操作
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
