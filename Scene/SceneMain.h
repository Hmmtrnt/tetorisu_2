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

	// 仮の関数
	void my_init_var();
	void my_init_var2();
	void my_ed();
	void my_make_block();
	void my_gameover();
	void my_turn_right();
	void my_move_block();
	void my_collision_left();
	void my_collision_right();
	void my_collision_bottom();
	void my_collision_center();
	void my_collision_turn();
	void my_fix_block();
	void my_search_line();
	void my_clear_line();
	void my_save_block();
	void my_draw_back();
	void my_draw_variable();
	void my_draw_block();
	void my_draw_stage();
	void my_fall_block();

private:
	//Mino* m_pMino;

	int block[BLOCK_HEIGHT][BLOCK_WIDTH];
	int turn_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	int stage[STAGE_HEIGHT][STAGE_WIDTH];

	int clear_line_point[STAGE_HEIGHT - 1];

	int block_x;
	int block_y;
	float block_y_count;
	float block_speed;
	int collision_flag;
	int gameover_flag;
	int make_block_flag;
	int clear_flag;
	int block_id;
	int clear_count;
	int turn_point;

	int back_img1;

};