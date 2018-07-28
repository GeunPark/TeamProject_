#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init(void)
//=============================================================
HRESULT mainGame::init(void)
{
	gameNode::init(TRUE);
	//�̰����� �ʱ�ȭ�� �Ѵ�
	
	//������ ���ΰ��� Ŭ���� �ȿ����� ���鸸 �����Ѵ�
	//�׸��� ������ ������ ���ΰ��� ������ �ϸ� �ȴ�

	/*���߰�*/
	SCENEMANAGER->addScene("�ε���", new loadingScene);
	SCENEMANAGER->addScene("��Ʈ�ξ�", new IntroScene);
	SCENEMANAGER->addScene("��ŸƮ��", new startScene);
	SCENEMANAGER->addScene("��������1", new stage1);
	SCENEMANAGER->addScene("�׽�Ʈ��", new TestScene);
	/*����� ����*/
	SCENEMANAGER->loadScene("�ε���");

	return S_OK;
}

//=============================================================
//	## ���� ## release(void)
//=============================================================
void mainGame::release(void)
{
	gameNode::release();
}

//=============================================================
//	## ������Ʈ ## update(void)
//=============================================================
void mainGame::update(void)
{
	//���Ŵ��� ������Ʈ
	SCENEMANAGER->update();

	//����Ŵ��� ������Ʈ
	SOUNDMANAGER->update();
}

//=============================================================
//	## ���� ## render(void)
//=============================================================
void mainGame::render(void)
{
	//��� �� ��Ʈ��(�̰͵� ������ �׳� �Ѱ�!!)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================

	//���Ŵ��� ����
	SCENEMANAGER->render();

	//Ÿ�ӸŴ��� ����
	TIMEMANAGER->render(getMemDC());

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �Ѱ�!!)
	this->getBackBuffer()->render(getHDC());
}