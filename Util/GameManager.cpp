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
	m_speedUpIntervar(0),
	m_actionTime(0),
	m_level(0)
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

// ����������
void GameManager::init()
{
	m_gameoverFlag = false;
	m_collsionFlag = false;
	m_turnProvisional = 0;
	m_clearCount = 0;
	m_speedUpIntervar = 3;
	m_actionTime = 60;
	m_level = 0;
	m_backHandle = LoadGraph("data/back2.jpg");
	m_soundMove = LoadSoundMem("sound/move.mp3");
	ChangeVolumeSoundMem(150, m_soundMove);
	m_soundClear = LoadSoundMem("sound/clear1.mp3");
	ChangeVolumeSoundMem(255, m_soundClear);

	m_pMino->init();
	m_pStage->init();
}
// �I������
void GameManager::end()
{
	DeleteSoundMem(m_soundMove);
	DeleteSoundMem(m_soundClear);
	m_pStage->end();
}

// �X�V����
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
			m_pStage->drawStage();
			m_pMino->drawMino();
			dropPointMino();
			fixMino();
		}
		else if (m_clearFlag)
		{
			clearLine();
			drawBack();
			m_pStage->drawStage();
		}
	}
	// �Q�[���I�[�o�[�̏���
	else if (m_gameoverFlag)
	{
		drawBack();
		m_pMino->drawMino();
		m_pStage->drawStage();
	}
}

// ��ڈȍ~�̏�����
void GameManager::initScond()
{
	m_pMino->m_minoX = 4;
	m_pMino->m_minoY = 0;
	m_pMino->m_minoFlameY = 0;
	//m_pMino->m_firstMinoFlag = true;
	m_pMino->m_secondMinoFlag = true;
	m_turnProvisional = 0;
}

// �Q�[���I�[�o�[����
void GameManager::gameover()
{
	collisionOver();

	if (m_collsionFlag)
	{
		m_gameoverFlag = true;
	}
}

// *********************************************
// �����蔻��
// *********************************************
// ��
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
				else if ((int)(m_pMino->m_minoFlameY - (m_pMino->m_minoY * DRAW_BLOCK_WIDTH)) > 0) {
					if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + (x - 1)] != 0) {
						m_collsionFlag = 1;
					}
				}
			}
		}
	}
}

// �E
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
				else if ((int)(m_pMino->m_minoFlameY - (m_pMino->m_minoY * DRAW_BLOCK_WIDTH)) > 0) {
					if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + (x + 1)] != 0) {
						m_collsionFlag = 1;
					}
				}
			}
		}
	}
}

// �n��
void GameManager::collisionBottom()
{
	m_collsionFlag = false;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->m_minoSave[y][x] != 0 /*&& m_pMino->m_minoShade[y][x] != 0*/)
			{
				if (m_pStage->m_stage[m_pMino->m_minoY + (y + 1)][m_pMino->m_minoX + x] != 0 /*&& 
					m_pStage->m_stage[m_pMino->m_minoShadeY + (y + 1)][m_pMino->m_minoX + x] != 0*/)
				{
					m_collsionFlag = true;
				}
			}
		}
	}
}

// �V��
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

// ��]
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
// �����蔻��I��
// *********************************************

// �~�m�̉�]
// �~�m����]���������]���������蔻������
// �����ē������~�m�̔z��ɉ�]�����~�m��������
// �E��]
void GameManager::turnMino()
{
	m_turnProvisional++;

	// ��]�����z���ʂ̔z��ɕۑ�
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_turnMino[y][x] = kMino::minos[(m_pMino->m_secondId * BLOCK_HEIGHT) + y][(m_turnProvisional % 4 * BLOCK_WIDTH) + x];
		}
	}

	collisionTurn();

	//��]�����ۂɕǂɂ߂荞�ނ̂ł���Ή�]���Ȃ�
	if (!m_collsionFlag)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_pMino->m_minoSave[y][x] = m_turnMino[y][x];
				m_pMino->m_minoShade[y][x] = m_turnMino[y][x];
			}
		}
	}
	else
	{
		m_turnProvisional--;
	}
}

// �~�m�����������̏���
void GameManager::fixMino()
{
	collisionBottom();

	if (m_collsionFlag)
	{
		m_actionTime--;
		if (Pad::isTrigger(PAD_INPUT_UP))
		{
			m_actionTime = 0;
		}
		if (m_actionTime <= 0)
		{
			saveMino();
			searchLine();
			if (!m_clearFlag)
			{
				initScond();
			}
			m_actionTime = 60;
		}
	}
	else if (!m_collsionFlag)
	{
		m_pMino->fallMino();
		m_actionTime = 60;
	}
}

