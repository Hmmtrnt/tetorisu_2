// �X�e�[�W
#pragma once
#include "common.h"

class Stage
{
public:
	Stage();
	virtual ~Stage();

	// ������
	void init();
	// �I������
	void end();
	// �`�揈��
	void draw();
	// �X�e�[�W�̕`��
	void drawStage();

	// �X�e�[�W�̔z��
	int m_stage[STAGE_HEIGHT][STAGE_WIDTH];
	
private:
	// �w�i�̃n���h��
	int m_backHandle;
};

