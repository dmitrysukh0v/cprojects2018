// Nalog.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "Property.h"
#include "Appartment.h"
#include "Car.h"
#include "CountryHouse.h"

using namespace std;

int main()
{
	int size;
	cout<<"Enter array size: ";
	cin>>size;
	cout<<endl<<endl;

	Property **parr=new Property *[size];

	srand(time(NULL));
	int type;
	for(int i=0;i<size;i++){
		type=1+rand()%3;
		switch(type){
		case 1:{
			parr[i]=new Appartment(static_cast<float>(rand())/static_cast<float>(100.0));
			break;
			   }
		case 2:{
			parr[i]=new Car(static_cast<float>(rand())/static_cast<float>(100.0));
			break;
			   }
		case 3:{
			parr[i]=new CountryHouse(static_cast<float>(rand())/static_cast<float>(100.0));
			break;
			   }
		}
		cout<<typeid(*parr[i]).name()<<endl<<"Worth: "<<parr[i]->getWorth()<<endl<<"Tax: "<<parr[i]->Calculation()<<endl<<"***"<<endl;
	}

	cout<<endl;
	system("pause");
    return 0;
}
