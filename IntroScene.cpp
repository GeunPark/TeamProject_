#include "stdafx.h"
#include "IntroScene.h"


HRESULT IntroScene::init(void)
{
	_intro[0] = IMAGEMANAGER->addImage("�κ�����", "resource/��Ʈ�ξ�/�κ�� ���.bmp", 1280, 720);
	_intro[1] = IMAGEMANAGER->addImage("�κ���ΰ�", "resource/��Ʈ�ξ�/�κ�� �ΰ�.bmp", 650, 274, true, MAGENTA);
	_intro[2] = IMAGEMANAGER->addImage("�κ����ư", "resource/��Ʈ�ξ�/�κ�� ��ư.bmp", 130, 105, true, MAGENTA);
	_intro[3] = IMAGEMANAGER->addImage("�κ����ѱ�", "resource/��Ʈ�ξ�/�κ�� ��ѱ�.bmp", 217, 228, true, MAGENTA);
	_intro[4] = IMAGEMANAGER->addImage("�κ������", "resource/��Ʈ�ξ�/�κ�� ����.bmp", 400, 545, true, MAGENTA);

	_rc.pos.x = 850;
	_rc.pos.y = 15;
	_rc.rc = RectMake(_rc.pos.x, _rc.pos.y, _intro[4]->getWidth(), _intro[4]->getHeight());

	//_intro[4]->setY(15);
	_count = 0;
	return S_OK;
}

void IntroScene::release(void)
{
}

void IntroScene::update(void)
{
	_count++;
	if (_count % 5 == 0)
	{
		

	}
	_rc.rc = RectMake(_rc.pos.x, _rc.pos.y, _intro[4]->getWidth(), _intro[4]->getHeight());
}

void IntroScene::render(void)
{
	IMAGEMANAGER->render("�κ�����", getMemDC());
	_intro[4]->render(getMemDC(), _rc.pos.x, _rc.pos.y, 0, 0, _intro[4]->getWidth(), _intro[4]->getHeight());
	IMAGEMANAGER->render("�κ���ΰ�", getMemDC(), 315, 110, 0, 0, 650, 274);

	char str[128];
	sprintf_s(str, "%d", _rc.pos.y);
	TextOut(getMemDC(), 10, 10, str, strlen(str));
}
