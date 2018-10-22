#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

// <�V�X�e��> ----------------------------------------------------------
const char* const GAME_TITLE = "Sample Game";    // �Q�[���^�C�g��

#define EXTENDS :
#define extends :

// <���> --------------------------------------------------------------
const int SCREEN_WIDTH = 640;    // ��ʂ̕�[pixel]
const int SCREEN_HEIGHT = 480;    // ��ʂ̍���[pixel]

const int SCREEN_TOP = 0;                    // ��ʂ̏�[
const int SCREEN_BOTTOM = SCREEN_HEIGHT;        // ��ʂ̉��[
const int SCREEN_LEFT = 0;                    // ��ʂ̍��[
const int SCREEN_RIGHT = SCREEN_WIDTH;         // ��ʂ̉E�[

const int SCREEN_CENTER_X = SCREEN_WIDTH / 2;    // ��ʂ̒���(X���W)
const int SCREEN_CENTER_Y = SCREEN_HEIGHT / 2;    // ��ʂ̒���(Y���W)

// <Game Screen>
const int GAME_SCREEN_WIDTH = (SCREEN_WIDTH / 2);
const int GAME_SCREEN_HEIGHT = (480);
const int GAME_SCREEN_TOP = (0);
const int GAME_SCREEN_BOTTOM = (GAME_SCREEN_HEIGHT);
const int GAME_SCREEN_LEFT = (0);
const int GAME_SCREEN_RIGHT = (GAME_SCREEN_WIDTH);
const int GAME_SCREEN_CENTER_X = (GAME_SCREEN_WIDTH / 2);
const int GAME_SCREEN_CENTER_Y = (GAME_SCREEN_HEIGHT / 2);


//���b�Z�[�W�{�b�N�X
#define MSG(m)	{	MessageBox(NULL,m,"Message Info",MB_OK);}
#define EXIT	{	MSG("�Q�[�����I�����܂�") PostQuitMessage(0);}

#define DEG_TO_RAD(DEG)	((DEG) * (M_PI / 180.0))
#define RAD_TO_DEG(RAD)	((RAD) * (180.0 / M_PI))