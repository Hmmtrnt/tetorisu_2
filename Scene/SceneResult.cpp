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

// 初期化
void SceneResult::init()
{
	m_fadeBright = kFade::Bright;	// フェード処理
	m_fadeSpeed = kFade::Speed;	// フェード速度
	// 文字サイズ
	m_textHandle = CreateFontToHandle(NULL, 60, 4);
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;

	m_pushMainFlag = false;
	m_pushTitleFlag = false;
	// 背景
	m_backHandle = LoadGraph("data/back2.jpg");
	// 音
	m_soundHandle = LoadSoundMem("sound/pushTitle.mp3");
	ChangeVolumeSoundMem(150, m_soundHandle);
}

// 終了処理
void SceneResult::end()
{
	// 描画輝度
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);
	DeleteSoundMem(m_soundHandle);
}

// 更新処理
SceneBase* SceneResult::update()
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

// 描画処理
void SceneResult::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	DrawStringToHandle(130, 150, "ゲームオーバー", GetColor(255, 0, 0), m_textHandle);
	// 点滅テキスト
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 500, "ボタン２を押してタイトル\n\nボタン１を押してリスタート", GetColor(0, 0, 0), true);
	}
}