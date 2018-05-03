#pragma once

#include "Property.h"

class CountryHouse : public virtual Property
{
public:
	CountryHouse(double worth):Property(worth){}
	double Calculation();
};

