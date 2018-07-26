#pragma once
#include "gameNode.h"
#define START 235
#define SETTING 360
class startScene :	public gameNode
{
private:
	int x, y;
	RECT rc;
public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	startScene() {}
	~startScene() {}
};

