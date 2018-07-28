#pragma once
#include "gameNode.h"
#include <functional>
#include "TagMessage.h"

class GameObject :	public gameNode
{
	
protected:
	unordered_map<string, function<void(struct tagMessage)>> callbackList;
	typedef unordered_map<string, function<void(struct tagMessage)>>::iterator callbackIter;

	//1
	//몬스터든 뭐든 만들때마다 변수나 함수를 선언다 해줘야하지만 그건 비효율적인 코딩이기때문에
	//근원이 되는 게임오브젝트를 만들어서 상속을 받아 중복된 코딩을 안하게 해준다

	//자식들이 쓸 변수들
	string		_name;
	tagFloat	_pos;
	image*		_img;
	RECT		_rc;
	bool		_isLive;
	tagFloat	_size;

	//함수 포인터형의 자료형
	//반환형이 void여야하고 매개변수도 void여야하는 함수의 포인터
	//테스트용으로 넣어놓은것
	function<void()>			func;
	int _hp;
public:

	GameObject();
	virtual ~GameObject();

	//버추얼 : 가상함수를 만들때 사용한다.
	//가상함수를 지정하게 되면 자식이 그함수와 똑같은 함수가있을경우 자식함수를 호출한다.

	// 초기화 부분에서 (이름, 좌표,이미지키값) 받는다.
	virtual HRESULT init(string name, tagFloat pos, string imageKey = "");
	virtual void release();
	virtual void update();
	virtual void render();

	void sendMessage(tagMessage msg);
	void addCallback(string name, function<void(tagMessage)> func);

	//접근자
	string getName() const { return _name; }
	RECT getRect() const { return _rc; }
	bool getIsLive() const { return _isLive; }

};

