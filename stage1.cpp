#include "stdafx.h"
#include "stage1.h"

HRESULT stage1::init(void)
{
	_state = NORMAL;
	_cam.x = WINSIZEX / 2;
	_cam.y = 2750 - (WINSIZEY / 2);
	_cam.rc = RectMakeCenter(_cam.x, _cam.y, WINSIZEX, WINSIZEY);
	_index = 0;
	_count = 0;
	_count1 = 0;
	_index1 = 0;

	_bush[0].x = 1470;
	_bush[0].y = 2600;
	_bush[1].x = 1390;
	_bush[1].y = 2600;
	_bush[2].x = 3450;
	_bush[2].y = 2185;
	_bush[3].x = 3530;
	_bush[3].y = 2185;
	_bush[4].x = 9470;
	_bush[4].y = 2500;

	_bush[5].x = 13615;
	_bush[5].y = 1310;
	_bush[6].x = 18220;
	_bush[6].y = 2600;
	_bush[7].x = 18300;
	_bush[7].y = 2600;
	_bush[8].x = 12260;
	_bush[8].y = 2600;
	_bush[9].x = 12340;
	_bush[9].y = 2600;
	
	for (int i = 0; i < 10; i++)
	{
		tagBoxs _bushs;
		_bushs._img = new image;
		_bushs._img = IMAGEMANAGER->findImage("ūǮ");
		_bushs.x = 200 * i + 100;
		_bushs.y = 2500;
		_bushs.rc = RectMakeCenter(_bush[i].x, _bush[i].y, 100,100);
		_vBush.push_back(_bushs);
	}
	return S_OK;
}

void stage1::release(void)
{

}
void stage1::update(void)
{
	
	cameraMove();
	imageMove();
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
		IMAGEMANAGER->findImage("�� ����1")->frameRender(getMemDC(), 2467 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("�� ����2")->frameRender(getMemDC(), 5700 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("�� ����3")->frameRender(getMemDC(), 11700 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("�� ����4")->frameRender(getMemDC(), 14100 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("�� ����5")->frameRender(getMemDC(), 16100 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("�� ����6")->frameRender(getMemDC(), 17600 - _cam.rc.left, 2630 - _cam.rc.top);
		IMAGEMANAGER->findImage("��������1")->render(getMemDC(),0,0, _cam.rc.left,_cam.rc.top,WINSIZEX, WINSIZEY);
		// ū Ǯ
		for (int i = 0; i < _vBush.size(); ++i)
		{
			if (!_vBush[i].isActive) continue;
			_vBush[i]._img->render(getMemDC(), _vBush[i].rc.left - _cam.rc.left, _vBush[i].rc.top - _cam.rc.top);
		}
		// ���� �̹��� ���
		IMAGEMANAGER->findImage("����1")->frameRender(getMemDC(), 8692 - _cam.rc.left, 2196 - _cam.rc.top);
		IMAGEMANAGER->findImage("����2")->frameRender(getMemDC(), 10288 - _cam.rc.left, 1896 - _cam.rc.top);
		IMAGEMANAGER->findImage("����3")->frameRender(getMemDC(), 14908 - _cam.rc.left, 2070 - _cam.rc.top);

		IMAGEMANAGER->findImage("������1")->frameRender(getMemDC(), 8692 - _cam.rc.left, 2148 - _cam.rc.top);
		IMAGEMANAGER->findImage("������2")->frameRender(getMemDC(), 10288 - _cam.rc.left, 1848- _cam.rc.top);
		IMAGEMANAGER->findImage("������3")->frameRender(getMemDC(), 14908 - _cam.rc.left, 2022 - _cam.rc.top);

		IMAGEMANAGER->findImage("�������")->frameRender(getMemDC(), 14473 - _cam.rc.left, 2213 - _cam.rc.top);
	

	/*{
	/	int mapWidth1 = IMAGEMANAGER->findImage("��������1-1")->getWidth();
	/	int mapWidth2 = IMAGEMANAGER->findImage("��������1-2")->getWidth();
	/	int width1 = mapWidth1 - _cam.rc.left;
	/	if (width1 >= WINSIZEX)
	/	{
	/		IMAGEMANAGER->findImage("��������1-1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	/	}
	/	else
	/	{
	/		IMAGEMANAGER->findImage("��������1-1")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, width1, WINSIZEY);
	/		IMAGEMANAGER->findImage("��������1-2")->render(getMemDC(), width1, 0, 0, _cam.rc.top, WINSIZEX - width1, WINSIZEY);
	/	}
	/	if (width1 <= 0 && _cam.rc.left > 10000)
	/	{
	/		IMAGEMANAGER->findImage("��������1-2")->render(getMemDC(), 0, 0, _cam.rc.left - 10000, _cam.rc.top, WINSIZEX, WINSIZEY);
	/	}
	/}
	/	IMAGEMANAGER->findImage("��������1-1 �ȼ�")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
	*/
		break;
	case ICE:
		break;
	}

	if (KEYMANAGER->isToggleKey(VK_F4))
	{
		IMAGEMANAGER->findImage("��������1 �ȼ�")->render(getMemDC(), 0, 0, _cam.rc.left, _cam.rc.top, WINSIZEX, WINSIZEY);
		Rectangle(getMemDC(), _cam.rc);
	}
	char str1[128];
	sprintf_s(str1, "%d ", _cam.rc.right);
	TextOut(getMemDC(), 760, 430, str1, strlen(str1));

	char str2[128];
	sprintf_s(str2, "%d", _cam.rc.top);
	TextOut(getMemDC(), 800, 430, str2, strlen(str2));
	
	char mp[128];
	sprintf_s(mp, "%d,%d", _cam.rc.left +  _ptMouse.x, _cam.rc.top + _ptMouse.y);
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, mp, strlen(mp));
	
}

void stage1::imageMove()
{
	_count++;
	_count1++;	// ������� ī����, ������� ���� ���� �׳� �߾��
	if (_count > 100000)_count = 0;
	if (_count1 > 100000)_count1 = 0;
	if (_count % 5 == 0)_index++;
	if (_index > 16)_index = 0;

	if (_count1 % 5 == 0)_index1++;
	if (_index1 > 7)_index1 = 0;
	IMAGEMANAGER->findImage("����1")->setFrameX(_index);
	IMAGEMANAGER->findImage("����2")->setFrameX(_index);
	IMAGEMANAGER->findImage("����3")->setFrameX(_index);

	IMAGEMANAGER->findImage("������1")->setFrameX(_index);
	IMAGEMANAGER->findImage("������2")->setFrameX(_index);
	IMAGEMANAGER->findImage("������3")->setFrameX(_index);

	IMAGEMANAGER->findImage("�������")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����1")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����2")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����3")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����4")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����5")->setFrameX(_index1);
	IMAGEMANAGER->findImage("�� ����6")->setFrameX(_index1);
}

void stage1::cameraMove()
{
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_cam.x += 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_cam.x -= 50;

	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_cam.y -= 50;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_cam.y += 50;
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
