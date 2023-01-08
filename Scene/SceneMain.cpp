#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include <time.h>
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
	clear_flag(0),
	block_id(0),
	clear_count(0),
	turn_point(0),
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

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			turn_block[y][x] = 0;
		}
	}

	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			stage[y][x] = 0;
		}
	}
	for (int y = 0; y < STAGE_HEIGHT - 3; y++)
	{
		clear_line_point[y] = 0;
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
	if (clear_flag == 0)
	{
		my_make_block();
		my_gameover();
		my_move_block();
		my_draw_back();
		my_draw_variable();
		my_draw_block();
		my_draw_stage();
		my_fix_block();
		my_fall_block();
	}
	else
	{
		my_clear_line();
		my_draw_back();
		my_draw_variable();
		my_draw_stage();
	}
	// �Q�[���I�[�o�[�̏���
	if (gameover_flag == 1)
	{
		/*my_draw_back();
		my_draw_block();
		my_draw_stage();
		my_ed();*/
		return (new SceneResult);
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

// �`�揈��
void SceneMain::draw()
{
	//DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	/*m_pMino->my_make_block();
	m_pMino->draw();*/
}

// ������
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
	block_id = 0;
	clear_count = 0;
	turn_point = 0;

	back_img1 = LoadGraph("data/back2.jpg");

	srand((unsigned)time(NULL));
}

// ��ڈȍ~�̏�����
void SceneMain::my_init_var2()
{
	block_x = 7;
	block_y = 0;
	block_y_count = 0;
	make_block_flag = 1;
	turn_point = 0;
}

// �Q�[���I�[�o�[���S
void SceneMain::my_ed()
{
	DrawFormatString(400, 400, kColor::Color_Black, "GAME OVER");
}

// �~�m�̐���
void SceneMain::my_make_block()
{
	if (make_block_flag == 1)
	{
		block_id = (rand() % BLOCK_TYPE);
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				block[y][x] = kMino::blocks[(block_id * BLOCK_HEIGHT) + y][x];
			}
		}
		make_block_flag = 0;
	}
}

// �Q�[���I�[�o�[����
void SceneMain::my_gameover()
{
	my_collision_center();

	if (collision_flag != 0)
	{
		gameover_flag = 1;
	}
}

// �~�m�̉�]
void SceneMain::my_turn_right()
{
	turn_point++;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			turn_block[y][x] =kMino::blocks[(block_id * BLOCK_HEIGHT) + y][(turn_point % 4 * BLOCK_WIDTH) + x];
		}
	}

	my_collision_turn();

	if (collision_flag == 0) {
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				block[y][x] = turn_block[y][x];
			}
		}
	}
	else {
		turn_point--;
	}
}

// �~�m�̑���
void SceneMain::my_move_block()
{
	// ��
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		my_collision_left();
		if (collision_flag == 0) 
		{
			block_x--;
		}
	}
	// �E
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		my_collision_right();
		if (collision_flag == 0)
		{
			block_x++;
		}
	}
	// �}�~��
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		my_collision_bottom();
		if (collision_flag == 0)
		{
			block_y++;
			block_y_count = (float)block_y * DRAW_BLOCK_WIDTH;
		}
	}
	// �~�m�̉�]
	if (Pad::isTrigger(PAD_INPUT_UP) == 1)
	{
		my_turn_right();
	}
}

// ���̓����蔻��
void SceneMain::my_collision_left()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (block[y][x] != 0)
			{
				if (stage[block_y + y][block_x + (x - 1)] != 0)
				{
					collision_flag = 1;
				}
				else if ((int)(block_y_count - (block_y * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (stage[block_y + (y + 1)][block_x + (x - 1)] != 0)
					{
						collision_flag = 1;
					}
				}
			}
		}
	}
}

// �E�̓����蔻��
void SceneMain::my_collision_right()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] != 0) {
				if (stage[block_y + y][block_x + (x + 1)] != 0)
				{
					collision_flag = 1;
				}
				else if ((int)(block_y_count - (block_y * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (stage[block_y + (y + 1)][block_x + (x + 1)] != 0)
					{
						collision_flag = 1;
					}
				}
			}
		}
	}
}

// �n�ʂ̓����蔻��
void SceneMain::my_collision_bottom()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (block[y][x] != 0)
			{
				if (stage[block_y + (y + 1)][block_x + x] != 0)
				{
					collision_flag = 1;
				}
			}
		}
	}
}

// �V��̓����蔻��
void SceneMain::my_collision_center()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (block[y][x] != 0)
			{
				if (stage[block_y + y][block_x + x] != 0)
				{
					collision_flag = 1;
				}
			}
		}
	}
}

