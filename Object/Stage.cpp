#include "Stage.h"

Stage::Stage() :
	m_backHandle(-1)
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			stage[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::init()
{
	for (int y = 0; y < STAGE_HEIGHT; y++) {
		for (int x = 0; x < STAGE_WIDTH; x++) {
			stage[y][0] = 9;
			stage[y][11] = 9;
			stage[20][x] = 9;
		}
	}

	
	// �w�i�̃n���h��
	m_backHandle = LoadGraph("data/back2.jpg");
}

void Stage::end()
{
	DeleteGraph(m_backHandle);
}

void Stage::update()
{
}

void Stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	my_draw_stage();
}

//void Stage::my_draw_back()
//{
//	DrawGraph(0, 0, m_backHandle, TRUE);
//}

void Stage::my_draw_stage()
{
	//my_draw_back();
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
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


