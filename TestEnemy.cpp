#include "stdafx.h"
#include "TestEnemy.h"


TestEnemy::TestEnemy()
{
}


TestEnemy::~TestEnemy()
{
}

HRESULT TestEnemy::init()
{
	GameObject::init("Enemy", tagFloat(RND->getFromIntTo(100, WINSIZEX), RND->getFromIntTo(100, WINSIZEY)));


	this->addCallback("Attack", [this](tagMessage msg)
	{
		this->_hp -= msg.intData;
		if (_hp < 0)_isLive = false;
	});


	_hp = 1;

	return S_OK;
}

void TestEnemy::release()
{
}

void TestEnemy::update()
{
	GameObject::update();
}

void TestEnemy::render()
{
	GameObject::render();
}
