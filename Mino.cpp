#include "Mino.h"
#include "common.h"

Mino::Mino()
{
}

Mino::~Mino()
{
}

void Mino::init()
{
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
	for (int y = 0; y < BLOCK_HEIGHT; y++) {
		for (int x = 0; x < BLOCK_WIDTH; x++) {
			block[y][x] = kMino::blocks[y][x];
		}
	}
}

// •Ï”Šm”F—p
void Mino::my_draw_variable()
{	
	DrawFormatString(400, 400, kColor::Color_Black, "block_x = %d", block_x);
	DrawFormatString(400, 420, kColor::Color_Black, "block_y = %d", block_y);
	DrawFormatString(400, 440, kColor::Color_Black, "block_y_count = %f", block_y_count);
}
