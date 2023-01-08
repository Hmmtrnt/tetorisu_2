// ���U���g���
#pragma once
#include "SceneBase.h"
class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

private:

	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;

	bool m_pushMainFlag;
	bool m_pushTitleFlag;

};