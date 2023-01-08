// メイン画面
#pragma once
#include "SceneBase.h"
#include "common.h"

class GameManager;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画処理

private:

	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;

	GameManager* m_pManager;
	
};