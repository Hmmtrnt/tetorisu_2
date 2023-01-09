#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneTitle::SceneTitle() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_backHandle(-1)
{

}

SceneTitle::~SceneTitle()
{

}

// ������
void SceneTitle::init()
{
	m_fadeBright = kFade::Bright;	// �t�F�[�h����
	m_fadeSpeed = kFade::Speed;	// �t�F�[�h���x
	m_backHandle = LoadGraph("data/back2.jpg");
}

// �I������
void SceneTitle::end()
{
	// �`��P�x
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
}

// �X�V����
SceneBase* SceneTitle::update()
{

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
		return(new SceneMain);
	}

	if (m_fadeSpeed == 0)
	{
		// �t�F�[�h�A�E�g�J�n
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			m_fadeSpeed = -kFade::Speed;
		}
	}

	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneMain);
	}*/

	return this;
}

// �`��
void SceneTitle::draw()
{
	// �`��P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	DrawString(0, 0, "�e�g���X", GetColor(0, 0, 0));
}