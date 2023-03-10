#include "Mino.h"
#include "Pad.h"
#include <time.h>

Mino::Mino() :
	m_minoX(0),
	m_minoY(0),
	m_minoShadeX(0),
	m_minoShadeY(0),
	m_minoShadeFY(0),
	m_minoFlameY(0),
	m_firstMinoFlag(false),
	m_secondMinoFlag(false),
	m_score(0),
	m_firstId(0),
	m_secondId(0),
	m_dropInterval(0)/*,
	m_OMinoFlag(false),
	m_IMinoFlag(false),
	m_SMinoFlag(false),
	m_ZMinoFlag(false),
	m_JMinoFlag(false),
	m_LMinoFlag(false),
	m_TMinoFlag(false)*/

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

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_minoShade[y][x] = 0;
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
	m_minoShadeX = 0;
	m_minoShadeY = 0;
	m_minoShadeFY = 0;
	m_minoFlameY = 0;
	m_firstMinoFlag = true;
	m_secondMinoFlag = true;
	m_firstId = 0;
	m_secondId = 0;
	m_dropInterval = 70;
	m_score = 0;
	/*m_OMinoFlag = false;
	m_IMinoFlag = false;
	m_SMinoFlag = false;
	m_ZMinoFlag = false;
	m_JMinoFlag = false;
	m_LMinoFlag = false;
	m_TMinoFlag = false;*/


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
		/*if (m_firstId = 0)
		{
			m_OMinoFlag = true;
		}
		if (m_firstId = 1)
		{
			m_IMinoFlag = true;
		}
		if (m_firstId = 2)
		{
			m_SMinoFlag = true;
		}
		if (m_firstId = 3)
		{
			m_ZMinoFlag = true;
		}
		if (m_firstId = 4)
		{
			m_JMinoFlag = true;
		}
		if (m_firstId = 5)
		{
			m_LMinoFlag = true;
		}
		if (m_firstId = 6)
		{
			m_TMinoFlag = true;
		}*/

		m_firstMinoFlag = false;
	}

	// 2個目以降のミノ
	if (m_secondMinoFlag)
	{
		m_secondId = m_firstId;
		m_firstId = (rand() % BLOCK_TYPE);
		/*if (m_firstId = 0)
		{
			m_OMinoFlag = true;
		}
		if (m_firstId = 1)
		{
			m_IMinoFlag = true;
		}
		if (m_firstId = 2)
		{
			m_SMinoFlag = true;
		}
		if (m_firstId = 3)
		{
			m_ZMinoFlag = true;
		}
		if (m_firstId = 4)
		{
			m_JMinoFlag = true;
		}
		if (m_firstId = 5)
		{
			m_LMinoFlag = true;
		}
		if (m_firstId = 6)
		{
			m_TMinoFlag = true;
		}
		if (m_OMinoFlag)
		{
			while (m_firstId == 0)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_IMinoFlag)
		{
			while (m_firstId != 1)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_SMinoFlag)
		{
			while (m_firstId != 2)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_ZMinoFlag)
		{
			while (m_firstId != 3)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_JMinoFlag)
		{
			while (m_firstId != 4)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_LMinoFlag)
		{
			while (m_firstId != 5)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		if (m_TMinoFlag)
		{
			while (m_firstId != 0)
			{
				m_firstId = (rand() % BLOCK_TYPE);
			}
		}
		
		if (m_OMinoFlag && m_IMinoFlag && m_SMinoFlag && m_ZMinoFlag && m_JMinoFlag && m_LMinoFlag && m_TMinoFlag)
		{
			m_OMinoFlag = false;
			m_IMinoFlag = false;
			m_SMinoFlag = false;
			m_ZMinoFlag = false;
			m_JMinoFlag = false;
			m_LMinoFlag = false;
			m_TMinoFlag = false;

		}*/

		// 次に落ちてくるミノを操作可能、さらに次に現れるミノの表示
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_minoSave[y][x] = m_minoNext[y][x];
				m_minoShade[y][x] = m_minoNext[y][x];
				m_minoNext[y][x] = kMino::minos[(m_firstId * BLOCK_HEIGHT) + y][x];
			}
		}
		m_secondMinoFlag = false;
	}

	// 七種一巡


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

	// 現在落ちてくるミノの影の描画
	//for (int y = 0; y < BLOCK_HEIGHT; y++)
	//{
	//	for (int x = 0; x < BLOCK_WIDTH; x++)
	//	{
	//		// Oミノ
	//		if (m_minoShade[y][x] == 1)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "□");
	//		}
	//		// Iミノ
	//		else if (m_minoShade[y][x] == 2)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "□");
	//		}
	//		// Sミノ
	//		else if (m_minoShade[y][x] == 3)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "□");
	//		}
	//		// Zミノ
	//		else if (m_minoShade[y][x] == 4)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "□");
	//		}
	//		// Jミノ
	//		else if (m_minoShade[y][x] == 5)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "□");
	//		}
	//		// Lミノ
	//		else if (m_minoShade[y][x] == 6)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "□");
	//		}
	//		// Tミノ
	//		else if (m_minoShade[y][x] == 7)
	//		{
	//			DrawFormatString(DRAW_POASTION_MINO + m_minoX * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
	//				DRAW_POASTION_MINO + m_minoShadeFY + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "□");
	//		}
	//	}
	//}
}

// ミノの落下
void Mino::fallMino()
{
	if (!m_secondMinoFlag)
	{
		m_dropInterval--;
		if (m_dropInterval <= 0)
		{
			if (m_score >= 3000)
			{
				m_dropInterval = 40;
			}
			else if (m_score >= 2000)
			{
				m_dropInterval = 50;
			}
			else if (m_score >= 1000)
			{
				m_dropInterval = 60;
			}
			else if (m_score >= 0)
			{
				m_dropInterval = 70;
			}
			m_minoFlameY += DRAW_BLOCK_WIDTH;
			m_minoY++;
		}
	}
}
