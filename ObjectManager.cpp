#include "stdafx.h"
#include "ObjectManager.h"

#include "GameObject.h"

//������
ObjectManager::ObjectManager()
{
	//�̸� ��(ObjectList) �ȿ� Ÿ�Ժ��� �� ���͸� �־� ���´�.
	for (UINT i = 0; i < ObjectManager::END; ++i)
	{
		//�ڷ���
		pair<ObjectManager::ObjectType, vector<GameObject*>> objectPair;

		//1
		//objectPair.first = (ObjectType)i;
		//objectPair.second = vector<GameObject*>();

		//2										//������ ���ÿ� �־��ش�
		objectPair = make_pair((ObjectType)i, vector<GameObject*>());

		this->ObjectList.insert(objectPair);
	}
}


ObjectManager::~ObjectManager()
{


}

void ObjectManager::release()
{
	ListIter iter = ObjectList.begin();
	
	for (iter; iter != ObjectList.end(); ++iter)
	{
		for (UINT i = 0; i < iter->second.size(); ++i)
		{
			iter->second[i]->release();
			SAFE_DELETE(iter->second[i]);
		}

		iter->second.clear();
	}

	ObjectList.clear();



}

void ObjectManager::update()
{
	ListIter iter = ObjectList.begin();

	for (iter; iter != ObjectList.end(); ++iter)
	{
		for (UINT i = 0; i < iter->second.size(); ++i)
		{
			if (iter->second[i]->getIsLive() == false)
			{
				iter->second[i]->release();
				SAFE_DELETE(iter->second[i]);
				iter->second.erase(iter->second.begin() + i);
				--i;
			}
			else
				iter->second[i]->update();
		}
	}
}

void ObjectManager::render()
{
	ListIter iter = ObjectList.begin();

	for (iter; iter != ObjectList.end(); ++iter)
	{
		for (UINT i = 0; i < iter->second.size(); ++i)
		{
			iter->second[i]->render();
		}
	}
}

void ObjectManager::addObject(ObjectManager::ObjectType type, GameObject * object)
{
	ObjectList[type].push_back(object);
}

void ObjectManager::deleteObject(ObjectManager::ObjectType type, string name)
{
	ListIter iter = ObjectList.begin();

	for (iter; iter != ObjectList.end(); ++iter)
	{
		for (UINT i = 0; i < iter->second.size(); ++i)
		{
			if (iter->second[i]->getName() == name)
			{
				iter->second[i]->release();
				SAFE_DELETE(iter->second[i]);
				iter->second.erase(iter->second.begin() + i);
				--i;
			}
		}
	}
}

GameObject * ObjectManager::findObject(ObjectManager::ObjectType type, string name)
{
	for (UINT i = 0; i < ObjectList[type].size(); ++i)
	{
		if (ObjectList[type][i]->getName() == name)
		{
			return ObjectList[type][i];
		}
	}

	return NULL;
}

vector<class GameObject*> ObjectManager::findObjects(ObjectManager::ObjectType type, string name)
{
	vector<GameObject*> findList;

	for (UINT i = 0; i < ObjectList[type].size(); ++i)
	{
		if (ObjectList[type][i]->getName() == name)
		{
			findList.push_back(ObjectList[type][i]);
		}
	}

	return findList;
}

vector<class GameObject*> ObjectManager::getObjectList(ObjectManager::ObjectType type)
{

	return ObjectList[type];
}
