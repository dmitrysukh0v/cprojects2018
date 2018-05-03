#pragma once

#include <string>

namespace School{
	class SchoolShadow
	{
	private:
		int id_;
		std::string name_;
		std::string adress_;
		std::string phone_;
	public:
		SchoolShadow();
		SchoolShadow(const SchoolShadow &obj);
		void setID(int id);
		int getID();
		void setName(std::string name);
		std::string getName();
		void setAdress(std::string adress);
		std::string getAdress();
		void setPhone(std::string phone);
		std::string getPhone();
	};
}

