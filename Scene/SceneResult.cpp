#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneResult::SceneResult() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_pushMainFlag(false),
	m_pushTitleFlag(false),
	m_backHandle(-1),
	m_textHandle(-1),
	m_textFlash(0),
	m_textShow(0),
	m_textHide(0),
	m_soundHandle(0)
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
	// �����T�C�Y
	m_textHandle = CreateFontToHandle(NULL, 60, 4);
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;

	m_pushMainFlag = false;
	m_pushTitleFlag = false;
	// �w�i
	m_backHandle = LoadGraph("data/back2.jpg");
	// ��
	m_soundHandle = LoadSoundMem("sound/pushTitle.mp3");
	ChangeVolumeSoundMem(150, m_soundHandle);
}

// �I������
void SceneResult::end()
{
	// �`��P�x
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
	DeleteSoundMem(m_soundHandle);
}

// �X�V����
SceneBase* SceneResult::update()
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
			PlaySoundMem(m_soundHandle, DX_PLAYTYPE_BACK);
			m_pushTitleFlag = true;
			m_fadeSpeed = -kFade::Speed;
		}
		else if (Pad::isTrigger(PAD_INPUT_1))
		{
			PlaySoundMem(m_soundHandle, DX_PLAYTYPE_BACK);
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

	DrawGraph(0, 0, m_backHandle, true);
	DrawStringToHandle(130, 150, "�Q�[���I�[�o�[", GetColor(255, 0, 0), m_textHandle);
	// �_�Ńe�L�X�g
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 500, "�{�^���Q�������ă^�C�g��\n\n�{�^���P�������ă��X�^�[�g", GetColor(0, 0, 0), true);
	}
}