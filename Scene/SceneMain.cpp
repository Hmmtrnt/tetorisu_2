#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
#include "GameManager.h"

SceneMain::SceneMain() :
	m_fadeBright(0),
	m_fadeSpeed(0)
{
	m_pManager = new GameManager;
}

SceneMain::~SceneMain()
{
	delete m_pManager;
}

// 初期化
void SceneMain::init()
{
	m_pManager->init();
	m_fadeBright = kFade::Bright;	// フェード処理
	m_fadeSpeed = kFade::Speed;	// フェード速度
}

// 終了処理
void SceneMain::end()
{
	// 描画輝度
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
	m_pManager->end();
}

// 更新処理
SceneBase* SceneMain::update()
{
	m_pManager->update();

	/*if (m_pManager->gameover_flag == 1)
	{
		return (new SceneResult);
	}*/

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
		return(new SceneResult);
	}

	if (m_fadeSpeed == 0)
	{
		// フェードアウト開始
		if (m_pManager->gameover_flag == 1)
		{
			m_fadeSpeed = -kFade::Speed;
		}
	}

	/*if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}*/
	return this;
}

// 描画処理
void SceneMain::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);
}
