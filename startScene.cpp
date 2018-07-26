#include "stdafx.h"
#include "startScene.h"

HRESULT startScene::init(void)
{
	x = WINSIZEX / 2 - 240;
	y = START;
	rc = RectMake(x, y, IMAGEMANAGER->findImage("��ŸƮ�������ڽ�")->getWidth(), IMAGEMANAGER->findImage("��ŸƮ�������ڽ�")->getHeight());
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SOUNDMANAGER->play("�����̵�����");
		if (y == START)
		{
			y = SETTING;
		}
		else
		{
			y = START;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SOUNDMANAGER->play("�����̵�����");
		if (y == START)
		{
			y = SETTING;
		}
		else
		{
			y = START;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("��������");
		if (y == START)	
		{
			SCENEMANAGER->loadScene("��������1");
		}
		else if (y == SETTING)
		{

		}
	}

	rc = RectMake(x, y, IMAGEMANAGER->findImage("��ŸƮ�������ڽ�")->getWidth(), IMAGEMANAGER->findImage("��ŸƮ�������ڽ�")->getHeight());
}

void startScene::render(void)
{
	IMAGEMANAGER->alphaRender("��ŸƮ�����", getMemDC(), 180);
	IMAGEMANAGER->render("��ŸƮ������â", getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("��ŸƮ������â")->getWidth() / 2, 200, 0, 0, IMAGEMANAGER->findImage("��ŸƮ������â")->getWidth(), IMAGEMANAGER->findImage("��ŸƮ������â")->getHeight());
	IMAGEMANAGER->render("��ŸƮ�������ڽ�", getMemDC(), rc.left, rc.top);
}
