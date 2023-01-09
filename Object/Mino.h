// ミノ
#pragma once
#include "common.h"

class Mino
{
public:
	Mino();
	virtual ~Mino();

	// 初期化
	void init();
	// ミノのランダム生成
	void makeMino();
	// ミノの描画
	void drawMino();
	// ミノの落下
	void fallMino();

	// ミノのステージの中の座標
	int m_minoX;	// X座標
	int m_minoY;	// Y座標

	// ミノの落下するフレームのY座標
	float m_minoFlameY;
	//ミノが作られているかどうか調べる
	bool m_makeMinoFlag;



	// ミノの種類
	int m_minoId;
	// ミノの配列を保存
	int m_minoSave[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	// ミノが降下するインターバル
	int m_dropInterval;
};