// ObserverPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Observer.h"
#include "Observable.h"

using namespace std;

class Person : public Observable<Person> // Observable
{
private:
	int age;
public:
	Person(int age) { Person::age = age; }
	int get_age() const
	{
		return age;
	}

	void set_age(int age)
	{
		if (this->age == age)
		{
			return;
		}
		this->age = age;
		string field_name = "age";
		notify(*this, field_name);
	}
};

struct ConsolePersonObserver : public Observer<Person> // Observer
{
private:
	void field_changed(Person& source, const std::string& field_name) override
	{
		cout << "Person's " << field_name << " has changed to ";
		if (field_name == "age")
		{
			cout << source.get_age();
		}
		cout << ".\n";
	}
};

int main()
{
	Person person{ 10 };
	ConsolePersonObserver cpo;

	person.subscribe(cpo);
	person.set_age(11);
	person.set_age(12);
	person.unsubscribe(cpo);
	person.set_age(13);
	return 0;
}

