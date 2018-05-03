#pragma once
ref class ChildrenShadow{
private:
	int _id;
	string _firstName;
	string _secondName;
	struct tm _dateOfBirth;
public:
	ChildrenShadow(int id,string firstName,string secondName,tm dateOfBirth);
	int getID();
	string getFirstName();
	string getSecondName();
	tm getDateOfBirth();
	int getAge();

	void setID(int id);
	void setFirstName(string firstName);
	void setSecondName(string secondName);
	void setDateOfBirth(tm dateOfBirth);
};

