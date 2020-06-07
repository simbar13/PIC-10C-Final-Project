#ifndef TRACKERH
#define TRACKERH
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class tracker {
public:


private:
	vector<account> bank;
	schedule events;
	fitness regime;
};




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
	void exercise(int amount, string type);
	void eat(double amount);

	

private:
	double goal_c;
	double goal_w;
	int need_rest;

};






#endif
