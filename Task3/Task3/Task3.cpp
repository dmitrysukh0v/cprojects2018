// Task3.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <string>

#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_0 48
#define ASCII_9 57

#define ASCII_COUNT 62

using namespace std;

string brutforce(char* pass,int limit){
	/*
	string result(pass);
	cout<<"/"<<strlen(pass)<<"/";
	char A=65;
	char Z=90;
	cout<<"/"<<A<<Z<<"/";
	return result;*/

	int length=strlen(pass);
	int lim=limit;

	char *result=new char[length+1];
	char ascii_table[ASCII_COUNT];
	
	for(int i=ASCII_A;i<=ASCII_Z;i++){
		ascii_table[i]=i;
	}
	for(int i=ASCII_a;i<=ASCII_z;i++){
		ascii_table[i]=i;
	}
	for(int i=ASCII_0;i<=ASCII_9;i++){
		ascii_table[i]=i;
	}

	for(int i=0;i<=length;i++){
		if(i!=length){
			result[i]=ASCII_A;
		}
		else{
			result[i]='\0';
		}
	}

	for(int l=0;l<length;l++){
		for(int i=0;i<ASCII_COUNT;i++){
			cout<<result<<" ";
			if(strcmp(pass,result)==0){
				string r(result);
				return r;
			}
			if(lim<0){
				return "ERROR";
			}
			else{
				lim--;
				result[l]=ascii_table[i];
			}
		}
	}

	return "ERROR";
}

int main(int argc, char* argv[])
{
	string input;

	cout<<"Enter password: ";
	cin>>input;
	cout<<"You entered: "<<input<<endl;

	char *inputc=new char[input.length()+1];
	strcpy(inputc,input.c_str());
	string ansver=brutforce(inputc,100);
	cout<<endl<<"Find: "<<ansver;
	
	system("pause");
    return 0;
}
