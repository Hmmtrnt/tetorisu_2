// �e�g���X�̐i�s�Ǘ�
#pragma once
#include "common.h"

class Mino;
class Stage;

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// ����������
	void init();
	// �I������
	void end();
	// �X�V����
	void update();

	// ��ڈȍ~�̏�����
	void initScond();
	// �Q�[���I�[�o�[����
	void gameover();
	// �����蔻��
	void collisionLeft();		// ��
	void collisionRight();		// �E
	void collisionBottom();		// �n��
	void collisionOver();		// �V��
	void collisionTurn();		// ��]
	// �~�m�̉�]
	void turnMino();
	// �~�m�����������̏���
	void fixMino();
	// �~�m�̑���
	void actionMino();
	// �n�[�h�h���b�v
	void hardDrop();
	// �~�m�̗����n�_
	void dropPointMino();
	// �~�m���X�e�[�W�̔z��ɕۑ�
	void saveMino();
	// ��������𒲂ׂ�
	void searchLine();
	// ��������̓���ւ�
	void clearLine();
	// �w�i
	void drawBack();

	// �Q�[���I�[�o�[�ɂȂ������ǂ���
	bool m_gameoverFlag;

private:

	// �ǂ̔���t���O
	bool m_collsionFlag;
	// ��]��̃~�m�����
	int m_turnProvisional;
	// ��]�����~�m��ۑ�
	int m_turnMino[BLOCK_HEIGHT][BLOCK_WIDTH];
	// ��������~�m
	int m_clearMinoLine[STAGE_HEIGHT - 1];
	// ����������̐�
	int m_clearCount;
	// �u���b�N�������Ă��邩�ǂ���
	bool m_clearFlag;
	// �w�i�n���h��
	int m_backHandle;
	// ���n���h��
	int m_soundMove;		// ����
	int m_soundClear;		// ����
	
	//���������̃C���^�[�o��
	int m_speedUpIntervar;
	// ���E�ړ��̃C���^�[�o��
	int m_LRIntervar;
	// �~�m����ӂŊ����ł��鎞��
	int m_actionTime;
	// ���x��
	int m_level;

	// �~�m�ƃX�e�[�W�̃|�C���^
	Mino*	m_pMino;
	Stage*	m_pStage;
};