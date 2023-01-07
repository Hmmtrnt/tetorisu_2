//#include "Stage.h"
//
//Stage::Stage() :
//	m_backHandle(-1)
//{
//	for (int y = 0; y < STAGE_HEIGHT; y++)
//	{
//		for (int x = 0; x < STAGE_WIDTH; x++)
//		{
//			stage[y][x] = 0;
//		}
//	}
//}
//
//Stage::~Stage()
//{
//}
//
//void Stage::init()
//{
//	for (int i = 0; i < STAGE_HEIGHT; i++) {
//		for (int j = 0; j < STAGE_WIDTH; j++) {
//			stage[i][0] = 9;
//			stage[i][1] = 9;
//			stage[i][2] = 9;
//			stage[20][j] = 9;
//			stage[21][j] = 9;
//			stage[22][j] = 9;
//			stage[i][15] = 9;
//			stage[i][16] = 9;
//			stage[i][17] = 9;
//		}
//	}
//
//	// ”wŒi‚Ìƒnƒ“ƒhƒ‹
//	m_backHandle = LoadGraph("data/back2.jpg");
//}
//
//void Stage::end()
//{
//	DeleteGraph(m_backHandle);
//}
//
//void Stage::update()
//{
//}
//
//void Stage::draw()
//{
//	DrawGraph(0, 0, m_backHandle, true);
//	my_draw_stage();
//}
//
//void Stage::my_draw_stage()
//{
//	for (int y = 0; y < STAGE_HEIGHT; y++) {
//		for (int x = 0; x < STAGE_WIDTH; x++) {
//			if (stage[y][x] == 1)DrawFormatString(x * DRAW_BLOCK_WIDTH,
//				y * DRAW_BLOCK_WIDTH, kColor::Color_Red, "¡");
//			else if (stage[y][x] == 9)DrawFormatString(x * DRAW_BLOCK_WIDTH,
//				y * DRAW_BLOCK_WIDTH, kColor::Color_Black, "¡");
//		}
//	}
//}
