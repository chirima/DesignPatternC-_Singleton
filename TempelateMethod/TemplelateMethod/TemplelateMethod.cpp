// TemplelateMethod.cpp : Defines the entry point for the console application.
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

/* base class */
class Game
{
public:
	Game(int number_of_players) : number_of_players(number_of_players) {}

	void run()   /* Skeleton function to call all virtual function */
	{
		start();
		while (!have_winner())
		{
			take_turn();
		}
		cout << "Player " << get_winner() << " wins.\n";
	}
protected:
	int number_of_players;
	int current_player{ 0 };
	/* All functions defined as virtual in the base class */
	virtual void start() = 0;
	virtual bool have_winner() = 0;
	virtual void take_turn() = 0;
	virtual int get_winner() = 0;
};

/* Derived class */
class Chess : public Game
{
public:
	Chess() : Game(2) {};
protected:
	virtual void start() override
	{
		cout << "Starting a game of chess with " 
			<< number_of_players << " players\n";
	}
	virtual bool have_winner() override
	{
		return turn == max_turns;
	}
	virtual void take_turn() override
	{
		cout << "Turn " << turn << " takern by player " << current_player << "\n";
		++turn;
		current_player = (current_player + 1) % number_of_players;
	}
	virtual int get_winner() override
	{
		return current_player;
	}
private:
	int turn{ 0 }; 
	int max_turns{ 10 };
};

int main()
{
	Chess chess;
	chess.run();
    return 0;
}

