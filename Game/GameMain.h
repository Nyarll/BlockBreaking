//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.h
//!
//! @brief  �Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

#include "Define.h"
//#include "Player.h"

class InputManager;
class Player;
class Ball;
class Block;

// �u���b�N�T�C�Y w = 640 / 8, h = w / 4,
const int BLOCK_NUM_X = 8;
const int BLOCK_NUM_Y = 6;
const int BLOCK_NUM = (BLOCK_NUM_X * BLOCK_NUM_Y);

const UINT color_list[3] = { 0xffff0000,0xff00ff00,0xff0000ff };

// �N���X�̒�` ============================================================

// <�Q�[��> ------------------------------------------------------------
class Game
{
	// �f�[�^�����o�̐錾
private:
	InputManager* input;
	Player* player;
	Ball* ball;
	Block* block[BLOCK_NUM];

	// �����o�֐��̐錾
public:
	// �R���X�g���N�^
	Game();

	// �f�X�g���N�^
	~Game();

public:
	// ����
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Finalize(void);
};
