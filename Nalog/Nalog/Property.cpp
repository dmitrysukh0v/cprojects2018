#include "StdAfx.h"
#include "Property.h"

double Property::getWorth(){
	return worth_;
}
Property::Property(double worth){
	worth_=worth;
}
