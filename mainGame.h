#pragma once
#include "gameNode.h"
/*�����δ� �� ������ϸ� �߰����ش�*/
#include "loadingScene.h"
#include "IntroScene.h"
#include "startScene.h"


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

