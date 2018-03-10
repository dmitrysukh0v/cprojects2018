// Task2.cpp

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void PrintToBinary(int val){
	bool bits[32];	//array for bits
	//checking for a negative value
	if(val>=0){
		bits[0]=0;
	}
	else{
		bits[0]=1;
		val=~(val-1);
	}
	for(int i=31;i>0;i--){
		if(val){
			bits[i]=(val & 1);
			val=val>>1;
		}
		else
			bits[i]=0;
	}
	for(int i=0;i<32;i++)
		cout<<bits[i];
}

int main()
{
	
	int valinteger;

	cout<<"Input number: ";
	cin>>valinteger;

	cout<<"You input: "<<valinteger<<". in the binary representation C: ";
	PrintToBinary(valinteger);

	cout<<endl;
	system("pause");

    return 0;
}
