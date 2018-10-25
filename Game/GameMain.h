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

// クラスの定義 ============================================================

// <ゲーム> ------------------------------------------------------------
class Game
{
	// データメンバの宣言
private:
	InputManager* input;
	Player* player;

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
