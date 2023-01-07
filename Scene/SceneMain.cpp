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

// ������
void SceneMain::init()
{
	//m_pMino->init();
	my_init_var();
}

// �I������
void SceneMain::end()
{
	//m_pMino->end();
}

// �X�V����
SceneBase* SceneMain::update()
{
	//m_pMino->update();
	//m_pMino->hitTop();
	/*if (m_pMino->getGameOver())
	{
		return (new SceneResult);
	}*/

	// ���̊֐��z��
	
	my_make_block();
	my_move_block();
	my_draw_back();
	my_draw_variable();
	my_draw_block();
	my_draw_stage();
	my_fall_block();

	if (block_y_count > DRAW_BLOCK_WIDTH * 17) {
		block_y_count = 0;
		block_y = 0;
	}

	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// �`�揈��
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
	block_speed = 0.5f;
	collision_flag = 0;

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

void SceneMain::my_move_block()
{
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		my_collision_left();
		if (collision_flag == 0) 
		{
			block_x--;
		}
	}
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		my_collision_right();
		if (collision_flag == 0) {
			block_x++;
		}
	}
}

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
				block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "��");
		}
	}
}

void SceneMain::my_draw_stage()
{
	for (int y = 0; y < STAGE_HEIGHT; y++) {
		for (int x = 0; x < STAGE_WIDTH; x++) {
			if (stage[y][x] == 1)DrawFormatString(x * DRAW_BLOCK_WIDTH,
				y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "��");
			else if (stage[y][x] == 9)DrawFormatString(x * DRAW_BLOCK_WIDTH,
				y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "��");
		}
	}
}

void SceneMain::my_fall_block()
{
	block_y_count += block_speed;
	block_y = block_y_count / DRAW_BLOCK_WIDTH;
}
