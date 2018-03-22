// Task_4.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <ctime>

using namespace std;

int fib_recursion(int val){
	if(val<1){
		return 0;
	}
	if(val==1){
		return 1;
	}
	return fib_recursion(val-1)+fib_recursion(val-2);
}

int fib_cycle(int val){
	int old=0;
	int now=1;
	int h;
	if(val<1){
		return 0;
	}
	for(int i=0;i<val-1;i++){
		h=now;
		now=now+old;
		old=h;
	}
	return now;
}

int main(int argc, char* argv[])
{
	int number;
	cout<<"Enter number: ";
	cin>>number;

	int start=clock();
	int val_recursion=fib_recursion(number);
	int end=clock();
	cout<<"Recursion:"<<endl;
	cout<<"Value="<<val_recursion<<" Time: "<<end-start<<" ms"<<endl;

	start=clock();
	int val_cycle=fib_cycle(number);
	end=clock();
	cout<<"Cycle:"<<endl;
	cout<<"Value="<<val_cycle<<" Time: "<<end-start<<" ms"<<endl;

    system("pause");
    return 0;
}
