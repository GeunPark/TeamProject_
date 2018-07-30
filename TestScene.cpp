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
	
	TestEnemy* Enemy = new TestEnemy;
	Enemy->init(tagFloat(100,100));
	OBJECTMANAGER->addObject(ObjectManager::ENEMY, Enemy);

	TestEnemy* Enemy1 = new TestEnemy;
	Enemy1->init(tagFloat(200, 100));
	OBJECTMANAGER->addObject(ObjectManager::ENEMY, Enemy1);

	

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
