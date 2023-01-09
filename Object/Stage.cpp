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

// ‰Šú‰»
void Stage::init()
{
	for (int y = 0; y < STAGE_HEIGHT; y++) {
		for (int x = 0; x < STAGE_WIDTH; x++) {
			m_stage[y][0] = 9;
			m_stage[y][11] = 9;
			m_stage[20][x] = 9;
		}
	}

	
	// ”wŒi‚Ìƒnƒ“ƒhƒ‹
	m_backHandle = LoadGraph("data/back2.jpg");
}

// I—¹ˆ—
void Stage::end()
{
	DeleteGraph(m_backHandle);
}

// •`‰æˆ—
void Stage::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	drawStage();
}

// ƒXƒe[ƒW‚Ì•`‰æ
void Stage::drawStage()
{
	//my_draw_back();
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			// Oƒ~ƒm
			if (m_stage[y][x] == 1)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "¡");
			}
			// Iƒ~ƒm
			else if (m_stage[y][x] == 2)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "¡");
			}
			// Sƒ~ƒm
			else if (m_stage[y][x] == 3)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "¡");
			}
			// Zƒ~ƒm
			else if (m_stage[y][x] == 4)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "¡");
			}
			// Jƒ~ƒm
			else if (m_stage[y][x] == 5)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "¡");
			}
			// Lƒ~ƒm
			else if (m_stage[y][x] == 6)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "¡");
			}
			// Tƒ~ƒm
			else if (m_stage[y][x] == 7)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "¡");
			}
			// ƒXƒe[ƒW
			else if (m_stage[y][x] == 9)
			{
				DrawFormatString(DRAW_POASTION_STAGE + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_STAGE + y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "¡");
			}
		}
	}
}