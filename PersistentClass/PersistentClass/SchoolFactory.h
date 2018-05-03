#pragma once

#include "SchoolShadow.h"

using namespace School;

ref class SchoolFactory
{
private:
	SchoolShadow* schoolShadow;
public:
	void create(SchoolShadow *scSh);
	int getUniqueID();
	SchoolShadow findByID(int id);
};

