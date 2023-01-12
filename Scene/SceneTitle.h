// �^�C�g�����
#pragma once
#include "SceneBase.h"
#include "common.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`��

private:

	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;
	// �w�i�n���h��
	int m_backHandle;
	// �e�L�X�g�n���h��
	int m_textHandle;
	// �e�L�X�g�̓_��
	int m_textFlash;		// �t���[��
	int m_textShow;			// �\��
	int m_textHide;			// ��\��
	// ���n���h��
	int m_soundHandle;
};