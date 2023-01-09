#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneTitle::SceneTitle() :
	m_fadeBright(0),
	m_fadeSpeed(0),
	m_backHandle(-1),
	m_textHandle(-1),
	m_textFlash(0),
	m_textShow(0),
	m_textHide(0),
	m_soundHandle(0)
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
	// �����T�C�Y
	m_textHandle = CreateFontToHandle(NULL, 80, 4);
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;
	// ��
	m_soundHandle = LoadSoundMem("sound/pushTitle.mp3");
}

// �I������
void SceneTitle::end()
{
	// �`��P�x
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);

	DeleteGraph(m_backHandle);
	DeleteSoundMem(m_soundHandle);
}

// �X�V����
SceneBase* SceneTitle::update()
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
			ChangeVolumeSoundMem(150, m_soundHandle);
			PlaySoundMem(m_soundHandle, DX_PLAYTYPE_BACK);
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
	
	DrawStringToHandle(160, 150, "�e�g���X", GetColor(0, 0, 0), m_textHandle);

	// �_�Ńe�L�X�g
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 500, "�{�^���Q�������ăX�^�[�g", GetColor(0, 0, 0), true);
	}
}