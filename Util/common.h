// 共通
#pragma once
#include "DxLib.h"

// ミノの幅
#define BLOCK_HEIGHT 4		// 縦
#define BLOCK_WIDTH 4		// 横

// ミノの種類
#define BLOCK_TYPE 7
#define BLOCK_ROTATE_TYPE 4

// ステージの幅
#define STAGE_HEIGHT 21		// 縦
#define STAGE_WIDTH 12		// 横

// 描画するミノ同士の横幅
#define DRAW_BLOCK_WIDTH 15

// 描画する位置の変更
#define DRAW_POASTION_STAGE 200
#define DRAW_POASTION_MINO 200

// ミノの配列
namespace kMino
{
	constexpr int blocks[BLOCK_HEIGHT * BLOCK_TYPE][BLOCK_WIDTH * BLOCK_ROTATE_TYPE] = {
		// Oミノ	⇒これ以降は回転したミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Iミノ
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	2,2,2,2,	0,0,2,0},
		{2,2,2,2,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		// Sミノ
		{0,0,0,0,	3,0,0,0,	0,0,0,0,	0,3,0,0},
		{0,3,3,0,	3,3,0,0,	0,3,3,0,	0,3,3,0},
		{3,3,0,0,	0,3,0,0,	3,3,0,0,	0,0,3,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Zミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{4,4,0,0,	0,4,0,0,	4,4,0,0,	0,0,4,0},
		{0,4,4,0,	4,4,0,0,	0,4,4,0,	0,4,4,0},
		{0,0,0,0,	4,0,0,0,	0,0,0,0,	0,4,0,0},
		// Jミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{5,0,0,0,	0,5,5,0,	0,0,0,0,	0,5,0,0},
		{5,5,5,0,	0,5,0,0,	5,5,5,0,	0,5,0,0},
		{0,0,0,0,	0,5,0,0,	0,0,5,0,	5,5,0,0},
		// Lミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,0,6,0,	0,6,0,0,	0,0,0,0,	6,6,0,0},
		{6,6,6,0,	0,6,0,0,	6,6,6,0,	0,6,0,0},
		{0,0,0,0,	0,6,6,0,	6,0,0,0,	0,6,0,0},
		// Tミノ
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,7,0,0,	0,7,0,0,	0,0,0,0,	0,7,0,0},
		{7,7,7,0,	0,7,7,0,	7,7,7,0,	7,7,0,0},
		{0,0,0,0,	0,7,0,0,	0,7,0,0,	0,7,0,0},
	};
}

// 色
namespace kColor
{
	// ミノ
	const int Color_Yellow = GetColor(255, 255, 0);		// 黄O
	const int Color_LightBlue = GetColor(0, 0, 120);	// 水I
	const int Color_Green = GetColor(0, 200, 0);		// 緑S
	const int Color_Red = GetColor(255, 0, 0);			// 赤Z
	const int Color_Blue = GetColor(0, 0, 255);			// 青J
	const int Color_Orange = GetColor(255, 120, 0);		// 橙L
	const int Color_Purple = GetColor(255, 0, 255);		// 紫T

	// ステージ
	const int Color_Black = GetColor(0, 0, 0);			// 黒
}

// フェード処理関係
namespace kFade
{
	// フェード
	constexpr int Bright = 0;		// 処理
	constexpr int Speed = 5;		// 速度
	// 描画輝度
	constexpr int RedBright = 255;		// 赤
	constexpr int GreenBright = 255;	// 緑
	constexpr int BlueBright = 255;		// 青
}