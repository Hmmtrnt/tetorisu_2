// �~�m
#pragma once
#include "common.h"

class Mino
{
public:
	Mino();
	virtual ~Mino();

	// ������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`��
	void draw();

	// ���̊֐�
	
	void my_make_block();
	void my_draw_block();
	void my_fall_block();

	int block_x;
	int block_y;
	float block_y_count;
	int make_block_flag;
	int block_id;
	int block[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	float block_speed;
	// �~�m���~������C���^�[�o��
	int m_dropInterval;
};