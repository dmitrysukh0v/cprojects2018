#include "StdAfx.h"
#include <string>
#include "SchoolShadow.h"

using namespace School;

SchoolShadow::SchoolShadow(){
}
SchoolShadow::SchoolShadow(const SchoolShadow &obj){
	setID(obj.id_);
	setName(obj.name_);
	setAdress(obj.adress_);
	setPhone(obj.phone_);
}
void SchoolShadow::setID(int id){
	SchoolShadow::id_=id;
}
int SchoolShadow::getID(){
	return SchoolShadow::id_;
}
void SchoolShadow::setName(std::string name){
	SchoolShadow::name_=name;
}
std::string SchoolShadow::getName(){
	return SchoolShadow::name_;
}
void SchoolShadow::setAdress(std::string adress){
	SchoolShadow::adress_=adress;
}
std::string SchoolShadow::getAdress(){
	return SchoolShadow::adress_;
}
void SchoolShadow::setPhone(std::string phone){
	SchoolShadow::phone_=phone;
}
std::string SchoolShadow::getPhone(){
	return SchoolShadow::phone_;
}
