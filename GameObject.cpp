#include "stdafx.h"
#include "GameObject.h"

#include "TagMessage.h"
GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}



HRESULT GameObject::init(string name, tagFloat pos, string imageKey)
{
	this->_name = name;
	this->_pos = pos;
	
	//���� �̹����̸��� 0���� ũ�ٸ� �̹����� �ִٴ� ��
	if (imageKey.length() > 0)
	{
		//�̹����� �ִٸ� �� Ű�����´� �̹����� ã�Ƽ� �̹����� �־��ְ�
		this->_img = IMAGEMANAGER->findImage(imageKey);
		//�̹����� ũ��� �̹����� ũ�⸸ŭ �־��
		this->_size = tagFloat(this->_img->getWidth(), this->_img->getHeight());
	}
	else // �װԾƴϰ� �̹����� ���ٸ� �̹����� ��
	{
		this->_img = NULL;
	}

	//�׻� �ʱ⿡�� ��������ϱ� Ʈ��
	this->_isLive = true;


	return S_OK;
}

void GameObject::release()
{
}

void GameObject::update()
{
	//if (this->_img != NULL)
	//{
	//	this->_rc = RectMakeCenter(this->_pos.x, this->_pos.y, this->_img->getWidth(), this->_img->getHeight());
	//}
	//else
	//{
	//	this->_rc = RectMakeCenter(this->_pos.x, this->_pos.y, 50, 50);
	//}
	
	//��ӹ��� Ŭ������ ��Ʈ�� �� Ŭ�������� �ʱ�ȭ�� �ϴ°�����

	this->_rc = RectMakeCenter(this->_pos.x, this->_pos.y, 50, 50);
}

void GameObject::render()
{
	Rectangle(getMemDC(), this->_rc);
}

void GameObject::sendMessage(tagMessage msg)
{
	callbackIter iter = callbackList.begin();

	for (; iter != callbackList.end(); ++iter)
	{
		if (msg.name == iter->first)
		{
			iter->second(msg);
			break;
		}
	}
}

void GameObject::addCallback(string name, function<void(tagMessage)> func)
{
	this->callbackList.insert(make_pair(name, func));
}

