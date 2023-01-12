#include "SceneExplanation.h"
#include "SceneMain.h"
#include "Pad.h"

SceneExplanation::SceneExplanation() :
	m_backHandle(-1),
	m_PadHandle(-1),
	m_fadeBright(0),
	m_fadeSpeed(0)
{
}

SceneExplanation::~SceneExplanation()
{
}

void SceneExplanation::init()
{
	m_fadeBright = kFade::Bright;	// フェード処理
	m_fadeSpeed = kFade::Speed;	// フェード速度
	m_backHandle = LoadGraph("data/back2.jpg");
	m_PadHandle = LoadGraph("data/GamePad2.png");
}

void SceneExplanation::end()
{
	DeleteGraph(m_backHandle);
	DeleteGraph(m_PadHandle);
}

SceneBase* SceneExplanation::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return(new SceneMain);
	}

	return this;
}

void SceneExplanation::draw()
{
	DrawGraph(0, 0, m_backHandle, true);
	DrawGraph(0, 0, m_PadHandle, true);

	DrawFormatString(200, 200, GetColor(0, 0, 0), "操作説明");
}