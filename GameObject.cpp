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
	
	//만약 이미지이름이 0보다 크다면 이미지가 있다는 것
	if (imageKey.length() > 0)
	{
		//이미지가 있다면 그 키값에맞는 이미지를 찾아서 이미지를 넣어주고
		this->_img = IMAGEMANAGER->findImage(imageKey);
		//이미지의 크기는 이미지의 크기만큼 넣어라
		this->_size = tagFloat(this->_img->getWidth(), this->_img->getHeight());
	}
	else // 그게아니고 이미지가 없다면 이미지는 널
	{
		this->_img = NULL;
	}

	//항상 초기에는 살아있으니까 트루
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
	
	//상속받은 클래스의 렉트는 각 클래스에서 초기화를 하는것으로

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

