#include "SceneExplanation.h"
#include "SceneMain.h"
#include "Pad.h"

SceneExplanation::SceneExplanation() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_backHandle(-1),
	m_PadHandle(-1),
	m_textHandle(-1)
{
}

SceneExplanation::~SceneExplanation()
{
}

void SceneExplanation::init()
{
	m_fadeBright = kFade::Bright;	// �t�F�[�h����
	m_fadeSpeed = kFade::Speed;	// �t�F�[�h���x
	m_backHandle = LoadGraph("data/back2.jpg");
	m_PadHandle = LoadGraph("data/GamePad3.png");
}

void SceneExplanation::end()
{
	DeleteGraph(m_backHandle);
	DeleteGraph(m_PadHandle);
}

SceneBase* SceneExplanation::update()
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

	return this;
}

void SceneExplanation::draw()
{
	// �`��P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	DrawGraph(175, 200, m_PadHandle, true);

	DrawFormatString(200, 200, GetColor(0, 0, 0), "�������");
}