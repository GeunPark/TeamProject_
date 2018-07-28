#include "stdafx.h"
#include "TestScene.h"
#include "TestEnemy.h"
#include "TestPlayer.h"

TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

HRESULT TestScene::init()
{
	for (UINT i = 0; i < 10; ++i)
	{
		TestEnemy* Enemy = new TestEnemy;
		Enemy->init();
		OBJECTMANAGER->addObject(ObjectManager::ENEMY, Enemy);
	}

	TestPlayer* Player = new TestPlayer;
	Player->init();
	OBJECTMANAGER->addObject(ObjectManager::PLAYER, Player);

	return S_OK;
}

void TestScene::release()
{
}

void TestScene::update()
{
	OBJECTMANAGER->update();
}

void TestScene::render()
{
	OBJECTMANAGER->render();
}
