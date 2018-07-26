#include "stdafx.h"
#include "startScene.h"

HRESULT startScene::init(void)
{
	
	x = WINSIZEX / 2 - 240;
	y = START;
	rc = RectMake(x, y, IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·º¹Ú½º")->getWidth(), IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·º¹Ú½º")->getHeight());
	return S_OK;
}

void startScene::release(void)
{
}

void startScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SOUNDMANAGER->play("¼¿·ºÀÌµ¿»ç¿îµå");
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
		SOUNDMANAGER->play("¼¿·ºÀÌµ¿»ç¿îµå");
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
		SOUNDMANAGER->play("¼¿·º»ç¿îµå");
		if (y == START)	
		{
			SCENEMANAGER->loadScene("½ºÅ×ÀÌÁö1");
		}
		else if (y == SETTING)
		{

		}
	}

	rc = RectMake(x, y, IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·º¹Ú½º")->getWidth(), IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·º¹Ú½º")->getHeight());
}

void startScene::render(void)
{
	IMAGEMANAGER->alphaRender("½ºÅ¸Æ®¾À¹è°æ", getMemDC(), 180);
	IMAGEMANAGER->render("½ºÅ¸Æ®¾À¼¿·ºÃ¢", getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·ºÃ¢")->getWidth() / 2, 200, 0, 0, IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·ºÃ¢")->getWidth(), IMAGEMANAGER->findImage("½ºÅ¸Æ®¾À¼¿·ºÃ¢")->getHeight());
	IMAGEMANAGER->render("½ºÅ¸Æ®¾À¼¿·º¹Ú½º", getMemDC(), rc.left, rc.top);
}
