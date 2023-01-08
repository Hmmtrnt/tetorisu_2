// リザルト画面
#pragma once
#include "SceneBase.h"
class SceneResult : public SceneBase
{
public:
	SceneResult();
	virtual ~SceneResult();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画処理

private:

	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;

	bool m_pushMainFlag;
	bool m_pushTitleFlag;

};