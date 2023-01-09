#include "GameManager.h"
#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

GameManager::GameManager() :
	m_gameoverFlag(false),
	m_collsionFlag(false),
	m_turnProvisional(0) ,
	m_clearCount(0),
	m_clearFlag(false),
	m_backHandle(-1)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_turnMino[y][x] = 0;
		}
	}

	for (int y = 0; y < STAGE_HEIGHT - 1; y++)
	{
		m_clearMinoLine[y] = 0;
	}

	m_pMino = new Mino;
	m_pStage = new Stage;
}

GameManager::~GameManager()
{
	delete m_pMino;
	delete m_pStage;
}

void GameManager::init()
{
	m_gameoverFlag = false;
	m_collsionFlag = false;
	m_turnProvisional = 0;
	m_clearCount = 0;
	m_backHandle = LoadGraph("data/back2.jpg");

	m_pMino->init();
	m_pStage->init();
}

void GameManager::end()
{
	m_pStage->end();
}

void GameManager::update()
{
	// ‰¼‚ÌŠÖ””z—ñ
	if (!m_clearFlag)
	{
		m_pMino->makeMino();
		gameover();
		actionMino();
		drawBack();
		m_pMino->drawMino();
		m_pStage->drawStage();
		fixMino();
		m_pMino->fallMino();
	}
	else
	{
		clearLine();
		drawBack();
		m_pStage->drawStage();
	}
	// ƒQ[ƒ€ƒI[ƒo[‚Ìˆ—
	if (m_gameoverFlag)
	{
		drawBack();
		m_pMino->drawMino();
		m_pStage->drawStage();
		//return (new SceneResult);
	}
}

void GameManager::initScond()
{
	m_pMino->m_minoX = 5;
	m_pMino->m_minoY = -1;
	m_pMino->m_minoFlameY = 0;
	m_pMino->m_makeMinoFlag = true;
	m_turnProvisional = 0;
}

void GameManager::gameover()
{
	collisionOver();

	if (m_collsionFlag)
	{
		m_gameoverFlag = true;
	}
}

void GameManager::collisionLeft()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_minoSave[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + y][m_pMino->m_minoX + (x - 1)] != 0)
				{
					m_collsionFlag = true;
				}
				else if ((int)(m_pMino->m_minoFlameY - (m_pMino->m_minoY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + (x - 1)] != 0)
					{
						m_collsionFlag = true;
					}
				}
			}
		}
	}
}

void GameManager::collisionRight()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_minoSave[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + y][m_pMino->m_minoX + (x + 1)] != 0)
				{
					m_collsionFlag = true;
				}
				else if ((int)(m_pMino->m_minoFlameY - (m_pMino->m_minoY * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + (x + 1)] != 0)
					{
						m_collsionFlag = true;
					}
				}
			}
		}
	}
}

void GameManager::collisionBottom()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_minoSave[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + x] != 0)
				{
					m_collsionFlag = true;
				}
			}
		}
	}
}

void GameManager::collisionOver()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_minoSave[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + y][m_pMino->m_minoX + x] != 0)
				{
					m_collsionFlag = true;
				}
			}
		}
	}
}

void GameManager::collisionTurn()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_turnMino[y][x] != 0)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + y][m_pMino->m_minoX + x] != 0)
				{
					m_collsionFlag = true;
				}
			}
		}
	}
}

void GameManager::turnMino()
{
	m_turnProvisional++;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_turnMino[y][x] = kMino::blocks[(m_pMino->m_minoId * BLOCK_HEIGHT) + y][(m_turnProvisional % 4 * BLOCK_WIDTH) + x];
		}
	}

	collisionTurn();

	if (!m_collsionFlag)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_pMino->m_minoSave[y][x] = m_turnMino[y][x];
			}
		}
	}
	else
	{
		m_turnProvisional--;
	}
}

void GameManager::fixMino()
{
	collisionBottom();

	if (m_collsionFlag)
	{
		saveMino();
		searchLine();
		if (!m_clearFlag)
		{
			initScond();
		}
	}
}

void GameManager::actionMino()
{
	// ¶
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		collisionLeft();
		if (!m_collsionFlag)
		{
			m_pMino->m_minoX--;
		}
	}
	// ‰E
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		collisionRight();
		if (!m_collsionFlag)
		{
			m_pMino->m_minoX++;
		}
	}
	// ‹}~‰º
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		collisionBottom();
		if (!m_collsionFlag)
		{
			m_pMino->m_minoY++;
			m_pMino->m_minoFlameY += DRAW_BLOCK_WIDTH;
		}
	}

	// ƒ~ƒm‚Ì‰ñ“]
	if (Pad::isTrigger(PAD_INPUT_UP) == 1)
	{
		turnMino();
	}
}

void GameManager::saveMino()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_pStage->m_stage[m_pMino->m_minoY + y][m_pMino->m_minoX + x] += m_pMino->m_minoSave[y][x];
		}
	}
}

void GameManager::searchLine()
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		m_clearMinoLine[i] = 0;
	}

	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		for (int j = 1; j < STAGE_WIDTH - 1; j++)
		{
			if (m_pStage->m_stage[i][j] == 0)
			{
				m_clearMinoLine[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		if (m_clearMinoLine[i] == 0)
		{
			m_clearFlag = true;
			break;
		}
	}
}

void GameManager::clearLine()
{
	int remain_line_point[20] = { 0 };
	int remain_line_index = 0;

	if (m_clearCount < 10) 
	{
		for (int i = 0; i < STAGE_HEIGHT - 1; i++)
		{
			if (m_clearMinoLine[i] == 0)
			{
				m_pStage->m_stage[i][m_clearCount + 1] = 0;
			}
		}
		m_clearCount++;
	}
	else
	{
		for (int i = STAGE_HEIGHT - 2; i >= 0; i--)
		{
			if (m_clearMinoLine[i] != 0)
			{
				remain_line_point[remain_line_index] = i;
				remain_line_index++;
			}
		}

		remain_line_index = 0;
		for (int y = STAGE_HEIGHT - 2; y >= 0; y--)
		{
			for (int x = 1; x < STAGE_WIDTH - 1; x++)
			{
				m_pStage->m_stage[y][x] = m_pStage->m_stage[remain_line_point[remain_line_index]][x];
			}
			remain_line_index++;
		}

		m_clearFlag = false;
		m_clearCount = 0;
		initScond();
	}
}

void GameManager::drawBack()
{
	DrawGraph(0, 0, m_backHandle, TRUE);
}