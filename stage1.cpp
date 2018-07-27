#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	_state = NORMAL;
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	
	

	_box[0].x = 100;
	_box[0].y = 2600;
	_box[1].x = 200;
	_box[1].y = 2500;
	_box[2].x = 340;
	_box[2].y = 2700;
	_box[3].x = 500;
	_box[3].y = 2450;
	
	for (int i = 0; i < 4; i++)
	{
		_box[i].rc = RectMakeCenter(_box[i].x, _box[i].y, 20, 20);
		_gihun.push_back(_box[i]);

	}

	

	
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

	
	/*_viGihun = _gihun.begin();
	for (_viGihun; _viGihun != _gihun.end(); ++_viGihun)
	{
		if (PtInRect(&_viGihun->rc, _ptMouse))
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_viGihun = _gihun.erase(_viGihun);
			}
			else
			{
				++_viGihun;
			}
			break;
		}
	}*/

	for (int i = 0; i < _gihun.size(); i++)
	{
		//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		//{
			if (PtInRect(&_gihun[i].rc, _ptMouse))
			{
				_gihun[i].isActive = false;
				//_gihun.erase(_gihun.begin() + i);

			}
		//}
	}

	


	//for (int i = 0; i4; <  ++i)
	//{
	//	_gihun[i].rc = RectMakeCenter(_gihun[i].x - _cam.rc.left, _gihun[i].y - _cam.rc.top, 20, 20);
	//}
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
}

void stage1::render(void)
{
	char mp[128];
	sprintf_s(mp, "%d,%d", _ptMouse.x, _ptMouse.y);
	TextOut(getMemDC(), WINSIZEX/2,WINSIZEY/2 ,mp, strlen(mp));
	

	switch (_state)
	{
	case NORMAL:


		IMAGEMANAGER->findImage("스테이지1 픽셀")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1")->render(getMemDC(),0,0, _cam.rc.left,_cam.rc.top,WINSIZEX, WINSIZEY);

	//{
	//	int mapWidth1 = IMAGEMANAGER->findImage("스테이지1-1")->getWidth();
	//	int mapWidth2 = IMAGEMANAGER->findImage("스테이지1-2")->getWidth();
	//	int width1 = mapWidth1 - _cam.rc.left;
	//	if (width1 >= WINSIZEX)
	//	{
	//		IMAGEMANAGER->findImage("스테이지1-1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	//	}
	//	else
	//	{
	//		IMAGEMANAGER->findImage("스테이지1-1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, width1, WINSIZEY);
	//		IMAGEMANAGER->findImage("스테이지1-2")->render(getMemDC(), width1, 0, 0, _cam.rc.top, WINSIZEX - width1, WINSIZEY);
	//	}
	//	if (width1 <= 0 && _cam.rc.left > 10000)
	//	{
	//		IMAGEMANAGER->findImage("스테이지1-2")->render(getMemDC(), 0, 0, _cam.rc.left - 10000, _cam.rc.top, WINSIZEX, WINSIZEY);
	//	}
	//}


	//	IMAGEMANAGER->findImage("스테이지1-1 픽셀")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		//IMAGEMANAGER->findImage("스테이지1-1")->render(getMemDC(),0,0, _cam.rc.left,_cam.rc.top,WINSIZEX, WINSIZEY);
		//IMAGEMANAGER->findImage("스테이지1-2")->render(getMemDC(), 10000, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->findImage("스테이지1-11")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		

		break;
	case ICE:
		break;
	}

	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		Rectangle(getMemDC(), _cam.rc);
	}

	char str1[128];
	sprintf_s(str1, "%d ", _cam.rc.right);
	TextOut(getMemDC(), 760, 430, str1, strlen(str1));

	char str2[128];
	sprintf_s(str2, "%d", _cam.rc.top);
	TextOut(getMemDC(), 800, 430, str2, strlen(str2));
	
	for (int i = 0; i < _gihun.size(); ++i)
	{
		if (_gihun[i].isActive == true)
			Rectangle(getMemDC(), _gihun[i].rc.left - _cam.rc.left, _gihun[i].rc.top - _cam.rc.top, _gihun[i].rc.right - _cam.rc.left, _gihun[i].rc.bottom - _cam.rc.top);
	}
}

void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cam.x += 100;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 100;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_cam.y -= 100;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_cam.y += 100;
	}


	if (_cam.x - WINSIZEX / 2 <= 0)
	{
		_cam.x = WINSIZEX / 2;
	}
	if (_cam.x + WINSIZEX / 2 >= 20000)
	{
		_cam.x = 20000 - WINSIZEX / 2;
	}
	if (_cam.y - WINSIZEY / 2 <= 0)
	{
		_cam.y = WINSIZEY / 2;
	}
	if (_cam.y + WINSIZEY / 2 >= 2750)
	{
		_cam.y = 2750 - WINSIZEY / 2;
	}

}
