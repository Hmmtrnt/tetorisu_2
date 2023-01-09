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

// 初期化
void SceneResult::init()
{
	m_fadeBright = kFade::Bright;	// フェード処理
	m_fadeSpeed = kFade::Speed;	// フェード速度

	m_pushMainFlag = false;
	m_pushTitleFlag = false;
}

// 終了処理
void SceneResult::end()
{
	// 描画輝度
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
}

// 更新処理
SceneBase* SceneResult::update()
{

	// フェードアウトの処理
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
		// フェードアウト開始
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

// 描画処理
void SceneResult::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawString(0, 0, "SceneResult", GetColor(255, 255, 255));
}