#include "Stage.h"

Stage::Stage() :
	m_backHandle(-1)
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stage[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

// ������
void Stage::init()
{
	for (int y = 0; y < STAGE_HEIGHT; y++) {
		for (int x = 0; x < STAGE_WIDTH; x++) {
			m_stage[y][0] = 9;
			m_stage[y][11] = 9;
			m_stage[20][x] = 9;
		}
	}

	
	// �w�i�̃n���h��
	m_backHandle = LoadGraph("data/back2.jpg");
}

// �I������
void Stage::end()
{
	DeleteGraph(m_backHandle);
}

// �`�揈��
void Stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	drawStage();
}

// �X�e�[�W�̕`��
void Stage::drawStage()
{
	//my_draw_back();
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			// O�~�m
			if (m_stage[y][x] == 1)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "��");
			}
			// I�~�m
			else if (m_stage[y][x] == 2)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "��");
			}
			// S�~�m
			else if (m_stage[y][x] == 3)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "��");
			}
			// Z�~�m
			else if (m_stage[y][x] == 4)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "��");
			}
			// J�~�m
			else if (m_stage[y][x] == 5)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "��");
			}
			// L�~�m
			else if (m_stage[y][x] == 6)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "��");
			}
			// T�~�m
			else if (m_stage[y][x] == 7)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "��");
			}
			// �X�e�[�W
			else if (m_stage[y][x] == 9)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "��");
			}
		}
	}
}