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
	
	if (imageKey.length() > 0)
	{
		this->_img = IMAGEMANAGER->findImage(imageKey);
		this->_size = tagFloat(this->_img->getWidth(), this->_img->getHeight());
	}
	else
	{
		this->_img = NULL;
	}

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

