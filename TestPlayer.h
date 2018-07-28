#pragma once
#include "GameObject.h"

class TestPlayer :	public GameObject
{
private:

public:
	TestPlayer();
	~TestPlayer();

	HRESULT init();
	void release();
	void update();
	void render();

	void collision(int damege);
};

