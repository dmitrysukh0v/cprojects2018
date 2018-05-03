// ListAndVector.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <ctime>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	srand(time(NULL));

	vector<int> v;
	list<int> l;

	typedef vector<int>::iterator vit;
	typedef list<int>::iterator lit;

	int start=clock();
	for(int i=0;i<10;i++){
		v.push_back(1+rand()%100);
	}
	int end=clock();

	cout<<"Add random value in vector: "<<end-start<<" ms"<<endl;

	//

	start=clock();
	for(int i=0;i<10;i++){
		l.push_back(1+rand()%100);
	}
	end=clock();

	cout<<"Add random value in list: "<<end-start<<" ms"<<endl;

	//

	start=clock();
	v.insert(v.begin(),100);
	end=clock();

	cout<<"Vector - insert in front: "<<end-start<<" ms"<<endl;

	start=clock();
	l.push_front(100);
	end=clock();

	cout<<"List - push_front: "<<end-start<<" ms"<<endl;

	//

	start=clock();
	v.insert(v.begin()+5,v.begin(),v.end());
	end=clock();

	cout<<"Vector - copy in center: "<<end-start<<" ms"<<endl;

	start=clock();
	/*
	lit it=l.begin();
	for(int i=0;i<5;i++,it++);*/

	l.insert(l.begin(),l.begin(),l.end());
	end=clock();

	cout<<"List - copy in begin: "<<end-start<<" ms"<<endl;

	//

	cout<<"vector: "<<endl;
	for(vit it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	cout<<"list: "<<endl;
	for(lit it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
	cout<<endl;

	//

	start=clock();
	sort(v.begin(),v.end());
	//v.sort();
	end=clock();
	int r=end-start;
	cout<<"sort\nvector: "<<endl;
	for(vit it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<endl<<r<<" ms\n";

	start=clock();
	l.sort();
	end=clock();
	r=end-start;
	cout<<"list: "<<endl;
	for(lit it=l.begin();it!=l.end();it++)
		cout<<*it<<" ";
	cout<<endl<<r<<" ms\n";

	system("pause");

    return 0;
}
