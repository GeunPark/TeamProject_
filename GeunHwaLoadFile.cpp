#include "stdafx.h"
#include "loadingScene.h"


void loadingScene::GeunHwaImage()
{
	_loading->loadImage("로비씬배경", "resource/인트로씬/로비씬 배경.bmp", 1280, 720);
	_loading->loadImage("로비씬로고", "resource/인트로씬/로비씬 로고.bmp", 650, 274, true, MAGENTA);
	_loading->loadImage("로비씬버튼", "resource/인트로씬/로비씬 버튼.bmp", 130, 105, true, MAGENTA);
	_loading->loadImage("로비씬비둘기", "resource/인트로씬/로비씬 비둘기.bmp", 217, 228, true, MAGENTA);
	_loading->loadImage("로비씬여우", "resource/인트로씬/로비씬 여우.bmp", 400, 545, true, MAGENTA);
	_loading->loadImage("스타트씬배경", "resource/인트로씬/스타트씬배경.bmp", 1280, 720);
	_loading->loadImage("스타트씬셀렉창", "resource/인트로씬/스타트씬 셀렉.bmp", 546, 299);
	_loading->loadImage("스타트씬셀렉박스", "resource/인트로씬/스타트씬 셀렉박스.bmp", 480, 106, true, MAGENTA);



}


void loadingScene::GeunHwaSound()
{
	_loading->loadSound("로비씬배경음악", "resource/사운드/로비씬배경음악.wav", true, true);
	// 스타트씬 사운드
	_loading->loadSound("셀렉사운드", "resource/사운드/셀렉 사운드.wav");
	_loading->loadSound("셀렉이동사운드", "resource/사운드/셀렉 이동 사운드.wav");

}

