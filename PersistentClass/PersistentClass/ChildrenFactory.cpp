#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "ChildrenFactory.h"

using namespace std;

void ChildrenFactory::create(ChildrenShadow *ch){
	ofstream fout("childrens.txt",ios_base::app);

	fout<<ch->getID()<<":"<<
		ch->getFirstName()<<":"<<
		ch->getSecondName()<<":"<<
		ch->getSchoolID()<<" "<<
		ch->getDateOfBirth().tm_mday<<":"<<
		ch->getDateOfBirth().tm_mon<<":"<<
		ch->getDateOfBirth().tm_year<<":\n";

	fout.close();
}
int ChildrenFactory::getUniqueID(){
	ifstream fin("childrens.txt",ios_base::in);
	char findid=0;
	char buff[51];

	if(fin.is_open()){
		while(!fin.eof()){
			fin.getline(buff,50);
			if(!fin.eof()){
				char buffid[51];
				for(int i=0;i<51;i++){
					if(buff[i]!=':'){
						buffid[i]=buff[i];
					}
					else{
						std::string id(buffid);
						findid=atoi(id.c_str());
						break;
					}
				}
			}
		}
	}

	return ++findid;
}
ChildrenShadow ChildrenFactory::findByID(int id){
	ifstream fin("childrens.txt",ios_base::in);

	char findid;
	char buff[51];

	while(!fin.eof()){
		fin.getline(buff,50);
		if(!fin.eof()){
			char buffid[51];
			for(int i=0;i<51;i++){
				if(buff[i]!=':'){
					buffid[i]=buff[i];
				}
				else{
					std::string id(buffid);
					findid=atoi(id.c_str());
					break;
				}
			}
			if(findid==id){
				break;
			}
		}
	}

	ChildrenShadow ch;

	bool id_find=false;
	bool fn_find=false;
	bool sn_find=false;
	bool sc_find=false;
	bool day_find=false;
	bool mon_find=false;
	bool year_find=false;

	int day=0;
	int month=0;
	int year=0;

	char temp_buff[51];//ok

	for(int i=0,j=0;i<51;i++){
		if(!id_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				ch.setID(atoi(temp.c_str()));
				id_find=true;
			}
			continue;
		}
		if(!fn_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				ch.setFirstName(temp);
				fn_find=true;
			}
			continue;
		}
		if(!sn_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				ch.setSecondName(temp);
				sn_find=true;
			}
			continue;
		}
		if(!sc_find){
			if(buff[i]!=' '){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				ch.setSchoolID(atoi(temp.c_str()));
				sc_find=true;
			}
			continue;
		}
		if(!day_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				day=atoi(temp.c_str());
				day_find=true;
			}
			continue;
		}
		if(!mon_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				month=atoi(temp.c_str());
				mon_find=true;
			}
			continue;
		}
		if(!year_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				year=atoi(temp.c_str());
				year_find=true;
			}
			continue;
		}
		for(int t=0;t<51;t++){
			temp_buff[t]=' ';
		}
	}

	fin.close();
	//cout<<"prepare return\n";
	ch.setDateOfBirth(day,month,year);
	return ch;
}
ChildrenShadow* ChildrenFactory::find(int &size,std::string namePart,int flag){
	ifstream fin("childrens.txt",ios_base::in);

	ChildrenShadow *charr;

	char buff[51];

	bool id_find=false;
	bool fn_find=false;
	bool sn_find=false;
	bool day_find=false;
	bool mon_find=false;
	bool year_find=false;

	char temp_buff[51];//ok

	ChildrenShadow ch;

	while(!fin.eof()){
		fin.getline(buff,50);
		for(int i=0,j=0;i<51;i++){
			if(!id_find){
				if(buff[i]!=':'){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setID(atoi(temp.c_str()));
					id_find=true;
				}
				continue;
			}
			if(!fn_find){
				if(buff[i]!=':'){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setFirstName(temp);
					fn_find=true;
				}
				continue;
			}
			if(!sn_find){
				if(buff[i]!=' '){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setSecondName(temp);
					sn_find=true;
				}
				continue;
			}

			if(flag==1 || flag==2){
				bool find_children=false;
				if(flag==1 && ch.getFirstName()==namePart)
					find_children=true;
				if(flag==2 && ch.getSecondName()==namePart)
					find_children=true;
				if(find_children){
					if(size==0){
						size++;
						charr=new ChildrenShadow[size];
						charr[size-1]=ch;
					}
					else{
						ChildrenShadow *temparr=new ChildrenShadow[size];
						for(int s=0;s<size;s++){
							temparr[s]=charr[s];
						}
						size++;
						charr=new ChildrenShadow[size];
						for(int s=0;s<size-1;s++){
							charr[s]=temparr[s];
						}
						charr[size-1]=ch;
					}
				}

				for(int t=0;t<51;t++){
					temp_buff[t]=' ';
					buff[t]=' ';

				}

				id_find=false;
				fn_find=false;
				sn_find=false;

				break;			
			}
		}
	}

	ChildrenShadow *arr=new ChildrenShadow[size];
	
	for(int i=0;i<size;i++){
		arr[i]=charr[i];
	}

	fin.close();
	return arr;
}
ChildrenShadow* ChildrenFactory::find(int &size,std::string firstName,std::string secondName){
	ifstream fin("childrens.txt",ios_base::in);

	ChildrenShadow *charr;

	char buff[51];

	bool id_find=false;
	bool fn_find=false;
	bool sn_find=false;
	bool day_find=false;
	bool mon_find=false;
	bool year_find=false;

	char temp_buff[51];//ok

	ChildrenShadow ch;

	while(!fin.eof()){
		fin.getline(buff,50);
		for(int i=0,j=0;i<51;i++){
			if(!id_find){
				if(buff[i]!=':'){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setID(atoi(temp.c_str()));
					id_find=true;
				}
				continue;
			}
			if(!fn_find){
				if(buff[i]!=':'){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setFirstName(temp);
					fn_find=true;
				}
				continue;
			}
			if(!sn_find){
				if(buff[i]!=' '){
					temp_buff[j++]=buff[i];
				}
				else{
					temp_buff[j]='\0';
					j=0;
					std::string temp(temp_buff);
					ch.setSecondName(temp);
					sn_find=true;
				}
				continue;
			}

			bool find_children=false;
			if(ch.getFirstName()==firstName && ch.getSecondName()==secondName)
				find_children=true;
			if(find_children){
				if(size==0){
					size++;
					charr=new ChildrenShadow[size];
					charr[size-1]=ch;
				}
				else{
					ChildrenShadow *temparr=new ChildrenShadow[size];
					for(int s=0;s<size;s++){
						temparr[s]=charr[s];
					}
					size++;
					charr=new ChildrenShadow[size];
					for(int s=0;s<size-1;s++){
						charr[s]=temparr[s];
					}
					charr[size-1]=ch;
				}
			}

			for(int t=0;t<51;t++){
				temp_buff[t]=' ';
				buff[t]=' ';

			}

			id_find=false;
			fn_find=false;
			sn_find=false;

			break;			
		}
	}

	ChildrenShadow *arr=new ChildrenShadow[size];
	
	for(int i=0;i<size;i++){
		arr[i]=charr[i];
	}

	fin.close();
	return arr;
}

