#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

// <システム> ----------------------------------------------------------
const char* const GAME_TITLE = "Sample Game";    // ゲームタイトル

#define EXTENDS :
#define extends :

// <画面> --------------------------------------------------------------
const int SCREEN_WIDTH = 640;    // 画面の幅[pixel]
const int SCREEN_HEIGHT = 480;    // 画面の高さ[pixel]

const int SCREEN_TOP = 0;                    // 画面の上端
const int SCREEN_BOTTOM = SCREEN_HEIGHT;        // 画面の下端
const int SCREEN_LEFT = 0;                    // 画面の左端
const int SCREEN_RIGHT = SCREEN_WIDTH;         // 画面の右端

const int SCREEN_CENTER_X = SCREEN_WIDTH / 2;    // 画面の中央(X座標)
const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;    // 画面の中央(Y座標)

// <Game Screen>
const int GAME_SCREEN_WIDTH = (SCREEN_WIDTH / 2);
const int GAME_SCREEN_HEIGHT = (480);
const int GAME_SCREEN_TOP = (0);
const int GAME_SCREEN_BOTTOM = (GAME_SCREEN_HEIGHT);
const int GAME_SCREEN_LEFT = (0);
const int GAME_SCREEN_RIGHT = (GAME_SCREEN_WIDTH);
const int GAME_SCREEN_CENTER_X = (GAME_SCREEN_WIDTH / 2);
const int GAME_SCREEN_CENTER_Y = (GAME_SCREEN_HEIGHT / 2);


//メッセージボックス
#define MSG(m)	{	MessageBox(NULL,m,"Message Info",MB_OK);}
#define EXIT	{	MSG("ゲームを終了します") PostQuitMessage(0);}

#define DEG_TO_RAD(DEG)	((DEG) * (M_PI / 180.0))
#define RAD_TO_DEG(RAD)	((RAD) * (180.0 / M_PI))