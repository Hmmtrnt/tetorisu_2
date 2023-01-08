// テトリスの進行管理
#pragma once
#include "common.h"

class Mino;
class Stage;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// 初期化処理
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画処理
	void draw();

	// 仮の関数
	void my_init_var2();
	void my_ed();
	void my_gameover();
	void my_collision_left();
	void my_collision_right();
	void my_collision_bottom();
	void my_collision_center();
	void my_collision_turn();
	void my_turn_right();
	void my_fix_block();
	void my_move_block();
	void my_save_block();
	void my_search_line();
	void my_clear_line();
	void my_draw_back();
	void my_draw_variable();

	int gameover_flag;

private:

	
	int collision_flag;
	int turn_point;
	int turn_block[BLOCK_HEIGHT][BLOCK_WIDTH];
	int clear_line_point[STAGE_HEIGHT - 1];
	int clear_count;
	int clear_flag;

	int back_img1;

	// ミノとステージのポインタ
	Mino*	m_pMino;
	Stage*	m_pStage;
};