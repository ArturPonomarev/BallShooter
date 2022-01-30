#pragma once

#include <memory>

#include "GameObject.h"
#include "Assets.h"

struct Content;

class Creator
{
public: 
	Creator() {};
	virtual ~Creator() {};

	virtual std::shared_ptr<GameObject> CreateObject(std::shared_ptr<Content>& content) = 0;
};

