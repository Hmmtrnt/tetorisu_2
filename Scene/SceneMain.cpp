#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "GameManager.h"

SceneMain::SceneMain() :
	m_fadeBright(0),
	m_fadeSpeed(0)
{
	m_pManager = new GameManager;
}

SceneMain::~SceneMain()
{
	delete m_pManager;
}

// ������
void SceneMain::init()
{
	m_pManager->init();
	m_fadeBright = kFade::Bright;	// �t�F�[�h����
	m_fadeSpeed = kFade::Speed;	// �t�F�[�h���x
}

// �I������
void SceneMain::end()
{
	// �`��P�x
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
	m_pManager->end();
}

// �X�V����
SceneBase* SceneMain::update()
{
	m_pManager->update();

	/*if (m_pManager->gameover_flag == 1)
	{
		return (new SceneResult);
	}*/

	// �t�F�[�h�A�E�g�̏���
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0))
	{
		m_fadeBright = 0;
		return(new SceneResult);
	}

	if (m_fadeSpeed == 0)
	{
		// �t�F�[�h�A�E�g�J�n
		if (m_pManager->gameover_flag == 1)
		{
			m_fadeSpeed = -kFade::Speed;
		}
	}

	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}*/
	return this;
}

// �`�揈��
void SceneMain::draw()
{
	// �`��P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
}
