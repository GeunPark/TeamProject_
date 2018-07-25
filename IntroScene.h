#pragma once
#include "gameNode.h"

struct tagBox
{
	RECT rc;
	POINT pos;
};


class IntroScene :	public gameNode
{
private:
	image* _intro[5];
	tagBox _rc;
	int _count;

public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	IntroScene() {}
	~IntroScene() {}
};

