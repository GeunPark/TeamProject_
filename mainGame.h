#pragma once
#include "gameNode.h"
/*앞으로는 씬 헤더파일만 추가해준다*/
#include "loadingScene.h"
#include "IntroScene.h"
#include "startScene.h"
#include "stage1.h"
#include "TestScene.h"


class mainGame : public gameNode
{
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	mainGame() {}
	~mainGame() {}
};

