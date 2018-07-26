#pragma once
#include "gameNode.h"
enum state
{
	NORMAL,
	ICE
};

struct tagBoxs
{
	int x, y;
	RECT rc;
};

class stage1 : public gameNode
{
private:
	state _state;
	tagBoxs _cam;

public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void cameraMove();

	stage1() {}
	~stage1() {}
};