void SceneMain::my_collision_turn()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (turn_block[y][x] != 0) {
				if (stage[block_y + y][block_x + x] != 0) {
					collision_flag = 1;
				}
			}
		}
	}
}

// �~�m���n�ʂɂ������̏���
void SceneMain::my_fix_block()
{
	my_collision_bottom();

	if (collision_flag != 0)
	{
		my_save_block();
		my_search_line();
		if (clear_flag == 0)
		{
			my_init_var2();
		}
	}
}

void SceneMain::my_search_line()
{
	for (int i = 0; i < STAGE_HEIGHT - 3; i++)
	{
		clear_line_point[i] = 0;
	}

	for (int i = 0; i < STAGE_HEIGHT - 3; i++)
	{
		for (int j = 3; j < STAGE_WIDTH - 3; j++)
		{
			if (stage[i][j] == 0)
			{
				clear_line_point[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < STAGE_HEIGHT - 3; i++)
	{
		if (clear_line_point[i] == 0)
		{
			clear_flag = 1;
			break;
		}
	}
}

void SceneMain::my_clear_line()
{
	int remain_line_point[20] = { 0 };
	int remain_line_index = 0;

	if (clear_count < 12) {
		for (int i = 0; i < STAGE_HEIGHT - 3; i++)
		{
			if (clear_line_point[i] == 0)
			{
				stage[i][clear_count + 3] = 0;
			}
		}
		clear_count++;
	}
	else {
		for (int i = STAGE_HEIGHT - 4; i >= 0; i--)
		{
			if (clear_line_point[i] != 0)
			{
				remain_line_point[remain_line_index] = i;
				remain_line_index++;
			}
		}

		remain_line_index = 0;
		for (int i = STAGE_HEIGHT - 4; i >= 0; i--)
		{
			for (int j = 3; j < STAGE_WIDTH - 3; j++)
			{
				stage[i][j] = stage[remain_line_point[remain_line_index]][j];
			}
			remain_line_index++;
		}

		clear_flag = 0;
		clear_count = 0;
		my_init_var2();
	}
}

// �~�m�̔z����X�e�[�W�̔z��ɌŒ�
void SceneMain::my_save_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			stage[block_y + y][block_x + x] += block[y][x];
		}
	}
}

// �w�i�`��
void SceneMain::my_draw_back()
{
	DrawGraph(0, 0, back_img1, TRUE);
}

// �ϐ��m�F�p�`�揈��
void SceneMain::my_draw_variable()
{
	DrawFormatString(400, 400, kColor::Color_Black, "block_x = %d", block_x);
	DrawFormatString(400, 420, kColor::Color_Black, "block_y = %d", block_y);
	DrawFormatString(400, 440, kColor::Color_Black, "block_y_count = %f", block_y_count);
}

// �~�m�̕`�揈��
void SceneMain::my_draw_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// O�~�m
			if (block[y][x] == 1)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "��");
			}
			// I�~�m
			else if (block[y][x] == 2)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "��");
			}
			// S�~�m
			else if (block[y][x] == 3)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "��");
			}
			// Z�~�m
			else if (block[y][x] == 4)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "��");
			}
			// J�~�m
			else if (block[y][x] == 5)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "��");
			}
			// L�~�m
			else if (block[y][x] == 6)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "��");
			}
			// T�~�m
			else if (block[y][x] == 7)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
								(int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "��");
			}
		}
	}
}

// �X�e�[�W�̕`�揈��
void SceneMain::my_draw_stage()
{
	for (int y = 0; y < STAGE_HEIGHT - 2; y++)
	{
		for (int x = 2; x < STAGE_WIDTH - 2; x++)
		{
			// O�~�m
			if (stage[y][x] == 1)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "��");
			}
			// I�~�m
			else if (stage[y][x] == 2)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "��");
			}
			// S�~�m
			else if (stage[y][x] == 3)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "��");
			}
			// Z�~�m
			else if (stage[y][x] == 4)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "��");
			}
			// J�~�m
			else if (stage[y][x] == 5)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "��");
			}
			// L�~�m
			else if (stage[y][x] == 6)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "��");
			}
			// T�~�m
			else if (stage[y][x] == 7)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "��");
			}
			// �X�e�[�W
			else if (stage[y][x] == 9)
			{
				DrawFormatString(x * DRAW_BLOCK_WIDTH,
								 y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "��");
			}
		}
	}
}

// �~�m���܂��n�ʂɂ��Ă��Ȃ����̏���
void SceneMain::my_fall_block()
{
	if (make_block_flag == 0)
	{
		block_y_count += block_speed;
		block_y = (int)block_y_count / DRAW_BLOCK_WIDTH;
	}
}
