// ¤Ê
#pragma once
#include "DxLib.h"

// ~mÌ
#define BLOCK_HEIGHT 4		// c
#define BLOCK_WIDTH 4		// Ħ

// ~mÌíŜ
#define BLOCK_TYPE 7
#define BLOCK_ROTATE_TYPE 4

// Xe[WÌ
#define STAGE_HEIGHT 21		// c
#define STAGE_WIDTH 12		// Ħ

// `ĉ·é~mŻmÌĦ
#define DRAW_BLOCK_WIDTH 15

// `ĉ·éÊuÌÏX
#define DRAW_POASTION_STAGE 200		// Xe[W
#define DRAW_POASTION_MINO 200		// ~m

// ~mÌzñ
namespace kMino
{
	constexpr int minos[BLOCK_HEIGHT * BLOCK_TYPE][BLOCK_WIDTH * BLOCK_ROTATE_TYPE] = {
		// O~m	ËħêÈ~Íñ]µ½~m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,1,1,0,	0,1,1,0,	0,1,1,0,	0,1,1,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// I~m
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	2,2,2,2,	0,0,2,0},
		{2,2,2,2,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		{0,0,0,0,	0,2,0,0,	0,0,0,0,	0,0,2,0},
		// S~m
		{0,0,0,0,	3,0,0,0,	0,0,0,0,	0,3,0,0},
		{0,3,3,0,	3,3,0,0,	0,3,3,0,	0,3,3,0},
		{3,3,0,0,	0,3,0,0,	3,3,0,0,	0,0,3,0},
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		// Z~m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{4,4,0,0,	0,4,0,0,	4,4,0,0,	0,0,4,0},
		{0,4,4,0,	4,4,0,0,	0,4,4,0,	0,4,4,0},
		{0,0,0,0,	4,0,0,0,	0,0,0,0,	0,4,0,0},
		// J~m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{5,0,0,0,	0,5,5,0,	0,0,0,0,	0,5,0,0},
		{5,5,5,0,	0,5,0,0,	5,5,5,0,	0,5,0,0},
		{0,0,0,0,	0,5,0,0,	0,0,5,0,	5,5,0,0},
		// L~m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,0,6,0,	0,6,0,0,	0,0,0,0,	6,6,0,0},
		{6,6,6,0,	0,6,0,0,	6,6,6,0,	0,6,0,0},
		{0,0,0,0,	0,6,6,0,	6,0,0,0,	0,6,0,0},
		// T~m
		{0,0,0,0,	0,0,0,0,	0,0,0,0,	0,0,0,0},
		{0,7,0,0,	0,7,0,0,	0,0,0,0,	0,7,0,0},
		{7,7,7,0,	0,7,7,0,	7,7,7,0,	7,7,0,0},
		{0,0,0,0,	0,7,0,0,	0,7,0,0,	0,7,0,0},
	};
}

// F
namespace kColor
{
	// ~m
	const int Color_Yellow = GetColor(255, 255, 0);		// İO
	const int Color_LightBlue = GetColor(0, 0, 120);	// I
	const int Color_Green = GetColor(0, 200, 0);		// ÎS
	const int Color_Red = GetColor(255, 0, 0);			// ÔZ
	const int Color_Blue = GetColor(0, 0, 255);			// ÂJ
	const int Color_Orange = GetColor(255, 120, 0);		// òL
	const int Color_Purple = GetColor(255, 0, 255);		// T

	// Xe[W
	const int Color_Black = GetColor(0, 0, 0);			// 
}

// tF[hÖW
namespace kFade
{
	// tF[h
	constexpr int Bright = 0;		// 
	constexpr int Speed = 5;		// Ĵx
	// `ĉPx
	constexpr int RedBright = 255;		// Ô
	constexpr int GreenBright = 255;	// Î
	constexpr int BlueBright = 255;		// Â
}