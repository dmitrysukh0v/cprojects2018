#include "StdAfx.h"
#include <iostream>
#include <time.h>
#include <sys\types.h>
#include <sys\timeb.h>
#include "ChildrenShadow.h"
#include "SchoolShadow.h"
#include "SchoolFactory.h"

using namespace Children;

ChildrenShadow::ChildrenShadow(){
	id_=0;
	schoolid_=0;
	firstName_=" ";
	secondName_=" ";
	dateOfBirth_.tm_mday=1;
	dateOfBirth_.tm_mon=1;
	dateOfBirth_.tm_year=1;
}
ChildrenShadow::ChildrenShadow(const ChildrenShadow &obj){
	//std::cout<<"Copy\n";
	setID(obj.id_);
	setFirstName(obj.firstName_);
	setSecondName(obj.secondName_);
	setDateOfBirth(obj.dateOfBirth_.tm_mday,obj.dateOfBirth_.tm_mon,obj.dateOfBirth_.tm_year);
	setSchoolID(obj.schoolid_);
}
ChildrenShadow::~ChildrenShadow(){
	//std::cout<<"Destroy\n";
}
void ChildrenShadow::setFirstName(std::string firstName){
	firstName_=firstName;
}
std::string ChildrenShadow::getFirstName(){
	return firstName_;
}
void ChildrenShadow::setSecondName(std::string secondName){
	secondName_=secondName;
}
std::string ChildrenShadow::getSecondName(){
	return secondName_;
}
void ChildrenShadow::setDateOfBirth(int day,int month,int year){
	dateOfBirth_.tm_mday=day;
	dateOfBirth_.tm_mon=month;
	dateOfBirth_.tm_year=year;
}
tm ChildrenShadow::getDateOfBirth(){
	return dateOfBirth_;
}
void ChildrenShadow::setSchoolID(int id){
	ChildrenShadow::schoolid_=id;
}
int ChildrenShadow::getSchoolID(){
	return ChildrenShadow::schoolid_;
}
int ChildrenShadow::getAge(){
	__time64_t now=time(NULL);
	tm tm_now;
	_localtime64_s(&tm_now,&now);
	return 2018-dateOfBirth_.tm_year;
}
ChildrenShadow ChildrenShadow::operator+(ChildrenShadow &obj){
	ChildrenShadow ch;
	ch.setDateOfBirth(0,0,getAge()+obj.getAge());
	return ch;
}

