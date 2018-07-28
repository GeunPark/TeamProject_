#pragma once
#include "singletonBase.h"
#include <unordered_map>

class ObjectManager : public singletonBase <ObjectManager>
{
public:
	enum ObjectType { PLAYER, ENEMY, ITEM, UI, END };

private:
	//���� ù��° first �� ���� �� �־��ְ�, second�� ���Ϳ� ���ӿ�����Ʈ�����͸� ���� ���͸� �־��ش�.

	unordered_map<ObjectType, vector<class GameObject*>> ObjectList;

	typedef unordered_map<ObjectType, vector<class GameObject*>>::iterator ListIter;

public:
	ObjectManager();
	~ObjectManager();

	void release();
	void update();
	void render();

	void addObject(ObjectManager::ObjectType type, class GameObject* object);				//������Ʈ�� �߰��Ѵ�.
	void deleteObject(ObjectManager::ObjectType type, string name);							//������Ʈ�� �����Ѵ�.
	class GameObject* findObject(ObjectManager::ObjectType type, string name);				//name�� ���� ������Ʈ�� ã�Ƽ� ��ȯ�Ѵ�.
	vector<class GameObject*> findObjects(ObjectManager::ObjectType type, string name);		//name�̶� ��ġ�ϴ� ��� ������Ʈ�� ���Ϳ� ��Ƽ� ��ȯ
	vector<class GameObject*> getObjectList(ObjectManager::ObjectType type);				//�ش� ������Ʈ Ÿ����ü�� ��ȯ
};

