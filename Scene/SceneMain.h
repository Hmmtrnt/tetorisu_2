// メイン画面
#pragma once
#include "SceneBase.h"
#include "common.h"

//class Mino;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画処理

	void my_init_var();
	void my_make_block();
	void my_draw_back();
	void my_draw_variable();
	void my_draw_block();
	void my_draw_stage();

private:
	//Mino* m_pMino;

	int block[BLOCK_HEIGHT][BLOCK_WIDTH];
	int stage[STAGE_HEIGHT][STAGE_WIDTH];

	int block_x;
	int block_y;
	float block_y_count;

	int back_img1;

};