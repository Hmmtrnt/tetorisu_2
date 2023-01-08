// テトリスの進行管理
#pragma once

class GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	// 初期化処理
	void init();
	// 終了処理
	void end();
	// 更新処理
	void update();
	// 描画処理
	void draw();
private:

};