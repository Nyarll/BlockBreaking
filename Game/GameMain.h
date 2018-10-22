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
#include "Player.h"

// �N���X�̒�` ============================================================

// <�Q�[��> ------------------------------------------------------------
class Game
{
	// �f�[�^�����o�̐錾
private:
	FrameTimer* frame_timer;
	Joypad* joy_pad;

	Player* player;

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
