#pragma once
#include "singletonBase.h"
#include <unordered_map>

class ObjectManager : public singletonBase <ObjectManager>
{
public:
	enum ObjectType { PLAYER, ENEMY, ITEM, UI, END };

private:
	unordered_map<ObjectType, vector<class GameObject*>> ObjectList;

	typedef unordered_map<ObjectType, vector<class GameObject*>>::iterator ListIter;

public:
	ObjectManager();
	~ObjectManager();

	void release();
	void update();
	void render();

	void addObject(ObjectManager::ObjectType type, class GameObject* object);				//오브젝트를 추가한다.
	void deleteObject(ObjectManager::ObjectType type, string name);							//오브젝트를 삭제한다.
	class GameObject* findObject(ObjectManager::ObjectType type, string name);				//name과 같은 오브젝트를 찾아서 반환한다.
	vector<class GameObject*> findObjects(ObjectManager::ObjectType type, string name);		//name이랑 일치하는 모든 오브젝트를 벡터에 담아서 반환
	vector<class GameObject*> getObjectList(ObjectManager::ObjectType type);				//해당 오브젝트 타입전체를 반환
};

