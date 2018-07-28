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
	//���͵� ���� ���鶧���� ������ �Լ��� ����� ����������� �װ� ��ȿ������ �ڵ��̱⶧����
	//�ٿ��� �Ǵ� ���ӿ�����Ʈ�� ���� ����� �޾� �ߺ��� �ڵ��� ���ϰ� ���ش�

	//�ڽĵ��� �� ������
	string		_name;
	tagFloat	_pos;
	image*		_img;
	RECT		_rc;
	bool		_isLive;
	tagFloat	_size;

	//�Լ� ���������� �ڷ���
	//��ȯ���� void�����ϰ� �Ű������� void�����ϴ� �Լ��� ������
	//�׽�Ʈ������ �־������
	function<void()>			func;
	int _hp;
public:

	GameObject();
	virtual ~GameObject();

	//���߾� : �����Լ��� ���鶧 ����Ѵ�.
	//�����Լ��� �����ϰ� �Ǹ� �ڽ��� ���Լ��� �Ȱ��� �Լ���������� �ڽ��Լ��� ȣ���Ѵ�.

	// �ʱ�ȭ �κп��� (�̸�, ��ǥ,�̹���Ű��) �޴´�.
	virtual HRESULT init(string name, tagFloat pos, string imageKey = "");
	virtual void release();
	virtual void update();
	virtual void render();

	void sendMessage(tagMessage msg);
	void addCallback(string name, function<void(tagMessage)> func);

	//������
	string getName() const { return _name; }
	RECT getRect() const { return _rc; }
	bool getIsLive() const { return _isLive; }

};

