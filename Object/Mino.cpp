#include "Mino.h"
#include "Pad.h"
#include <time.h>

Mino::Mino() :
	m_minoX(0),
	m_minoY(0),
	m_minoFlameY(0),
	m_firstMinoFlag(false),
	m_secondMinoFlag(false),
	m_firstId(0),
	m_secondId(0),
	m_dropInterval(0)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_minoSave[y][x] = 0;
		}
	}

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_minoNext[y][x] = 0;
		}
	}
}

Mino::~Mino()
{
}

// 初期化
void Mino::init()
{
	m_minoX = 4;
	m_minoY = 0;
	m_minoFlameY = 0;
	m_firstMinoFlag = true;
	m_secondMinoFlag = true;
	m_firstId = 0;
	m_secondId = 0;
	m_dropInterval = 70;

	srand((unsigned)time(NULL));
}

// ミノのランダム生成
void Mino::makeMino()
{
	// 1番最初のミノ
	if (m_firstMinoFlag)
	{
		m_firstId = (rand() % BLOCK_TYPE);
		// ミノの保存
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_minoNext[y][x] = kMino::minos[(m_firstId * BLOCK_HEIGHT) + y][x];
			}
		}

		m_firstMinoFlag = false;
	}

	// 2個目以降のミノ
	if (m_secondMinoFlag)
	{
		m_secondId = m_firstId;
		m_firstId = (rand() % BLOCK_TYPE);
		// 次に落ちてくるミノのを操作可能にする保存
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_minoSave[y][x] = m_minoNext[y][x];
				m_minoNext[y][x] = kMino::minos[(m_firstId * BLOCK_HEIGHT) + y][x];
			}
		}
		m_secondMinoFlag = false;
	}
}

// ミノの描画
void Mino::drawMino()
{
	// 次に落ちてくるミノの描画
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// Oミノ
			if (m_minoNext[y][x] == 1)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "■");
			}
			// Iミノ
			else if (m_minoNext[y][x] == 2)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "■");
			}
			// Sミノ
			else if (m_minoNext[y][x] == 3)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "■");
			}
			// Zミノ
			else if (m_minoNext[y][x] == 4)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
			}
			// Jミノ
			else if (m_minoNext[y][x] == 5)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "■");
			}
			// Lミノ
			else if (m_minoNext[y][x] == 6)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "■");
			}
			// Tミノ
			else if (m_minoNext[y][x] == 7)
			{
				DrawFormatString(DRAW_POASTION_MINO + 15 * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + 15 + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "■");
			}
		}
	}

	// 現在落ちてくるミノの描画
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// Oミノ
			if (m_minoSave[y][x] == 1)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "■");
			}
			// Iミノ
			else if (m_minoSave[y][x] == 2)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "■");
			}
			// Sミノ
			else if (m_minoSave[y][x] == 3)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "■");
			}
			// Zミノ
			else if (m_minoSave[y][x] == 4)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
			}
			// Jミノ
			else if (m_minoSave[y][x] == 5)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "■");
			}
			// Lミノ
			else if (m_minoSave[y][x] == 6)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "■");
			}
			// Tミノ
			else if (m_minoSave[y][x] == 7)
			{
				DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)m_minoFlameY + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "■");
			}
		}
	}
}

// ミノの落下
void Mino::fallMino()
{
	if (!m_secondMinoFlag)
	{
		m_dropInterval--;
		if (m_dropInterval <= 0)
		{
			m_dropInterval = 70;
			m_minoFlameY += DRAW_BLOCK_WIDTH;
			m_minoY++;
		}
	}
}
