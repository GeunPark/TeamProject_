#include "stdafx.h"
#include "IntroScene.h"


HRESULT IntroScene::init(void)
{
	_intro[0] = IMAGEMANAGER->addImage("·Îºñ¾À¹è°æ", "resource/ÀÎÆ®·Î¾À/·Îºñ¾À ¹è°æ.bmp", 1280, 720);
	_intro[1] = IMAGEMANAGER->addImage("·Îºñ¾À·Î°í", "resource/ÀÎÆ®·Î¾À/·Îºñ¾À ·Î°í.bmp", 650, 274, true, MAGENTA);
	_intro[2] = IMAGEMANAGER->addImage("·Îºñ¾À¹öÆ°", "resource/ÀÎÆ®·Î¾À/·Îºñ¾À ¹öÆ°.bmp", 130, 105, true, MAGENTA);
	_intro[3] = IMAGEMANAGER->addImage("·Îºñ¾ÀºñµÑ±â", "resource/ÀÎÆ®·Î¾À/·Îºñ¾À ºñµÑ±â.bmp", 217, 228, true, MAGENTA);
	_intro[4] = IMAGEMANAGER->addImage("·Îºñ¾À¿©¿ì", "resource/ÀÎÆ®·Î¾À/·Îºñ¾À ¿©¿ì.bmp", 400, 545, true, MAGENTA);

	_rc[0].pos.x = 850;
	_rc[0].pos.y = 15;
	_rc[0].rc = RectMake(_rc[0].pos.x, _rc[0].pos.y, _intro[4]->getWidth(), _intro[4]->getHeight());

	_rc[1].pos.x = 195;
	_rc[1].pos.y = 250;
	_rc[1].rc = RectMake(_rc[1].pos.x, _rc[1].pos.y, _intro[3]->getWidth(), _intro[3]->getHeight());
	

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

	_rc[0].rc = RectMake(_rc[0].pos.x, _rc[0].pos.y, _intro[4]->getWidth(), _intro[4]->getHeight());
	_rc[1].rc = RectMake(_rc[1].pos.x, _rc[1].pos.y, _intro[3]->getWidth(), _intro[3]->getHeight());
}

void IntroScene::render(void)
{
	IMAGEMANAGER->render("·Îºñ¾À¹è°æ", getMemDC());
	_intro[4]->render(getMemDC(), _rc[0].pos.x, _rc[0].pos.y, 0, 0, _intro[4]->getWidth(), _intro[4]->getHeight());
	_intro[3]->render(getMemDC(), _rc[1].pos.x, _rc[1].pos.y, 0, 0, _intro[3]->getWidth(), _intro[3]->getHeight());
	IMAGEMANAGER->render("·Îºñ¾À·Î°í", getMemDC(), 315, 110, 0, 0, 650, 274);
	
	_intro[2]->alphaRender(getMemDC(), WINSIZEX / 2 - 65, 500, 0, 0, _intro[2]->getWidth(), _intro[2]->getHeight(),alpha);
	

	//char str[128];
	//sprintf_s(str, "%d", _rc[0].pos.y);
	//TextOut(getMemDC(), 10, 10, str, strlen(str));
}
