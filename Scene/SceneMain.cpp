#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
//#include "Mino.h"
//#include "Stage.h"

SceneMain::SceneMain() :
	block_x(0),
	block_y(0),
	block_y_count(0),
	block_speed(0),
	collision_flag(0),
	gameover_flag(0),
	make_block_flag(0),
	back_img1(-1)
{
	//m_pMino = new Mino;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			block[y][x] = 0;
		}
	}
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			stage[y][x] = 0;
		}
	}
}

SceneMain::~SceneMain()
{
	//delete m_pMino;
}

// 初期化
void SceneMain::init()
{
	//m_pMino->init();
	my_init_var();
}

// 終了処理
void SceneMain::end()
{
	//m_pMino->end();
}

// 更新処理
SceneBase* SceneMain::update()
{
	//m_pMino->update();
	//m_pMino->hitTop();
	/*if (m_pMino->getGameOver())
	{
		return (new SceneResult);
	}*/

	// 仮の関数配列
	
	my_make_block();
	my_gameover();
	my_move_block();
	my_draw_back();
	my_draw_variable();
	my_draw_block();
	my_draw_stage();
	my_fix_block();
	my_fall_block();

	if (gameover_flag == 1)
	{
		my_draw_back();
		my_draw_block();
		my_draw_stage();
		my_ed();
	}

	/*if (block_y_count > DRAW_BLOCK_WIDTH * 17) {
		block_y_count = 0;
		block_y = 0;
	}*/

	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// 描画処理
void SceneMain::draw()
{
	//DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	/*m_pMino->my_make_block();
	m_pMino->draw();*/
}

// 初期化
void SceneMain::my_init_var()
{
	for (int i = 0; i < STAGE_HEIGHT; i++) {
		for (int j = 0; j < STAGE_WIDTH; j++) {
			stage[i][0] = 9;
			stage[i][1] = 9;
			stage[i][2] = 9;
			stage[20][j] = 9;
			stage[21][j] = 9;
			stage[22][j] = 9;
			stage[i][15] = 9;
			stage[i][16] = 9;
			stage[i][17] = 9;
		}
	}

	block_x = 7;
	block_y = 0;
	block_y_count = 0;
	block_speed = 0.5f;
	collision_flag = 0;
	gameover_flag = 0;
	make_block_flag = 1;

	back_img1 = LoadGraph("data/back2.jpg");
}

// 二個目以降の初期化
void SceneMain::my_init_var2()
{
	block_x = 7;
	block_y = 0;
	block_y_count = 0;
	make_block_flag = 1;
}

// ゲームオーバーロゴ
void SceneMain::my_ed()
{
	DrawFormatString(400, 400, kColor::Color_Black, "GAME OVER");
}

// ミノの生成
void SceneMain::my_make_block()
{
	if (make_block_flag == 1)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++) {
			for (int x = 0; x < BLOCK_WIDTH; x++) {
				block[y][x] = kMino::blocks[y][x];
			}
		}
		make_block_flag = 0;
	}
}

// ゲームオーバー判定
void SceneMain::my_gameover()
{
	my_collision_center();

	if (collision_flag != 0) {
		gameover_flag = 1;
	}
}

// ミノの操作
void SceneMain::my_move_block()
{
	// 左
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		my_collision_left();
		if (collision_flag == 0) 
		{
			block_x--;
		}
	}
	// 右
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		my_collision_right();
		if (collision_flag == 0) {
			block_x++;
		}
	}
	// 急降下
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		my_collision_bottom();
		if (collision_flag == 0) {
			block_y++;
			block_y_count = block_y * DRAW_BLOCK_WIDTH;
		}
	}
}

// 左の当たり判定
void SceneMain::my_collision_left()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[block_y + y][block_x + (x - 1)] != 0) {
					collision_flag = 1;
				}
				else if ((int)(block_y_count - (block_y * DRAW_BLOCK_WIDTH)) > 0) {
					if (stage[block_y + (y + 1)][block_x + (x - 1)] != 0) {
						collision_flag = 1;
					}
				}
			}
		}
	}
}

// 右の当たり判定
void SceneMain::my_collision_right()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[block_y + y][block_x + (x + 1)] != 0) {
					collision_flag = 1;
				}
				else if ((int)(block_y_count - (block_y * DRAW_BLOCK_WIDTH)) > 0) {
					if (stage[block_y + (y + 1)][block_x + (x + 1)] != 0) {
						collision_flag = 1;
					}
				}
			}
		}
	}
}

// 地面の当たり判定
void SceneMain::my_collision_bottom()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[block_y + (y + 1)][block_x + x] != 0) {
					collision_flag = 1;
				}
			}
		}
	}
}

// 天井の当たり判定
void SceneMain::my_collision_center()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[block_y + y][block_x + x] != 0) {
					collision_flag = 1;
				}
			}
		}
	}
}

// ミノが地面についた時の処理
void SceneMain::my_fix_block()
{
	my_collision_bottom();

	if (collision_flag != 0) {
		my_save_block();
		my_init_var2();
	}
}

// ミノの配列をステージの配列に固定
void SceneMain::my_save_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			stage[block_y + y][block_x + x] += block[y][x];
		}
	}
}

// 背景追加
void SceneMain::my_draw_back()
{
	DrawGraph(0, 0, back_img1, TRUE);
}

// 変数確認用描画処理
void SceneMain::my_draw_variable()
{
	DrawFormatString(400, 400, kColor::Color_Black, "block_x = %d", block_x);
	DrawFormatString(400, 420, kColor::Color_Black, "block_y = %d", block_y);
	DrawFormatString(400, 440, kColor::Color_Black, "block_y_count = %f", block_y_count);
}

// ミノの描画処理
void SceneMain::my_draw_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (block[y][x] == 1)DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
				block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
		}
	}
}

// ステージの描画処理
void SceneMain::my_draw_stage()
{
	for (int y = 0; y < STAGE_HEIGHT - 2; y++)
	{
		for (int x = 2; x < STAGE_WIDTH - 2; x++)
		{
			if (stage[y][x] == 1)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
			}
			else if (stage[y][x] == 2)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "■");
			}
			else if (stage[y][x] == 9)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "■");
			}
		}
	}
}

// ミノがまだ地面についていない時の処理
void SceneMain::my_fall_block()
{
	if (make_block_flag == 0)
	{
		block_y_count += block_speed;
		block_y = block_y_count / DRAW_BLOCK_WIDTH;
	}
}
