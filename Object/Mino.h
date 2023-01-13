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

	// 操作できるミノのステージ内の座標
	int m_minoX;	// X座標
	int m_minoY;	// Y座標
	// ミノの落下地点のステージ内の座標
	int m_minoShadeX;
	int m_minoShadeY;
	// ミノの落下地点のフレーム座標
	int m_minoShadeFY;	// Y座標

	// ミノの落下するフレームのY座標
	float m_minoFlameY;
	// 最初に生成したミノが作られたかどうかのフラグ
	bool m_firstMinoFlag;
	// 操作するミノの作られたかどうかのフラグ
	bool m_secondMinoFlag;

	// スコア
	int m_score;

	// 控えにあるミノの種類
	int m_firstId;
	// 操作中ミノの種類
	int m_secondId;
	// ミノの配列を保存
	int m_minoSave[BLOCK_HEIGHT][BLOCK_WIDTH];
	// 次に落ちてくるミノの配列の保存
	int m_minoNext[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ミノの落下地点
	int m_minoShade[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ミノが降下するインターバル
	int m_dropInterval;

private:
	

	// 七種一巡フラグ
	/*bool m_OMinoFlag;
	bool m_IMinoFlag;
	bool m_SMinoFlag;
	bool m_ZMinoFlag;
	bool m_JMinoFlag;
	bool m_LMinoFlag;
	bool m_TMinoFlag;*/

};