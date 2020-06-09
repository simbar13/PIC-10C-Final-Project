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

void fitness::exercise(double amount, char type)
{
	if (type == 'r')
		goal_c -= amount * 650;
	if (type == 'w')
		goal_c -= amount * 180;
	if (type == 's')
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

void tracker::update_tracker()
{
	bool continuer = 1;
	while (continuer)
	{

		cout << "Would you like to update your current tracker? (y/n)" << endl;
		char hi;
		cin >> hi;
		if (hi == 'n')
			return;
	
		cout << "What aspect of your tracker would you like to update?" << endl << "Finance (press 1), Schedule (press 2), Fitness, (press 3)" << endl;
		int which;
		cin >> which;
		cout << endl;
		switch (which) {
		case 1:
		{cout << "You selected finance, please enter the name of the account you wish to modify: ";
		char ws;
		ws = cin.get();
		string name = "";
		getline(cin, name);
		cout << "Are you making a withdrawl (press w) or a deposit (press d)?" << endl;
		char c;
		cin >> c;
		cout << "Enter the value you would like to change this account by: " << endl;
		double d;
		cin >> d;
		int a = bank.size();
		for (int i = 0; i < a; i++)
		{
			if (bank[i].getname() == name)
			{
				if (c == 'w')
					bank[i].alter(d, 0);
				else
					bank[i].alter(d, 1);
			}

		}
		}
		break;

		case 2:
		{
			cout << "You selected Schedule, would you like to add an event (press a) or find the timing of an event (press t)?" << endl;
			char maybe;
			cin >> maybe;
			if (maybe == 'a')
			{
				char ws;
				ws = cin.get();
				cout << "Enter the name of your new event: ";
				string name;
				getline(cin, name);
				cout << endl << "How many days until " << name << "? ";
				int days;
				cin >> days;
				add_event(name, days);
				cout << "You added " << name << " which occurs in " << days << " days" << endl;
			}
			else if (maybe == 't')
			{
				cout << "Enter the name of the event you want to look up: ";
				char ws;
				ws = cin.get();
				string name;
				getline(cin, name);
				cout << "There are " << till_event(name) << " days until " << name << endl;
			}


		}
		break;

		case 3:
		{
			cout << "You selected fitness." << endl;
			cout << "Did you exercise (press x) or eat (press e)?";
			char c;
			cin >> c;
			if (c == 'x')
			{
				cout << endl<<"What type of exercise did you do (press r for running, s for surfing, or w for weights)?";
				char type;
				cin >> type;
				cout <<endl<< "For how many hours did you exercise?";
				double d;
				cin >> d;
				regime.exercise(d, type);
			}
			if (c == 'e')
			{
				cout << endl << "How many calories did you eat?";
				double d;
				cin >> d;
				regime.eat(d);
			}
		}
			break;

		default:
			break;
		}
	}
}

int main()
{
	tracker* y =new tracker();
	y->update_tracker();
}
