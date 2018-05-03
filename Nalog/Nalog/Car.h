#pragma once

#include "Property.h"

class Car : public virtual Property
{
public:
	Car(double worth):Property(worth){}
	double Calculation();
};