// �~�m�̑���
void GameManager::actionMino()
{
	// ��
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		collisionLeft();
		if (!m_collsionFlag)
		{
			PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
			m_pMino->m_minoX--;
		}
	}
	// �E
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		collisionRight();
		if (!m_collsionFlag)
		{
			PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
			m_pMino->m_minoX++;
		}
	}
	// �\�t�g�h���b�v
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		collisionBottom();
		if (!m_collsionFlag)
		{
			m_speedUpIntervar--;
			if (m_speedUpIntervar <= 0)
			{
				m_speedUpIntervar = 3;
				m_pMino->m_score++;
				PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
				m_pMino->m_minoY++;
				m_pMino->m_minoFlameY += DRAW_BLOCK_WIDTH;
			}
		}
	}

	// �~�m�̉�]
	if (Pad::isTrigger(PAD_INPUT_1) == 1)
	{
		PlaySoundMem(m_soundMove, DX_PLAYTYPE_BACK);
		turnMino();
	}

	// �n�[�h�h���b�v
	if (Pad::isTrigger(PAD_INPUT_UP) == 1)
	{
		hardDrop();
		
	}
}

void GameManager::hardDrop()
{
	m_pMino->m_score += 20;
	collisionBottom();
	while (!m_collsionFlag)
	{
		m_pMino->m_minoY++;
		m_pMino->m_minoFlameY += DRAW_BLOCK_WIDTH;
		collisionBottom();
	}
}

void GameManager::dropPointMino()
{
	/*collisionBottom();
	while (!m_collsionFlag)
	{
		m_pMino->m_minoShadeY++;
		m_pMino->m_minoShadeFY += DRAW_BLOCK_WIDTH;
		collisionBottom();
	}*/
}

// �~�m���X�e�[�W�̔z��ɕۑ�
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

// ��������𒲂ׂ�
// ����ɋ󔒂�����Ύ��̍s�𒲂ׂ�
void GameManager::searchLine()
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		m_clearMinoLine[i] = 1;
	}

	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		for (int j = 1; j < STAGE_WIDTH - 1; j++)
		{
			if (m_pStage->m_stage[i][j] == 0)
			{
				m_clearMinoLine[i] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		if (m_clearMinoLine[i] == 1)
		{
			m_clearFlag = true;
			m_pMino->m_score+=100;
		}
	}
}

// ��������̓���ւ�
// ���t���[������
void GameManager::clearLine()
{
	// �c���Ă����ׂ���̕ۑ�
	int clearPoint[20] = { 0 };
	// ���������̔z��
	int clearIndex = 0;

	if (m_clearCount < 10) 
	{
		// ���������𒲂ׂ�
		for (int i = 0; i < STAGE_HEIGHT - 1; i++)
		{
			if (m_clearMinoLine[i] == 1)
			{
				m_pStage->m_stage[i][m_clearCount + 1] = 0;
			}
		}
		
		m_clearCount++;
	}
	// ��������̓���ւ�
	else
	{
		// �c���ׂ���̕ۑ�
		for (int i = STAGE_HEIGHT - 2; i >= 0; i--)
		{
			if (m_clearMinoLine[i] != 1)
			{
				clearPoint[clearIndex] = i;
				clearIndex++;
			}
		}

		clearIndex = 0;
		// �ۑ����ꂽ��̓���ւ�
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

// �w�i
void GameManager::drawBack()
{
	DrawGraph(0, 0, m_backHandle, TRUE);
	DrawFormatString(430, 200, GetColor(0, 0, 0), "next");
	DrawBox(410, 220, 490, 280, GetColor(200, 200, 200), true);
	DrawBox(410, 220, 490, 280, GetColor(0, 0, 0), false);
	DrawFormatString(450, 400, GetColor(0, 0, 0), "�X�R�A�F%d", m_pMino->m_score, true);


	// �����艺�͊m�F�p�̕ϐ��\��
	//DrawFormatString(450, 450, GetColor(0, 0, 0), "%d", m_actionTime, true);
	//DrawFormatString(450, 500, GetColor(0, 0, 0), "%d", m_pMino->m_minoY, true);
	//DrawFormatString(450, 550, GetColor(0, 0, 0), "%d", m_pMino->m_minoFlameY, true);
}