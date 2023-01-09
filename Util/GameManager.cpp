#include "GameManager.h"
#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

GameManager::GameManager() :
	gameover_flag(0),
	collision_flag(0),
	turn_point(0) ,
	clear_count(0),
	clear_flag(0),
	back_img1(-1)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			turn_block[y][x] = 0;
		}
	}

	for (int y = 0; y < STAGE_HEIGHT - 1; y++)
	{
		clear_line_point[y] = 0;
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
	gameover_flag = 0;
	collision_flag = 0;
	turn_point = 0;
	clear_count = 0;
	back_img1 = LoadGraph("data/back2.jpg");

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
	if (clear_flag == 0)
	{
		m_pMino->my_make_block();
		my_gameover();
		my_move_block();
		my_draw_back();
		//my_draw_variable();
		m_pMino->my_draw_block();
		m_pStage->my_draw_stage();
		my_fix_block();
		m_pMino->my_fall_block();
	}
	else
	{
		my_clear_line();
		my_draw_back();
		//my_draw_variable();
		m_pStage->my_draw_stage();
	}
	// ƒQ[ƒ€ƒI[ƒo[‚Ìˆ—
	if (gameover_flag == 1)
	{
		my_draw_back();
		m_pMino->my_draw_block();
		m_pStage->my_draw_stage();
		my_ed();
		//return (new SceneResult);
	}
}

void GameManager::draw()
{
	//m_pMino->my_make_block();
}

void GameManager::my_init_var2()
{
	m_pMino->block_x = 5;
	m_pMino->block_y = -1;
	m_pMino->block_y_count = 0;
	m_pMino->make_block_flag = 1;
	turn_point = 0;
}

void GameManager::my_ed()
{
	DrawFormatString(400, 400, kColor::Color_Black, "GAME OVER");
}

void GameManager::my_gameover()
{
	my_collision_center();

	if (collision_flag != 0)
	{
		gameover_flag = 1;
	}
}

void GameManager::my_collision_left()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->block[y][x] != 0)
			{
				if (m_pStage->stage[m_pMino->block_y + y][m_pMino->block_x + (x - 1)] != 0)
				{
					collision_flag = 1;
				}
				else if ((int)(m_pMino->block_y_count - (m_pMino->block_y * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->stage[m_pMino->block_y + (y + 1)][m_pMino->block_x + (x - 1)] != 0)
					{
						collision_flag = 1;
					}
				}
			}
		}
	}
}

void GameManager::my_collision_right()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->block[y][x] != 0)
			{
				if (m_pStage->stage[m_pMino->block_y + y][m_pMino->block_x + (x + 1)] != 0)
				{
					collision_flag = 1;
				}
				else if ((int)(m_pMino->block_y_count - (m_pMino->block_y * DRAW_BLOCK_WIDTH)) > 0)
				{
					if (m_pStage->stage[m_pMino->block_y + (y + 1)][m_pMino->block_x + (x + 1)] != 0)
					{
						collision_flag = 1;
					}
				}
			}
		}
	}
}

void GameManager::my_collision_bottom()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->block[y][x] != 0)
			{
				if (m_pStage->stage[m_pMino->block_y + (y + 1)][m_pMino->block_x + x] != 0)
				{
					collision_flag = 1;
				}
			}
		}
	}
}

void GameManager::my_collision_center()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_pMino->block[y][x] != 0)
			{
				if (m_pStage->stage[m_pMino->block_y + y][m_pMino->block_x + x] != 0)
				{
					collision_flag = 1;
				}
			}
		}
	}
}

void GameManager::my_collision_turn()
{
	collision_flag = 0;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (turn_block[y][x] != 0)
			{
				if (m_pStage->stage[m_pMino->block_y + y][m_pMino->block_x + x] != 0)
				{
					collision_flag = 1;
				}
			}
		}
	}
}

void GameManager::my_turn_right()
{
	turn_point++;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			turn_block[y][x] = kMino::blocks[(m_pMino->block_id * BLOCK_HEIGHT) + y][(turn_point % 4 * BLOCK_WIDTH) + x];
		}
	}

	my_collision_turn();

	if (collision_flag == 0)
	{
		for (int y = 0; y < BLOCK_HEIGHT; y++)
		{
			for (int x = 0; x < BLOCK_WIDTH; x++)
			{
				m_pMino->block[y][x] = turn_block[y][x];
			}
		}
	}
	else
	{
		turn_point--;
	}
}

void GameManager::my_fix_block()
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

void GameManager::my_move_block()
{
	// ¶
	if (Pad::isTrigger(PAD_INPUT_LEFT) == 1)
	{
		my_collision_left();
		if (collision_flag == 0)
		{
			m_pMino->block_x--;
		}
	}
	// ‰E
	if (Pad::isTrigger(PAD_INPUT_RIGHT) == 1)
	{
		my_collision_right();
		if (collision_flag == 0)
		{
			m_pMino->block_x++;
		}
	}
	// ‹}~‰º
	if (Pad::isPress(PAD_INPUT_DOWN) == 1)
	{
		my_collision_bottom();
		if (collision_flag == 0)
		{
			m_pMino->block_y++;
			m_pMino->block_y_count += DRAW_BLOCK_WIDTH;
		}
	}

	// ƒ~ƒm‚Ì‰ñ“]
	if (Pad::isTrigger(PAD_INPUT_UP) == 1)
	{
		my_turn_right();
	}
}

void GameManager::my_save_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			m_pStage->stage[m_pMino->block_y + y][m_pMino->block_x + x] += m_pMino->block[y][x];
		}
	}
}

void GameManager::my_search_line()
{
	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		clear_line_point[i] = 0;
	}

	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		for (int j = 1; j < STAGE_WIDTH - 1; j++)
		{
			if (m_pStage->stage[i][j] == 0)
			{
				clear_line_point[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < STAGE_HEIGHT - 1; i++)
	{
		if (clear_line_point[i] == 0)
		{
			clear_flag = 1;
			break;
		}
	}
}

void GameManager::my_clear_line()
{
	int remain_line_point[20] = { 0 };
	int remain_line_index = 0;

	if (clear_count < 10) 
	{
		for (int i = 0; i < STAGE_HEIGHT - 1; i++)
		{
			if (clear_line_point[i] == 0)
			{
				m_pStage->stage[i][clear_count + 1] = 0;
			}
		}
		clear_count++;
	}
	else
	{
		for (int i = STAGE_HEIGHT - 2; i >= 0; i--)
		{
			if (clear_line_point[i] != 0)
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
				m_pStage->stage[y][x] = m_pStage->stage[remain_line_point[remain_line_index]][x];
			}
			remain_line_index++;
		}

		clear_flag = 0;
		clear_count = 0;
		my_init_var2();
	}
}

void GameManager::my_draw_back()
{
	DrawGraph(0, 0, back_img1, TRUE);
}

void GameManager::my_draw_variable()
{
	DrawFormatString(450, 400, kColor::Color_Black, "block_x = %d", m_pMino->block_x);
	DrawFormatString(450, 420, kColor::Color_Black, "block_y = %d", m_pMino->block_y);
	DrawFormatString(450, 440, kColor::Color_Black, "block_y_count = %f", m_pMino->block_y_count);
}
