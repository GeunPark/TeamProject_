#include "stdafx.h"
#include "TestPlayer.h"
#include "TestEnemy.h"

TestPlayer::TestPlayer()
{
}


TestPlayer::~TestPlayer()
{
}

HRESULT TestPlayer::init()
{
	
	GameObject::init("player", tagFloat(WINSIZEX / 2, WINSIZEY / 2));


	return S_OK;
}

void TestPlayer::release()
{
}

void TestPlayer::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pos.x -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_pos.x += 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_pos.y -= 3;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_pos.y += 3;
	}
	GameObject::update();

	vector<GameObject*> EnemyList = OBJECTMANAGER->getObjectList(ObjectManager::ENEMY);

	for (UINT i = 0; i < EnemyList.size(); ++i)
	{
		RECT temp;
		if (IntersectRect(&temp, &EnemyList[i]->getRect(), &this->_rc))
		{
			EnemyList[i]->sendMessage(tagMessage("Attack", 0.f, 3));
		}
	}

}

void TestPlayer::render()
{
	GameObject::render();

}

void TestPlayer::collision(int damege)
{
}
