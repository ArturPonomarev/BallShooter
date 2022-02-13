#include "ESC.h"

#include <iterator>

ESC::ESC()
{
}

ESC::~ESC()
{
	
}

void ESC::Update(float dt)
{
		
}

void ESC::CreateEntity()
{
	static int entityId = 0;
	m_entities.push_back(new Entity(++entityId));
}

void ESC::DestroyEntity(int entityId)
{
	for (auto iter = m_entities.begin(); iter != m_entities.end(); iter++)
	{
		if ((*iter)->GetId() == entityId)
		{
			delete (*iter);
			m_entities.emplace(iter);
			return;
		}
	}
}
