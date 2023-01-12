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
	m_fadeBright = kFade::Bright;						// フェード処理
	m_fadeSpeed = kFade::Speed;							// フェード速度
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

	DrawStringToHandle(170, 100, "操作説明", GetColor(0, 0, 0), m_textHandle);
}