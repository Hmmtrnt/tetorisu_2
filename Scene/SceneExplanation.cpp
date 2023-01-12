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
	m_fadeBright = kFade::Bright;						// フェード処理
	m_fadeSpeed = kFade::Speed;							// フェード速度
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;
	m_backHandle = LoadGraph("data/back2.jpg");
	m_PadHandle = LoadGraph("data/GamePad3.png");
	m_textHandle = CreateFontToHandle(NULL, 80, 4);		// 文字サイズ
}

void SceneExplanation::end()
{
	DeleteGraph(m_backHandle);
	DeleteGraph(m_PadHandle);
}

SceneBase* SceneExplanation::update()
{
	// テキストの点滅
	m_textFlash++;
	if (m_textFlash >= m_textShow + m_textHide)
	{
		m_textFlash = 0;
	}

	// フェードアウトの処理
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
		// フェードアウト開始
		if (Pad::isTrigger(PAD_INPUT_2))
		{
			m_fadeSpeed = -kFade::Speed;
		}
	}

	return this;
}

void SceneExplanation::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	DrawGraph(175, 300, m_PadHandle, true);

	// ボタン４
	DrawLine(400, 332, 400, 270, GetColor(0, 0, 0), true);
	// ボタン１
	DrawLine(400, 395, 480, 395, GetColor(0, 0, 0), true);
	// ボタンUP
	DrawLine(248, 338, 248, 270, GetColor(0, 0, 0), true);
	// ボタンRIGHT,LEFT
	DrawLine(224, 364, 180, 364, GetColor(0, 0, 0), true);
	DrawBox(224, 354, 273, 374, GetColor(0, 0, 0), false);
	// ボタンDOWN
	DrawLine(248, 385, 248, 410, GetColor(0, 0, 0), true);
	DrawLine(248, 410, 170, 410, GetColor(0, 0, 0), true);

	DrawString(380, 250, "いつでもゲームを終了出来ます", GetColor(0, 0, 0), true);
	DrawString(480, 390, "ミノの回転", GetColor(0, 0, 0), true);
	DrawString(180, 250, "ハードドロップ", GetColor(0, 0, 0), true);
	DrawString(110, 355, "左右移動", GetColor(0, 0, 0), true);
	DrawString(50, 402, "ソフトドロップ", GetColor(0, 0, 0), true);

	DrawStringToHandle(140, 100, "操作説明", GetColor(0, 0, 0), m_textHandle);

	// 点滅テキスト
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 570, "Ｂボタンを押してスタート", GetColor(0, 0, 0), true);
	}
}