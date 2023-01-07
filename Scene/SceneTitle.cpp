#include "SceneTitle.h"
#include "SceneMain.h"
#include "DxLib.h"
#include "Pad.h"

SceneTitle::SceneTitle()
{

}

SceneTitle::~SceneTitle()
{

}

// 初期化
void SceneTitle::init()
{

}

// 終了処理
void SceneTitle::end()
{

}

// 更新処理
SceneBase* SceneTitle::update()
{
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneMain);
	}

	return this;
}

// 描画
void SceneTitle::draw()
{
	DrawString(0, 0, "テトリス", GetColor(255, 255, 255));
}