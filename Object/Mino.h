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
	// �~�m�̃����_������
	void makeMino();
	// �~�m�̕`��
	void drawMino();
	// �~�m�̗���
	void fallMino();

	// �~�m�̃X�e�[�W�̒��̍��W
	int m_minoX;	// X���W
	int m_minoY;	// Y���W

	// �~�m�̗�������t���[����Y���W
	float m_minoFlameY;
	//�~�m������Ă��邩�ǂ������ׂ�
	bool m_makeMinoFlag;



	// �~�m�̎��
	int m_minoId;
	// �~�m�̔z���ۑ�
	int m_minoSave[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	// �~�m���~������C���^�[�o��
	int m_dropInterval;
};