#pragma once

//TODO �������� ��� ������

#include "ComponentBase.h"
#include <vector>

class Entity
{
public:
	Entity(int id) { m_id = id; }
	~Entity() {};

	int GetId() { return m_id; }


private:
	int m_id;

	std::vector<ComponentBase*> components;
};


