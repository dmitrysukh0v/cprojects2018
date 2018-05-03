// 220318_cpp.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>

using namespace std;

class Aclass{
public:
	int a;

	Aclass(int b){
		a=b;
		cout<<"Create"<<endl;
	}

	~Aclass(){
		cout<<"Delete"<<endl;
	}
	static void istatic(){
		cout<<"Static";
	}
};

void f(){
	Aclass a(10);
}

int main(int argc,char* argv[])
{
	f();
	Aclass.istatic();
	system("pause");
    return 0;
}
