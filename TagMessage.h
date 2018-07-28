#pragma once
#include "stdafx.h"
struct tagMessage
{
	string name;
	float delayTime;
	int intData;
	float floatData;
	vector<class GameObject*> targetList;
	
	tagMessage() {}

	tagMessage(string name, float delayTime = 0.0f, int intData = 0, float floatData = 0.0f, vector<class GameObject*> targetList = vector<class GameObject*>())
		:name(name), delayTime(delayTime), intData(intData), floatData(floatData), targetList(targetList) {}
};
