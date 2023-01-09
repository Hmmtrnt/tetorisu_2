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
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画
	void draw();

	// 仮の関数
	
	void my_make_block();
	void my_draw_block();
	void my_fall_block();

	int block_x;
	int block_y;
	float block_y_count;
	int make_block_flag;
	int block_id;
	int block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	float block_speed;
	// ミノが降下するインターバル
	int m_dropInterval;
};