// ����
#pragma once
#include "DxLib.h"

#define BLOCK_HEIGHT 4
#define BLOCK_WIDTH 4

#define STAGE_HEIGHT 23
#define STAGE_WIDTH 18

#define DRAW_BLOCK_WIDTH 20

namespace kMino
{
	constexpr int blocks[BLOCK_HEIGHT][BLOCK_WIDTH] = {
		{0,0,0,0},
		{0,1,1,0},
		{0,1,1,0},
		{0,0,0,0}
	};
}

namespace kColor
{
	// �~�m
	const int Color_Yellow = GetColor(255, 255, 0);		// ��O
	const int Color_LightBlue = GetColor(0, 0, 120);	// ��I
	const int Color_Green = GetColor(0, 200, 0);		// ��S
	const int Color_Red = GetColor(255, 0, 0);			// ��Z
	const int Color_Blue = GetColor(0, 0, 255);			// ��J
	const int Color_Orange = GetColor(255, 120, 0);		// ��L
	const int Color_Purple = GetColor(255, 0, 255);		// ��T

	// �X�e�[�W
	const int Color_Black = GetColor(0, 0, 0);			// ��
}