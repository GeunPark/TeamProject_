#include "stdafx.h"
#include "ObjectManager.h"

#include "GameObject.h"

//생성자
ObjectManager::ObjectManager()
{
	//미리 맵(ObjectList) 안에 타입별로 빈 벡터를 넣어 놓는다.
	for (UINT i = 0; i < ObjectManager::END; ++i)
	{
		//자료형
		//pair = 탬플릿형 구조체
		pair<ObjectManager::ObjectType, vector<GameObject*>> objectPair;

		//1
		//objectPair.first = (ObjectType)i;
		//objectPair.second = vector<GameObject*>();

		//2										//생성과 빈 벡터 넣어준다
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
	//같은 이름의 게임오브젝트를 찾아서 벡터에 넣어서 그벡터를 반환
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
