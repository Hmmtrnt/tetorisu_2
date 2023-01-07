#include "SceneResult.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneResult::SceneResult()
{

}

SceneResult::~SceneResult()
{

}

// ‰Šú‰»
void SceneResult::init()
{

}

// I—¹ˆ—
void SceneResult::end()
{

}

// XVˆ—
SceneBase* SceneResult::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneTitle);
	}
	else if (Pad::isTrigger(PAD_INPUT_1))
	{
		return (new SceneMain);
	}

	return this;
}

// •`‰æˆ—
void SceneResult::draw()
{
	DrawString(0, 0, "SceneResult", GetColor(255, 255, 255));
}