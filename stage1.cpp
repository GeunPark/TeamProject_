#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	_state = NORMAL;

	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	return S_OK;
}

void stage1::release(void)
{
}

void stage1::update(void)
{
	cameraMove();
	switch (_state)
	{
	case NORMAL:
		if (KEYMANAGER->isOnceKeyDown('A'))_state = ICE;
		break;
	case ICE:
		if (KEYMANAGER->isOnceKeyDown('A'))_state = NORMAL;
		break;
	}
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
}

void stage1::render(void)
{
	switch (_state)
	{
	case NORMAL:
	//	IMAGEMANAGER->findImage("스테이지1-1 픽셀")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1-1")->render(getMemDC(),0,0, _cam.rc.left,_cam.rc.top,WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1-2")->render(getMemDC(), 10000, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);

		
		break;
	case ICE:
		IMAGEMANAGER->findImage("스테이지1-1 얼음 픽셀")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1-1 얼음")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1-2 얼음")->render(getMemDC(), 10000, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		break;
	}

	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		Rectangle(getMemDC(), _cam.rc);
	}

	char str1[128];
	sprintf_s(str1, "%d ", _cam.rc.right);
	TextOut(getMemDC(), 760, 430, str1, strlen(str1));
}

void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cam.x += 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP) && _cam.rc.top > 0)
	{
		_cam.y -= 10;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && _cam.rc.bottom < 2750)
	{
		_cam.y += 10;
	}
}
