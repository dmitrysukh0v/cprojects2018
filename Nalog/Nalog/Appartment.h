#pragma once

#include "Property.h"

class Appartment : public virtual Property
{
public:
	Appartment(double worth):Property(worth){}
	double Calculation();
};

