#pragma once

//TODO Доделать или убрать

#include <vector>

#include "Entity.h"

class ESC
{
public:
	ESC();
	~ESC();

	void Update(float dt);

	void CreateEntity();
	void DestroyEntity(int entityId);

private:
	std::vector<Entity*> m_entities;
};

