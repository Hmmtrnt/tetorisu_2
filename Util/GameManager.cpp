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
	m_backHandle(-1),
	m_soundMove(0),
	m_soundClear(0),
	m_score(0)
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

// 初期化処理
void GameManager::init()
{
	m_gameoverFlag = false;
	m_collsionFlag = false;
	m_turnProvisional = 0;
	m_clearCount = 0;
	m_score = 0;
	m_backHandle = LoadGraph("data/back2.jpg");
	m_soundMove = LoadSoundMem("sound/move.mp3");
	ChangeVolumeSoundMem(150, m_soundMove);
	m_soundClear = LoadSoundMem("sound/clear1.mp3");
	ChangeVolumeSoundMem(255, m_soundClear);

	m_pMino->init();
	m_pStage->init();
}
// 終了処理
void GameManager::end()
{
	DeleteSoundMem(m_soundMove);
	DeleteSoundMem(m_soundClear);
	m_pStage->end();
}

// 更新処理
void GameManager::update()
{
	if (!m_gameoverFlag)
	{
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
		else if (m_clearFlag)
		{
			clearLine();
			drawBack();
			m_pStage->drawStage();
		}
	}
	// ゲームオーバーの処理
	else if (m_gameoverFlag)
	{
		drawBack();
		m_pMino->drawMino();
		m_pStage->drawStage();
	}
}

// 二個目以降の初期化
void GameManager::initScond()
{
	m_pMino->m_minoX = 5;
	m_pMino->m_minoY = -1;
	m_pMino->m_minoFlameY = 0;
	m_pMino->m_makeMinoFlag = true;
	m_turnProvisional = 0;
}

// ゲームオーバー判定
void GameManager::gameover()
{
	collisionOver();

	if (m_collsionFlag)
	{
		m_gameoverFlag = true;
	}
}

// *********************************************
// 当たり判定
// *********************************************
// 左
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

// 右
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

// 地面
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

// 天井
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

// 回転
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
// *********************************************
// 当たり判定終了
// *********************************************

// ミノの回転
// ミノを回転させた後回転した当たり判定を作る
// そして動かすミノの配列に回転したミノを代入する
// 右回転
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

// ミノが落ちた時の処理
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

// ミノの操作
void GameManager::actionMino()
{
	// 左
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		collisionLeft();
		if (!m_collsionFlag)
		{
			PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
			m_pMino->m_minoX--;
		}
	}
	// 右
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		collisionRight();
		if (!m_collsionFlag)
		{
			PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
			m_pMino->m_minoX++;
		}
	}
	// 急降下
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		collisionBottom();
		if (!m_collsionFlag)
		{
			PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
			m_pMino->m_minoY++;
			m_pMino->m_minoFlameY += DRAW_BLOCK_WIDTH;
		}
	}

	// ミノの回転
	if (Pad::isTrigger(PAD_INPUT_1) == 1)
	{
		PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
		turnMino();
	}
}

// ミノをステージの配列に保存
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

// 揃った列を調べる
// 横列に空白があれば次の行を調べる
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

// 揃った列の入れ替え
// 毎フレーム処理
void GameManager::clearLine()
{
	// 消去する列の保存
	int clearPoint[20] = { 0 };
	// 消去する列の配列
	int clearIndex = 0;

	if (m_clearCount < 10) 
	{
		// 消去する列を調べる
		for (int i = 0; i < STAGE_HEIGHT - 1; i++)
		{
			if (m_clearMinoLine[i] == 0)
			{
				m_pStage->m_stage[i][m_clearCount + 1] = 0;
			}
		}
		m_score += 1;
		m_clearCount++;
	}
	else
	{
		for (int i = STAGE_HEIGHT - 2; i >= 0; i--)
		{
			if (m_clearMinoLine[i] != 0)
			{
				clearPoint[clearIndex] = i;
				clearIndex++;
			}
		}

		clearIndex = 0;
		for (int y = STAGE_HEIGHT - 2; y >= 0; y--)
		{
			for (int x = 1; x < STAGE_WIDTH - 1; x++)
			{
				m_pStage->m_stage[y][x] = m_pStage->m_stage[clearPoint[clearIndex]][x];
			}
			clearIndex++;
		}
		PlaySoundMem(m_soundClear, DX_PLAYTYPE_BACK);

		m_clearFlag = false;
		m_clearCount = 0;
		initScond();
	}
}

// 背景
void GameManager::drawBack()
{
	DrawGraph(0, 0, m_backHandle, TRUE);
	DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", m_score, true);
}