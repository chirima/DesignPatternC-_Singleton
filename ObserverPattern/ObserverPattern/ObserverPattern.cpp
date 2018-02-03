// ObserverPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Observer.h"

using namespace std;

class Person
{
private:
	int age;
public:
	int get_age() const
	{
		return age;
	}

	void set_age(int age)
	{
		Person::age = age;
	}
};

struct ConsolePersonObserver : public Observer<Person>
{
private:
	void field_changed(Person& source, const std::string& field_name) override
	{
		cout << "Person's" << field_name << "has changed to ";
		if (field_name == "age")
		{
			cout << source.get_age();
		}
		cout << "\n.";
	}
};

int main()
{
    return 0;
}

