#pragma once
#include "gameNode.h"
#include "loading.h"

class loadingScene : public gameNode
{
private:
	loading * _loading;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	//�ε��̹��� �Լ�(�̰��� �̹����� ���� �־��)
	void loadingImage();
	//�ε����� �Լ�(�̰��� ���带 ���� �־��)
	void loadingSound();

	void SeoeaWonImage();
	void SunSooImage();
	void GeunHwaImage();
	void GiHoonImage();

	void SeoeaWonSound();
	void SunSooSound();
	void GeunHwaSound();
	void GiHoonSound();


	loadingScene() {}
	~loadingScene() {}
};


