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
	cout << "Press 1 to create a new tracker, press 2 to update current tracker." << endl;
	int wi;
	cin >> wi;
	if (wi == 1)
	{
		cout << "Financial Information:" << endl << "Enter number of accounts: ";
		int na = 0;
		cin >> na;
		int i = 0;
		while(i<na)
		{
			char ws;
			ws = cin.get();
			string name;
			string type;
			double yeet;
			cout << "Enter account #"<<i+1<<" name"<<endl;
			getline(cin, name);
			cout << "Enter account #" << i + 1 << " type" << endl;
			getline(cin, type);
			cout << "Enter account #" << i + 1 << " balance" << endl;
			cin >> yeet;
			account y(yeet, type, name);
			bank.push_back(y);
			i++;
		}
		cout << "Upcoming Schedule:" << endl;
		cout << "Enter number of upcoming events: ";
		int nb;
		cin >> nb;
		cout << endl;
		for (int i = 0; i < nb; i++)
		{
			char ws;
			ws = cin.get();
			cout << "Enter the name of event #" << i+1 << ": ";
			string name;
			getline(cin, name);
			cout << "Enter the number of days until " << name << ": ";
			int yeet;
			cin >> yeet;
			events.add_event(name, yeet);
		}
		cout << "Fitness Goals:" << endl<<"Enter your goal calorie intake: "<<endl;
		double c;
		cin >> c;
		cout << "Enter you goal weight: ";
		double w;
		cin >> w;
		fitness y(c, w, 0);
		regime = y;
	}
}

int main()
{
	tracker* y =new tracker();
}
