// Singleton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

class SingletonDatabase
{
private:
	map<string, int> capitals;
	SingletonDatabase()                        /* Constructor */
	{
		cout << "Initializing Database\n";
		ifstream ifs("capitals.txt");          /* read text file to get city and population */

		string city, population;

		while (getline(ifs, city))             /* read inidivisual line, get city */
		{
			getline(ifs, population);          /* read inidivisual line, get population */
			int pop = stoi(population);
			capitals[city] = pop;
		}
	}
public:
	SingletonDatabase(SingletonDatabase const&) = delete;
	void operator=(SingletonDatabase const&) = delete;

	static SingletonDatabase& get()             /* Get reference of Singleton database */
	{
		static SingletonDatabase db;
		return db;
	}

	int getPopulation(const string& name)       /* function to get city's population */
	{
		return capitals[name];
	}
};

int main()
{
	string city = "Tokyo";
	cout << city << " has population " <<
		SingletonDatabase::get().getPopulation(city) << "\n";    /* Direct access to singleton class */
    return 0;
}

