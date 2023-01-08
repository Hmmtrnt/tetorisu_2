// ���C�����
#pragma once
#include "SceneBase.h"
#include "common.h"

class GameManager;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

private:

	// �t�F�[�h����
	int m_fadeBright;
	// �t�F�[�h���x
	int m_fadeSpeed;

	GameManager* m_pManager;
	
};