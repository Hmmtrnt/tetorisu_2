#include "SceneExplanation.h"
#include "SceneMain.h"
#include "Pad.h"

SceneExplanation::SceneExplanation() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_backHandle(-1),
	m_PadHandle(-1),
	m_textHandle(-1),
	m_textFlash(0),
	m_textShow(0),
	m_textHide(0)
{
}

SceneExplanation::~SceneExplanation()
{
}

void SceneExplanation::init()
{
	m_fadeBright = kFade::Bright;						// �t�F�[�h����
	m_fadeSpeed = kFade::Speed;							// �t�F�[�h���x
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;
	m_backHandle = LoadGraph("data/back2.jpg");
	m_PadHandle = LoadGraph("data/GamePad3.png");
	m_textHandle = CreateFontToHandle(NULL, 80, 4);		// �����T�C�Y
}

void SceneExplanation::end()
{
	DeleteGraph(m_backHandle);
	DeleteGraph(m_PadHandle);
}

SceneBase* SceneExplanation::update()
{
	// �e�L�X�g�̓_��
	m_textFlash++;
	if (m_textFlash >= m_textShow + m_textHide)
	{
		m_textFlash = 0;
	}

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
	DrawGraph(175, 300, m_PadHandle, true);

	// �{�^���S
	DrawLine(400, 332, 400, 270, GetColor(0, 0, 0), true);
	// �{�^���P
	DrawLine(400, 395, 480, 395, GetColor(0, 0, 0), true);
	// �{�^��UP
	DrawLine(248, 338, 248, 270, GetColor(0, 0, 0), true);
	// �{�^��RIGHT,LEFT
	DrawLine(224, 364, 180, 364, GetColor(0, 0, 0), true);
	DrawBox(224, 354, 273, 374, GetColor(0, 0, 0), false);
	// �{�^��DOWN
	DrawLine(248, 385, 248, 410, GetColor(0, 0, 0), true);
	DrawLine(248, 410, 170, 410, GetColor(0, 0, 0), true);

	DrawString(380, 250, "���ł��Q�[�����I���o���܂�", GetColor(0, 0, 0), true);
	DrawString(480, 390, "�~�m�̉�]", GetColor(0, 0, 0), true);
	DrawString(180, 250, "�n�[�h�h���b�v", GetColor(0, 0, 0), true);
	DrawString(110, 355, "���E�ړ�", GetColor(0, 0, 0), true);
	DrawString(50, 402, "�\�t�g�h���b�v", GetColor(0, 0, 0), true);

	DrawStringToHandle(140, 100, "�������", GetColor(0, 0, 0), m_textHandle);

	// �_�Ńe�L�X�g
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 570, "�a�{�^���������ăX�^�[�g", GetColor(0, 0, 0), true);
	}
}