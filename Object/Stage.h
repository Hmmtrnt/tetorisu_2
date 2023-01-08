// ステージ
#pragma once
#include "common.h"

class Stage
{
public:
	Stage();
	virtual ~Stage();

	// 初期化処理
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画処理
	void draw();

	// 仮の関数
	
	//void my_draw_back();
	void my_draw_stage();

	// ステージの配列
	int stage[STAGE_HEIGHT][STAGE_WIDTH];

	

private:
	// 背景のハンドル
	int m_backHandle;
};

