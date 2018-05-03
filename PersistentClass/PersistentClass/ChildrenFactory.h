#pragma once

#include "ChildrenShadow.h"

using namespace Children;

ref class ChildrenFactory
{
private:
	ChildrenShadow* childrenShadow;
public:
	void create(ChildrenShadow *chSh);
	int getUniqueID();
	ChildrenShadow findByID(int id);
	ChildrenShadow* find(int &size,std::string namePart,int flag);
	ChildrenShadow* find(int &size,std::string firstName,std::string secondName);
};

