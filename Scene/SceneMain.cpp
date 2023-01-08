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
}

// 終了処理
void SceneMain::end()
{
	m_pManager->end();
}

// 更新処理
SceneBase* SceneMain::update()
{
	m_pManager->update();

	if (m_pManager->gameover_flag == 1)
	{
		return (new SceneResult);
	}

	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// 描画処理
void SceneMain::draw()
{
}
