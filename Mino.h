// ミノ
#pragma once
#include "common.h"

class Stage;

class Mino
{
public:
	Mino();
	virtual ~Mino();

	// 初期化
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画
	void draw();
private:

};

