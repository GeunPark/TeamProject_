#pragma once
#include "GameObject.h"
class TestEnemy :	public GameObject
{
public:
	TestEnemy();
	~TestEnemy();

	HRESULT init(tagFloat pos);
	void release();
	void update();
	void render();

	void Damage() { _isLive = false; }
};

