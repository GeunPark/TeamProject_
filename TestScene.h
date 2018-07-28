#pragma once
#include "gameNode.h"
class TestScene : public gameNode
{
private:



public:
	TestScene();
	~TestScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

