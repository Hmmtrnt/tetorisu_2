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
	m_soundHandle(0),
	m_PadHandle(-1)
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
	// 文字サイズ
	m_textHandle = CreateFontToHandle(NULL, 80, 4);
	m_textFlash = 0;
	m_textShow = 40;
	m_textHide = 20;
	// 音
	m_soundHandle = LoadSoundMem("sound/pushTitle.mp3");
	// 画像
	m_PadHandle = LoadGraph("data/GamePad2.png");

}

// 終了処理
void SceneTitle::end()
{
	// 描画輝度
	SetDrawBright(kFade::RedBright, kFade::GreenBright, kFade::BlueBright);

	DeleteGraph(m_backHandle);
	DeleteSoundMem(m_soundHandle);
	DeleteGraph(m_PadHandle);
}

// 更新処理
SceneBase* SceneTitle::update()
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
			ChangeVolumeSoundMem(150, m_soundHandle);
			PlaySoundMem(m_soundHandle, DX_PLAYTYPE_BACK);
			m_fadeSpeed = -kFade::Speed;
		}
	}

	return this;
}

// 描画
void SceneTitle::draw()
{
	// 描画輝度
	SetDrawBright(m_fadeBright, m_fadeBright, m_fadeBright);

	DrawGraph(0, 0, m_backHandle, true);
	//DrawGraph(0, 0, m_PadHandle, true);

	DrawBox(0, 0, 150, 150, GetColor(0, 0, 0), true);

	DrawStringToHandle(160, 150, "テトリス", GetColor(0, 0, 0), m_textHandle);

	// 点滅テキスト
	if (m_textFlash < m_textShow)
	{
		DrawString(220, 500, "ボタン２を押してスタート", GetColor(0, 0, 0), true);
	}
	DrawString(170, 600, "ボタン４を押していつでも終了できます。", GetColor(0, 0, 0), true);
}