// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include <SDKDDKVer.h>


#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <Windows.h>

//디버깅용 (주석치면 콘솔창이 사라진다)
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
// C++ 런타임 헤더 파일입니다.
#include <iostream>
using namespace std;
// 자주사용하는 STL
#include <string>
#include <vector>
#include <map>
// 네임스페이스
#include "util.h"
using namespace MY_UTIL;


//=============================================================
//	## 내가 만든 헤더파일을 이곳에 추가한다 ##
//=============================================================
#include "commonMacroFunction.h"
#include "keyManager.h"
#include "randomFunction.h"
#include "imageManager.h"
#include "saveData.h"
#include "txtData.h"
#include "sceneManager.h"
#include "iniData.h"
#include "timeManager.h"
#include "soundManager.h"
#include "ObjectManager.h"


//=============================================================
//	## 싱글톤을 추가한다 ##
//=============================================================
#define KEYMANAGER keyManager::getSingleton()
#define RND randomFunction::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SAVEDATA saveData::getSingleton()
#define TXTDATA txtData::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define INIDATA iniData::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define OBJECTMANAGER ObjectManager::getSingleton()


//=============================================================
//	## 디파인문 ## (윈도우창 초기화)
//=============================================================
#define WINNAME (LPTSTR)(TEXT(" FOX N FORESTS - 누가 우리 기훈이한테 뭐라고 했조 "))
#define WINSTARTX	500
#define WINSTARTY	100
#define WINSIZEX		1280
#define WINSIZEY		720
#define WINSTYLE		WS_CAPTION | WS_SYSMENU

//=============================================================
//	## 매크로함수 ## (클래스에서 동적할당된 부분 해제)
//=============================================================
#define SAFE_DELETE(p)		{if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p)	{if(p) {delete[] (p); (p) = NULL;}}
#define ONE_RAID 0.01745328f // 디그리를 라디안 값으로 바꿔준다 (ex) 90 * ONE_RAID =  90도

#define Synthesize(VarType, VarName, FuncName)	\
protected: VarType VarName;	\
public: inline VarType Get##FuncName(void) const { return VarName; }	\
public: inline void Set##FuncName(VarType value) { VarName = value; }

//=============================================================
//	## 전역변수 ##
//=============================================================
extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;