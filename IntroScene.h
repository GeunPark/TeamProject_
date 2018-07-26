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
	tagBox _rc[2];
	int _count, _count2, _count3;
	bool Uturn, Uturn2;
	int alpha;

public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	IntroScene() {}
	~IntroScene() {}
};

