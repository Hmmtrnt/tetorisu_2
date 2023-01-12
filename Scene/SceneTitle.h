// タイトル画面
#pragma once
#include "SceneBase.h"
#include "common.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	virtual ~SceneTitle();

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
	// テキストハンドル
	int m_textHandle;
	// テキストの点滅
	int m_textFlash;		// フレーム
	int m_textShow;			// 表示
	int m_textHide;			// 非表示
	// 音ハンドル
	int m_soundHandle;
};