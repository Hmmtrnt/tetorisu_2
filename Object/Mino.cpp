#include "Mino.h"
#include "Stage.h"
#include "Pad.h"

Mino::Mino() :
	block_x(0),
	block_y(0),
	block_y_count(0)
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			block[y][x] = 0;
		}
	}
	m_pStage = new Stage;
}

Mino::~Mino()
{
	delete m_pStage;
}

void Mino::init()
{
	block_x = 7;
	block_y = 0;
	block_y_count = 0;

	m_pStage->init();
}

void Mino::end()
{
	m_pStage->end();
}

void Mino::update()
{
	m_pStage->update();
}

void Mino::draw()
{
	// ステージ描画
	m_pStage->draw();
}

void Mino::my_make_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) 
	{
		for (int x = 0; x < BLOCK_WIDTH; x++) 
		{
			block[y][x] = kMino::blocks[y][x];
		}
	}
}

void Mino::my_draw_variable()
{
	DrawFormatString(400, 400, kColor::Color_Black, "block_x = %d", block_x);
	DrawFormatString(400, 420, kColor::Color_Black, "block_y = %d", block_y);
	DrawFormatString(400, 440, kColor::Color_Black, "block_y_count = %f", block_y_count);
}

void Mino::my_draw_block()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			if (block[y][x] == 1)
			{
				DrawFormatString(block_x * DRAW_BLOCK_WIDTH + x * DRAW_BLOCK_WIDTH,
					block_y_count + y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "■");
			}
		}
	}
}
