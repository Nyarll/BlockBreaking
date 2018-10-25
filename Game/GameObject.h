#pragma once

#include "Define.h"
#include "Vector.h"

typedef struct
{
	HGRP texture;
	Vector2 pos;
	Vector2 size;
	float rota;
	float scale;
} Sprite;

// <Color>
typedef struct
{
	int r, g, b;
} Color;

class GameObject
{
private:
	bool alive;			// ���݂��Ă��邩�ǂ���
	int state;			// �I�u�W�F�N�g�̏��

	Vector2 position;	// ���S���W
	Vector2 velocity;	// �ړ����x�̑傫��
	Vector2 speed;		// �ړ�����

	Sprite sprite;		// �X�v���C�g
	Color color;		// �F

	float rad_vel;		// ��]���x
	float rotate;		// ��]
	float scale;		// �g�嗦

	Vector2 hitsize;		// �����蔻��p / ��`
	float r;			// �����蔻��p / �~�`

	int cnt;			// �J�E���g�p

public:
	GameObject();	// �R���X�g���N�^
	~GameObject();	// �f�X�g���N�^
	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	void SetVelocity(Vector2 vel);
	void SetSpeed(Vector2 spd);
	void SetSprite(int* graph_handle, Vector2 pos, Vector2 size, float scale = 1.0f);
	void GameObjectRotate(float rad);

	void MovePos();
	void Render();

	bool GetAliveFlag();
	void SetAliveFlag(bool flag);

	bool CircleCollision(const GameObject obj);
	bool BoxCollision(const GameObject obj);
};
