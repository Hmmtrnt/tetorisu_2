#pragma once
#include "SceneBase.h"
#include "common.h"

class SceneExplanation : public SceneBase
{
public:
	SceneExplanation();
	virtual ~SceneExplanation();

	virtual void init();			// 初期化
	virtual void end();				// 終了処理
	virtual SceneBase* update();	// 更新処理
	virtual void draw();			// 描画

private:
	// フェード処理
	int m_fadeBright;
	// フェード速度
	int m_fadeSpeed;
	// 背景ハンドル
	int m_backHandle;
	// 画像ハンドル
	int m_PadHandle;
	// テキストハンドル
	int m_textHandle;
};