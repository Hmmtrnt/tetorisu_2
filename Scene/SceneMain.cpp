#include "SceneMain.h"
#include "SceneResult.h"
#include "DxLib.h"
#include "Pad.h"
//#include "Mino.h"
//#include "Stage.h"

SceneMain::SceneMain()
{
	//m_pMino = new Mino;
}

SceneMain::~SceneMain()
{
	//delete m_pMino;
}

// ������
void SceneMain::init()
{
	//m_pMino->init();
}

// �I������
void SceneMain::end()
{
	//m_pMino->end();
}

// �X�V����
SceneBase* SceneMain::update()
{
	/*m_pMino->update();
	m_pMino->hitTop();
	if (m_pMino->getGameOver())
	{
		return (new SceneResult);
	}*/
	if (Pad::isTrigger(PAD_INPUT_2))
	{
		return (new SceneResult);
	}
	return this;
}

// �`�揈��
void SceneMain::draw()
{
	DrawString(0, 0, "SceneMain", GetColor(255, 255, 255));
	/*m_pMino->makeMino();
	m_pMino->draw();*/
}