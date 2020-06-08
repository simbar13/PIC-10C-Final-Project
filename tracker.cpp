#include <sstream>
#include "tracker.h"



account::account(double start, string kind, string nombre)
{
	value = start;
	type = kind;
	nombre = name;
}

void account::alter(double amount, bool deposit)
{
	if (deposit)
		value += amount;
	else
		value -= amount;
}

void schedule::add_event(string name, int until)
{
	upcoming.insert(pair<string, int>(name, until));
	
}

int schedule::lookup(string name)
{
	return upcoming[name];
}

fitness::fitness(double cal, double weight, int days_straight)
{
	goal_c = cal;
	goal_w = weight;
	need_rest = 5 - days_straight;
	if (need_rest <= 0)
		cout << "Consider Taking a Rest Day";
}

void fitness::exercise(int amount, string type)
{
	if (type == "running")
		goal_c -= amount * 100;
	if (type == "strength")
		goal_c -= amount * 180;
	if (type == "surfing")
		goal_c -= 250 * amount;
}

void fitness::eat(double amount)
{
	goal_c += amount;
}

tracker::tracker()
{
	cout << "Financial Information:" << endl << "Enter number of accounts: ";
	int na;
	cin >> na;
	cout << endl;
	for (int i = 0; i < na; i++)
	{
		cout << "Enter account name, hit return, enter account type, hit return, and then enter account balance for account #" << i << ": ";
		string name;
		getline(cin, name);
		string type;
		getline(cin, type);
		double yeet;
		cin >> yeet;
		account y(yeet, type, name);
		bank.push_back(y);
	}
	cout << "Upcoming Schedule:" << endl;
}

