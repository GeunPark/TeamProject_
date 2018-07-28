#include "stdafx.h"
#include "IntroScene.h"


HRESULT IntroScene::init(void)
{
	_rc[0].pos.x = 850;
	_rc[0].pos.y = 15;
	_rc[0].rc = RectMake(_rc[0].pos.x, _rc[0].pos.y, IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getHeight());

	_rc[1].pos.x = 195;
	_rc[1].pos.y = 250;
	_rc[1].rc = RectMake(_rc[1].pos.x, _rc[1].pos.y, IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getHeight());
	

	SOUNDMANAGER->play("·Îºñ¾À¹è°æÀ½¾Ç");
	//_intro[4]->setY(15);
	_count = _count2 = _count3 = 0;
	Uturn = Uturn2 = false;
	alpha = 255;
	return S_OK;
}

void IntroScene::release(void)
{
}

void IntroScene::update(void)
{
	_count3++;
	if (_count3 % 50 == 0)
	{
		alpha = 0;
	}
	if (_count3 % 100 == 0)
	{
		alpha = 255;
	}
	_count++;
	if (_count % 7 == 0)
	{
		if (!Uturn)
		{
			_rc[0].pos.y--;
			if (_rc[0].pos.y < 10)
			{
				Uturn = true;
			}
		}
		else
		{
			_rc[0].pos.y++;
			if (_rc[0].pos.y > 30)
			{
				Uturn = false;
			}
		}
	}
	_count2++;
	if (_count2 % 2 == 0)
	{
		if (!Uturn2)
		{
			_rc[1].pos.y--;
			if (_rc[1].pos.y < 240)
			{
				Uturn2 = true;
			}
		}
		else
		{
			_rc[1].pos.y++;
			if (_rc[1].pos.y > 270)
			{
				Uturn2 = false;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("¼¿·º»ç¿îµå");

		SCENEMANAGER->loadScene("½ºÅ¸Æ®¾À");
		//SOUNDMANAGER->stop("·Îºñ¾À¹è°æÀ½¾Ç");
	}

	_rc[0].rc = RectMake(_rc[0].pos.x, _rc[0].pos.y, IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getWidth(),  IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getWidth());
	_rc[1].rc = RectMake(_rc[1].pos.x, _rc[1].pos.y, IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getHeight());
}

void IntroScene::render(void)
{
	IMAGEMANAGER->render("·Îºñ¾À¹è°æ", getMemDC());
	IMAGEMANAGER->render("·Îºñ¾À¿©¿ì", getMemDC(), _rc[0].pos.x, _rc[0].pos.y, 0, 0, IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾À¿©¿ì")->getHeight());
	IMAGEMANAGER->render("·Îºñ¾ÀºñµÑ±â", getMemDC(), _rc[1].pos.x, _rc[1].pos.y, 0, 0, IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾ÀºñµÑ±â")->getHeight());
	IMAGEMANAGER->render("·Îºñ¾À·Î°í", getMemDC(), 315, 110, 0, 0, 650, 274);
	
	IMAGEMANAGER->alphaRender("·Îºñ¾À¹öÆ°", getMemDC(), WINSIZEX / 2 - 65, 500, 0, 0, IMAGEMANAGER->findImage("·Îºñ¾À¹öÆ°")->getWidth(), IMAGEMANAGER->findImage("·Îºñ¾À¹öÆ°")->getHeight(), alpha);
	

	//char str[128];
	//sprintf_s(str, "%d", _rc[0].pos.y);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));
}
