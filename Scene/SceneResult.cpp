#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_pushMainFlag(false),
	m_pushTitleFlag(false)
{

}

SceneResult::~SceneResult()
{

}

// ������
void SceneResult::init()
{
	m_fadeBright = kFade::Bright;	// �t�F�[�h����
	m_fadeSpeed = kFade::Speed;	// �t�F�[�h���x

	m_pushMainFlag = false;
	m_pushTitleFlag = false;
}

// �I������
void SceneResult::end()
{
	// �`��P�x
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
}

// �X�V����
SceneBase* SceneResult::update()
{

	// �t�F�[�h�A�E�g�̏���
	m_fadeBright += m_fadeSpeed;
	if (m_fadeBright >= 255)
	{
		m_fadeBright = 255;
		m_fadeSpeed = 0;
	}
	if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && 
		(m_pushMainFlag))
	{
		m_fadeBright = 0;
		return(new SceneMain);
	}
	else if ((m_fadeBright <= 0) && (m_fadeSpeed < 0) && 
		(m_pushTitleFlag))
	{
		m_fadeBright = 0;
		return(new SceneTitle);
	}

	if (m_fadeSpeed == 0)
	{
		// �t�F�[�h�A�E�g�J�n
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			m_pushTitleFlag = true;
			m_fadeSpeed = -kFade::Speed;
		}
		else if (Pad::isTrigger(PAD_INPUT_1))
		{
			m_pushMainFlag = true;
			m_fadeSpeed = -kFade::Speed;
		}
	}

	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneTitle);
	}
	else if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneMain);
	}*/

	return this;
}

// �`�揈��
void SceneResult::draw()
{
	// �`��P�x
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawString(0, 0, "SceneResult", GetColor(255, 255, 255));
}