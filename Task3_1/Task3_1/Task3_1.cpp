// Task3_1.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

#define ASCII_A 65
#define ASCII_Z 90
#define ASCII_a 97
#define ASCII_z 122
#define ASCII_0 48
#define ASCII_9 57

#define ASCII_COUNT 62

using namespace std;

class ASCII_TABLE{
public:
	char ascii[ASCII_COUNT];
	ASCII_TABLE(){
		for(int i=ASCII_A,n=0;i<=ASCII_Z;i++,n++){
			ascii[n]=i;
		}
		for(int i=ASCII_a,n=26;i<=ASCII_z;i++,n++){
			ascii[n]=i;
		}
		for(int i=ASCII_0,n=52;i<=ASCII_9;i++,n++){
			ascii[n]=i;
		}

		for(int i=0;i<ASCII_COUNT;i++){
			cout<<ascii[i];
		}
		cout<<endl;
	}
};

struct RESULT{
	string s;
	int limit;
};

string brutforce(char *pass,int limit,int &iterations,int deep=0,char *result=NULL,ASCII_TABLE *t=new ASCII_TABLE()){
	if(iterations>limit){
		throw 0;
	}
	if(result==NULL){
		result=new char[strlen(pass)+1];
		int len=strlen(pass);
		for(int i=0;i<len;i++){
			result[i]=ASCII_A;
		}
		result[len]='\0';
	}
	if(deep==strlen(result)){
		iterations++;
		if(iterations>limit){
			throw 0;
		}
		for(int i=1;i<=ASCII_COUNT;i++){
			//cout<<result<<" ";
			if(strcmp(pass,result)==0){
				//cout<<"FIND!!!"<<" ";
				string s(result);
				return s;
			}
			result[deep-1]=t->ascii[i];
		}
		result[deep-1]=ASCII_A;
		string s(result);
		return s;
	}
	else{
		for(int i=1;i<=ASCII_COUNT;i++){
			string s=brutforce(pass,limit,iterations,deep+1,result,t);
			char *r=new char[s.length()+1];
			strcpy(r,s.c_str());
			if(strcmp(r,pass)==0){
				string res(r);
				return res;
			}
			else{
				result[deep-1]=t->ascii[i];
			}
		}
		result[deep-1]=ASCII_A;
		string s(result);
		return s;
	}/*
	if(strcmp(pass,result)==0){
		string s(result);
		return s;
	}*/
}

int main(int argc, char* argv[])
{
	string input;

	cout<<"Enter password: ";
	cin>>input;
	cout<<"You entered: "<<input<<endl;

	char *inputc=new char[input.length()+1];
	strcpy(inputc,input.c_str());
	string ansver;
	int iterations=0;
	int start=clock();
	int end;
	try{
		ansver=brutforce(inputc,1000000,iterations);
		end=clock();
	}
	catch(int err){
		cout<<"Over limit"<<endl;
		system("pause");
		return 0;
	}
	cout<<endl<<"Find: "<<ansver<<" iterations: "<<iterations<<" time: "<<end-start<<" ms"<<endl;

	ofstream fout("result.txt");
	fout<<"Password : "<<input<<" Find : "<<ansver<<" Iterations : "<<iterations<<" Time : "<<end-start<<" ms";
	fout.close();

	cout<<"File close"<<endl;
	
	system("pause");
    return 0;
}
