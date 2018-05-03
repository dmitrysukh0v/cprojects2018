#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "SchoolFactory.h"

using namespace std;

void SchoolFactory::create(SchoolShadow *scSh){
	ofstream fout("schools.txt",ios_base::app);

	fout<<scSh->getID()<<":"<<
		scSh->getName()<<":"<<
		scSh->getAdress()<<" "<<
		scSh->getPhone()<<":\n";

	fout.close();
}
int SchoolFactory::getUniqueID(){
	ifstream fin("schools.txt",ios_base::in);
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
SchoolShadow SchoolFactory::findByID(int id){
	ifstream fin("schools.txt",ios_base::in);

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

	SchoolShadow scSh;

	bool id_find=false;
	bool name_find=false;
	bool adr_find=false;
	bool ph_find=false;

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
				scSh.setID(atoi(temp.c_str()));
				id_find=true;
			}
			continue;
		}
		if(!name_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				scSh.setName(temp);
				name_find=true;
			}
			continue;
		}
		if(!adr_find){
			if(buff[i]!=' '){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				scSh.setAdress(temp);
				adr_find=true;
			}
			continue;
		}
		if(!ph_find){
			if(buff[i]!=':'){
				temp_buff[j++]=buff[i];
			}
			else{
				temp_buff[j]='\0';
				j=0;
				std::string temp(temp_buff);
				scSh.setPhone(temp);
				ph_find=true;
			}
			continue;
		}
		for(int t=0;t<51;t++){
			temp_buff[t]=' ';
		}
	}

	fin.close();
	return scSh;
}