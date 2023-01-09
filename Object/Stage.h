// ステージ
#pragma once
#include "common.h"

class Stage
{
public:
	Stage();
	virtual ~Stage();

	// 初期化
	void init();
	// 終了処理
	void end();
	// 描画処理
	void draw();
	// ステージの描画
	void drawStage();

	// ステージの配列
	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];
	
private:
	// 背景のハンドル
	int m_backHandle;
};

