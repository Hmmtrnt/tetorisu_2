#pragma once
#include "SceneBase.h"
#include "common.h"

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation();

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
	// �摜�n���h��
	int m_PadHandle;
	// �e�L�X�g�n���h��
	int m_textHandle;
};