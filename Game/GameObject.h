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
	bool alive;			// 存在しているかどうか
	int state;			// オブジェクトの状態

	Vector2 position;	// 中心座標
	Vector2 velocity;	// 移動速度の大きさ
	Vector2 speed;		// 移動方向

	Sprite sprite;		// スプライト
	Color color;		// 色

	float rad_vel;		// 回転速度
	float rotate;		// 回転
	float scale;		// 拡大率

	Vector2 hitsize;		// 当たり判定用 / 矩形
	float r;			// 当たり判定用 / 円形

	int cnt;			// カウント用

public:
	GameObject();	// コンストラクタ
	~GameObject();	// デストラクタ
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
