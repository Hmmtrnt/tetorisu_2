#include "Mino.h"
#include "Pad.h"
#include <time.h>

Mino::Mino() :
	block_x(0),
	block_y(0),
	block_y_count(0),
	make_block_flag(0),
	block_id(0),
	block_speed(0),
	m_dropInterval(0)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			block[y][x] = 0;
		}
	}

	
}

Mino::~Mino()
{
}

void Mino::init()
{
	block_x = 5;
	block_y = -1;
	block_y_count = 0;
	block_speed = 0.5f;
	make_block_flag = 1;
	block_id = 0;
	m_dropInterval = 70;

	srand((unsigned)time(NULL));
}

void Mino::end()
{
	
}

void Mino::update()
{
	
}

void Mino::draw()
{
	
}



void Mino::my_make_block()
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


void Mino::my_draw_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			// Oƒ~ƒm
			if (block[y][x] == 1)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Yellow, "¡");
			}
			// Iƒ~ƒm
			else if (block[y][x] == 2)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_LightBlue, "¡");
			}
			// Sƒ~ƒm
			else if (block[y][x] == 3)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Green, "¡");
			}
			// Zƒ~ƒm
			else if (block[y][x] == 4)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "¡");
			}
			// Jƒ~ƒm
			else if (block[y][x] == 5)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Blue, "¡");
			}
			// Lƒ~ƒm
			else if (block[y][x] == 6)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Orange, "¡");
			}
			// Tƒ~ƒm
			else if (block[y][x] == 7)
			{
				DrawFormatString(DRAW_POASTION_MINO + block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					DRAW_POASTION_MINO + (int)block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Purple, "¡");
			}
		}
	}
}

void Mino::my_fall_block()
{
	if (make_block_flag == 0)
	{
		m_dropInterval--;
		if (m_dropInterval <= 0)
		{
			m_dropInterval = 70;
			block_y_count += DRAW_BLOCK_WIDTH;
			block_y++;
		}
		//block_y_count += block_speed;
		//block_y = (int)block_y_count / DRAW_BLOCK_WIDTH;
	}
}
