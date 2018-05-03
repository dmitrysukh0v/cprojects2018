#pragma once
class Property
{
protected:
	double worth_;
public:
	Property(double worth);
	double getWorth();
	virtual double Calculation()=0;
};

