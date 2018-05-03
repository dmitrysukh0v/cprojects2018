// ChildrenProject.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include "ChildrenShadow.h"

using namespace std;

int main(int argc,char** argv)
{
    ChildrenShadow chSh;
	chSh.setID(10);
	cout<<chSh.getID();
	system("pause");
    return 0;
}
