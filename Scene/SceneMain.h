// ���C�����
#pragma once
#include "SceneBase.h"
#include "common.h"

//class Mino;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();

	virtual void init();			// ������
	virtual void end();				// �I������
	virtual SceneBase* update();	// �X�V����
	virtual void draw();			// �`�揈��

	// ���̊֐�
	void my_init_var();
	void my_make_block();
	void my_move_block();
	void my_collision_left();
	void my_collision_right();
	void my_draw_back();
	void my_draw_variable();
	void my_draw_block();
	void my_draw_stage();
	void my_fall_block();

private:
	//Mino* m_pMino;

	int block[BLOCK_HEIGHT][BLOCK_WIDTH];
	int stage[STAGE_HEIGHT][STAGE_WIDTH];

	int block_x;
	int block_y;
	float block_y_count;
	float block_speed;
	int collision_flag;

	int back_img1;

};