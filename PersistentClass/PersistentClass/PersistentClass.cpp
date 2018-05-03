// PersistentClass.cpp: ������� ���� �������.

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include "ElementShadow.h"
#include "ChildrenShadow.h"
#include "ChildrenFactory.h"
#include "SchoolShadow.h"
#include "SchoolFactory.h"
#include <vector>
#include <iterator>

using namespace std;
using namespace Children;

bool find(int current,int wanted){
	return current==wanted ? true : false;
}

ChildrenShadow* findCurrentAge(vector<ChildrenShadow*> v,bool (*cond)(int,int),int w){
	typedef vector<ChildrenShadow*>::iterator It;
	for(It it=v.begin();it!=v.end();it++){
		if(cond((*it)->getAge(),w))
			return *it;
	}
	return NULL;
}

int main(int argc,char** argv)
{
	setlocale(LC_ALL,"Russian");

	ChildrenFactory factory;
	SchoolFactory sfactory;

	while(true){
		cout<<"�������� ��������:"<<endl;

		cout<<"1 - ������� ������������\n"
			<<"2 - ����� �� ID\n"
			<<"3 - ����� �� �����\n"
			<<"4 - ����� �� �������\n"
			<<"5 - ����� �� ����� � �������\n"
			<<"6 - ������� �����\n"
			<<"7 - ����� �� ID\n"
			<<"8 - ����� ���������\n"
			<<"9 - ���� �������, ������� �� 03.05.18"<<endl;

		int input;
		cin>>input;
		switch(input){
		case 1:{
			cout<<"������� ���: ";
			string firstname;
			cin>>firstname;
			cout<<"������� �������: ";
			string secondname;
			cin>>secondname;
			cout<<"������� id �����: ";
			int scid;
			cin>>scid;

			int year;
			while(true){
				cout<<"��� ��������: ";
				cin>>year;
				if(year>0)
					break;
				else
					cout<<"������!"<<endl;
			}
			int month;
			while(true){
				cout<<"����� ��������: ";
				cin>>month;
				if(month>0 && month<13)
					break;
				else
					cout<<"������!"<<endl;
			}
			int day;
			while(true){
				cout<<"���� ��������: ";
				cin>>day;
				if(day>0 && day<32)
					break;
				else
					cout<<"������!"<<endl;
			}


			ChildrenShadow ch;
			ch.setID(factory.getUniqueID());
			ch.setFirstName(firstname);
			ch.setSecondName(secondname);
			ch.setSchoolID(scid);
			ch.setDateOfBirth(day,month,year);
			factory.create(&ch);
			cout<<"������ ������������ � id="<<ch.getID()<<endl<<endl;
			break;
			   }
		case 2:{
			int id;
			cout<<"������� id: ";
			cin>>id;
			ChildrenShadow ch=factory.findByID(id);
			if(ch.getID()>0){
				tm date=ch.getDateOfBirth();
				cout<<"������ ������������: "<<ch.getFirstName()<<" "<<ch.getSecondName()<<" "<<date.tm_mday<<":"<<date.tm_mon<<":"<<date.tm_year<<endl;
				cout<<"��� ������� : "<<ch.getAge()<<endl;
				SchoolFactory scf;
				SchoolShadow scSh=scf.findByID(ch.getSchoolID());
				cout<<"��� �����: ";
				cout<<scSh.getID()<<" "<<scSh.getName()<<" "<<scSh.getAdress()<<" "<<scSh.getPhone()<<endl<<endl;
			}
			else{
				cout<<"������������ �� ������"<<endl<<endl;
			}
			break;
			   }
		case 3:{
			string name;
			cout<<"������� ���: ";
			cin>>name;
			
			int size=0;
			ChildrenShadow *arr=factory.find(size,name,1);
			if(size==0){
				cout<<"������ �� �������"<<endl<<endl;
			}
			else{
				cout<<"������� ������������:\n";
				for(int i=0;i<size;i++){
					cout<<arr[i].getID()<<" "<<arr[i].getFirstName()<<" "<<arr[i].getSecondName()<<endl;
				}
				cout<<endl<<endl;
			}
			break;
			   }
		case 4:{
			string name;
			cout<<"������� �������: ";
			cin>>name;
			
			int size=0;
			ChildrenShadow *arr=factory.find(size,name,2);
			if(size==0){
				cout<<"������ �� �������"<<endl<<endl;
			}
			else{
				cout<<"������� ������������:\n";
				for(int i=0;i<size;i++){
					cout<<arr[i].getID()<<" "<<arr[i].getFirstName()<<" "<<arr[i].getSecondName()<<endl;
				}
				cout<<endl<<endl;
			}
			break;
			   }
		case 5:{
			string fname;
			cout<<"������� ���: ";
			cin>>fname;

			string sname;
			cout<<"������� �������: ";
			cin>>sname;
			
			int size=0;
			ChildrenShadow *arr=factory.find(size,fname,sname);
			if(size==0){
				cout<<"������ �� �������"<<endl<<endl;
			}
			else{
				cout<<"������� ������������:\n";
				for(int i=0;i<size;i++){
					cout<<arr[i].getID()<<" "<<arr[i].getFirstName()<<" "<<arr[i].getSecondName()<<endl;
				}
				cout<<endl<<endl;
			}
			break;
			   }
		case 6:{
			cout<<"������� ���: ";
			string name;
			cin>>name;
			cout<<"������� �����: ";
			string adress;
			cin>>adress;
			cout<<"������� �������: ";
			string phone;
			cin>>phone;

			SchoolShadow scSh;
			scSh.setID(sfactory.getUniqueID());
			scSh.setName(name);
			scSh.setAdress(adress);
			scSh.setPhone(phone);
			sfactory.create(&scSh);
			cout<<"������� ����� � id="<<scSh.getID()<<endl<<endl;
			break;
			   }
		case 7:{
			int id;
			cout<<"������� id: ";
			cin>>id;
			SchoolShadow scSh=sfactory.findByID(id);
			if(scSh.getID()>0){
				cout<<"������� �����: "<<scSh.getID()<<" "<<scSh.getName()<<" "<<scSh.getAdress()<<" "<<scSh.getPhone()<<endl<<endl;
			}
			else{
				cout<<"����� �� �������"<<endl<<endl;
			}
			break;
			   }
		case 8:{
			ChildrenShadow chMaxAge;
			chMaxAge.setDateOfBirth(0,0,0);
			int last_id=factory.getUniqueID()-1;
			for(int i=1;i<last_id;i++){
				ChildrenShadow ch=factory.findByID(i);
				if(ch.getID()>0){
					chMaxAge=chMaxAge+ch;
				}
			}
			cout<<chMaxAge.getAge()<<endl;
			break;
			   }
		case 9:{
			vector<ChildrenShadow*> vectCh;

			vectCh.push_back(new ChildrenShadow());
			vectCh.back()->setDateOfBirth(1,1,1990);

			vectCh.push_back(new ChildrenShadow());
			vectCh.back()->setDateOfBirth(1,1,2000);

			vectCh.push_back(new ChildrenShadow());
			vectCh.back()->setDateOfBirth(1,1,1995);

			ChildrenShadow* ch=findCurrentAge(vectCh,find,28);

			cout<<ch->getAge()<<endl;

			break;
			   }
		default:{
				}
		
		}
	}


	system("pause");
    return 0;
}
