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
	my_init_var();
	my_make_block();
	my_draw_back();
	my_draw_variable();
	my_draw_block();
	my_draw_stage();

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

	back_img1 = LoadGraph("data/back2.jpg");
}

void SceneMain::my_make_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			block[y][x] = kMino::blocks[y][x];
		}
	}
}

void SceneMain::my_draw_back()
{
	DrawGraph(0, 0, back_img1, TRUE);

}

void SceneMain::my_draw_variable()
{
	DrawFormatString(400, 400, kColor::Color_Black, "block_x = %d", block_x);
	DrawFormatString(400, 420, kColor::Color_Black, "block_y = %d", block_y);
	DrawFormatString(400, 440, kColor::Color_Black, "block_y_count = %f", block_y_count);
}

void SceneMain::my_draw_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] == 1)DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
				block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
		}
	}
}

void SceneMain::my_draw_stage()
{
	for (int y = 0; y < STAGE_HEIGHT; y++) {
		for (int x = 0; x < STAGE_WIDTH; x++) {
			if (stage[y][x] == 1)DrawFormatString(x * DRAW_BLOCK_WIDTH,
				y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
			else if (stage[y][x] == 9)DrawFormatString(x * DRAW_BLOCK_WIDTH,
				y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "■");
		}
	}
}
