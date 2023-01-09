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

// 初期化
void SceneTitle::init()
{
	m_fadeBright = kFade::Bright;	// フェード処理
	m_fadeSpeed = kFade::Speed;	// フェード速度
	m_backHandle = LoadGraph("data/back2.jpg");
}

// 終了処理
void SceneTitle::end()
{
	// 描画輝度
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
}

// 更新処理
SceneBase* SceneTitle::update()
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

	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneMain);
	}*/

	return this;
}

// 描画
void SceneTitle::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	DrawString(0, 0, "テトリス", GetColor(0, 0, 0));
}