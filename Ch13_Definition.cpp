#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

class Employee
{
public:
	// constructor
	Employee():name("NoName"), id(counter)
		{ ++ counter; }
	Employee( std::string EmName ):name(EmName), id(counter)
		{ ++ counter; }
	Employee( const Employee& other ):name(other.name), id(counter)
		{ ++ counter; }
	Employee& operator= (const Employee& other)
	{
		name = other.name;
		return *this;
	}
private:
	std::string name;
	unsigned int id;
	static int counter;
};

int Employee::counter = -1;

class Employer
{
public:
	Employer():name("NoName")
		{ setID(); }
	Employer( std::string EmName ):name(EmName)
		{ setID(); }
	Employer( const Employer& other ):name(other.name)
		{ setID(); }
	Employer& operator= (const Employer& other)
	{
		name = other.name;
		return *this;
	}
	~Employer();
private:
	std::string name;
	std::string id;
	static int counter;
	void setID()
	{
		++counter;
		id = "Employer-";
		if ( counter < 10 )
			id += "000";
		else if ( counter < 100 )
			id += "00";
		else if ( counter < 1000 )
			id += "0";
		else
			std::cerr << "No valid Employer ID input!" << std::endl;
		char buffer[5];
		itoa( counter, buffer, 10 );
		id += buffer;
		// stringstream ss;
		// ss << counter;
		// id += ss.str();
	}
};

int Employer::counter = -1;

int main()
{
    return 0;
}
