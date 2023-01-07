#include "Stage.h"
#include "common.h"

Stage::Stage() :
	m_backHandle(-1)
{
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_stageArray[y][x] = 0;
		}
	}
}

Stage::~Stage()
{
}

void Stage::init()
{
}

void Stage::end()
{
}

void Stage::update()
{
}

void Stage::draw()
{
}
