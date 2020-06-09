#ifndef TRACKERH
#define TRACKERH
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;





class account {
public:
	account(double start, string kind, string nombre);
	void alter(double amount, bool deposit);

private:
	double value;
	string type;
	string name;
};

class schedule {
public:
	schedule() { ; }
	void add_event(string name, int until);
	int lookup(string name);

private:
	map<string, int> upcoming;


};

class fitness {
public:
	fitness(double cal, double weight, int days_straight);
	fitness() { ; }
	void exercise(int amount, string type);
	void eat(double amount);

	

private:
	double goal_c=0;
	double goal_w=0;
	int need_rest=0;

};


class tracker {
public:
	tracker();
	void add_event(string yo, int yi) { events.add_event(yo, yi); }

private:
	vector<account> bank;
	schedule events;
	fitness regime;
};





#endif
