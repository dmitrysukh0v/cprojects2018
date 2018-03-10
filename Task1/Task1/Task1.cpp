// Task1.cpp: главный файл проекта.

#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include <string>

#define H_MAX 24
#define MS_MAX 60

using namespace std;

//taking the abs
int mod(int n){
	return (n>=0) ? n : -n;
}

class Time{
public:
	int hour;
	int minute;
	int second;

	Time(){}
	Time(int h,int m,int s){
		try{
			if((h>(H_MAX-1) || h<0) || (m>(MS_MAX-1) || m<0) || (s>(MS_MAX-1) || s<0))
				throw 0;
		}
		catch(int err){
			cout<<"Uncorrect parameter!"<<endl;
			system("pause");
			exit(0);
		}
		hour=h;
		minute=m;
		second=s;
	}
	int ConvertToSecond(){
		return this->hour * MS_MAX * MS_MAX+this->minute * MS_MAX+this->second;
	}
	
	Time GetDiff(Time t2){
		int h,m,s;

		int f_time=this->ConvertToSecond();
		int s_time=t2.ConvertToSecond();

		int result=f_time-s_time;

		h=result / (MS_MAX*MS_MAX);
		result-=h * (MS_MAX*MS_MAX);

		m=result / MS_MAX;
		result-=m * MS_MAX;

		s=result;

		return Time(mod(h),mod(m),mod(s));
	}
	//getting a string representation of time
	string GetStr(){
		string res;
		if(hour<10)
			res.append("0");
		res.append(to_string((long long)hour));
		res.append(":");
		if(minute<10)
			res.append("0");
		res.append(to_string((long long)minute));
		res.append(":");
		if(second<10)
			res.append("0");
		res.append(to_string((long long)second));
		return res;
	}
};

void CharTimeToInt(char *arg,int time){

}

int main(int argc, char *argv[])
{

	Time *t1p,*t2p;

	if(argc==7){
		t1p=new Time(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]));
		t2p=new Time(atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));

		cout<<"Parameters entered:"<<endl<<t1p->GetStr()<<endl<<t2p->GetStr()<<endl;
		Time res=t1p->GetDiff(*t2p);

		cout<<"Difference: "<<res.GetStr()<<endl;
	}
	else
		cout<<"Error! Parameters are not entered or their number is not equal to 6"<<endl;

	system("pause");

    return 0;
}
