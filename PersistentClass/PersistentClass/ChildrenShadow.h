#pragma once

#include <string>
#include <time.h>
#include "ElementShadow.h"
#include "SchoolShadow.h"

namespace Children{
	class ChildrenShadow : public ElementShadow
	{
	private:
		int id_;
		int schoolid_;
		std::string firstName_;
		std::string secondName_;
		struct tm dateOfBirth_;
	public:
		ChildrenShadow();
		ChildrenShadow(const ChildrenShadow &obj);
		~ChildrenShadow();
		void setFirstName(std::string firstName);
		std::string getFirstName();
		void setSecondName(std::string secondName);
		std::string getSecondName();
		void setDateOfBirth(int day,int month,int year);
		std::tm getDateOfBirth();
		int getAge();
		void setSchoolID(int id);
		int getSchoolID();
		ChildrenShadow operator+(ChildrenShadow &obj);
	};
}

