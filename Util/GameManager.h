// テトリスの進行管理
#pragma once
#include "common.h"

class Mino;
class Stage;

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

	// 二個目以降の初期化
	void initScond();
	// ゲームオーバー判定
	void gameover();
	// 当たり判定
	void collisionLeft();		// 左
	void collisionRight();		// 右
	void collisionBottom();		// 地面
	void collisionOver();		// 天井
	void collisionTurn();		// 回転
	// ミノの回転
	void turnMino();
	// ミノが落ちた時の処理
	void fixMino();
	// ミノの操作
	void actionMino();
	// ハードドロップ
	void hardDrop();
	// ミノの落下地点
	void dropPointMino();
	// ミノをステージの配列に保存
	void saveMino();
	// 揃った列を調べる
	void searchLine();
	// 揃った列の入れ替え
	void clearLine();
	// 背景
	void drawBack();

	// ゲームオーバーになったかどうか
	bool m_gameoverFlag;

private:

	// 壁の判定フラグ
	bool m_collsionFlag;
	// 回転後のミノを作る
	int m_turnProvisional;
	// 回転したミノを保存
	int m_turnMino[BLOCK_HEIGHT][BLOCK_WIDTH];
	// 消去するミノ
	int m_clearMinoLine[STAGE_HEIGHT - 1];
	// 消去する一列の数
	int m_clearCount;
	// ブロックが消えているかどうか
	bool m_clearFlag;
	// 背景ハンドル
	int m_backHandle;
	// 音ハンドル
	int m_soundMove;		// 操作
	int m_soundClear;		// 消去
	
	//落下加速のインターバル
	int m_speedUpIntervar;
	// 左右移動のインターバル
	int m_LRIntervar;
	// ミノが底辺で活動できる時間
	int m_actionTime;
	// レベル
	int m_level;

	// ミノとステージのポインタ
	Mino*	m_pMino;
	Stage*	m_pStage;
};