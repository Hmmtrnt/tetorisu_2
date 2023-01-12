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
	// �ŏ��ɐ��������~�m�����ꂽ���ǂ����̃t���O
	bool m_firstMinoFlag;
	// ���삷��~�m�̍��ꂽ���ǂ����̃t���O
	bool m_secondMinoFlag;


	// �T���ɂ���~�m�̎��
	int m_firstId;
	// ���쒆�~�m�̎��
	int m_secondId;
	// �~�m�̔z���ۑ�
	int m_minoSave[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ���ɗ����Ă���~�m�̔z��̕ۑ�
	int m_minoNext[BLOCK_HEIGHT][BLOCK_WIDTH];

private:
	// �~�m���~������C���^�[�o��
	int m_dropInterval;

	// ����ꏄ�t���O
	/*bool m_OMinoFlag;
	bool m_IMinoFlag;
	bool m_SMinoFlag;
	bool m_ZMinoFlag;
	bool m_JMinoFlag;
	bool m_LMinoFlag;
	bool m_TMinoFlag;*/

};