// �X�e�[�W
#pragma once
#include "common.h"

class Stage
{
public:
	Stage();
	virtual ~Stage();

	// ����������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();
	// �`�揈��
	void draw();

	// ���̊֐�
	
	//void my_draw_back();
	void my_draw_stage();

	// �X�e�[�W�̔z��
	int stage[STAGE_HEIGHT][STAGE_WIDTH];

	

private:
	// �w�i�̃n���h��
	int m_backHandle;
};

