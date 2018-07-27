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
	bool isActive = true;
	RECT rc;
};

class stage1 : public gameNode
{
private:
	state _state;
	tagBoxs _cam;
	tagBoxs _box[5];
	vector<tagBoxs> _gihun;
	vector<tagBoxs>::iterator _viGihun;
	//int _x, _y;


public:

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	vector<tagBoxs> getVBox() { return _gihun; }


	void cameraMove();
	stage1() {}
	~stage1() {}
};

