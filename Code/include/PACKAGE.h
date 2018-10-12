#ifndef PACKAGE_h
#define PACKAGE_h
/*
S——剑
T——盾

A——加生命的buff
B——加防御的buff
C——加攻击的buff
D——加怒气的buff
*/
#include<iostream>
#include<string>
#include"EQUIPMENT.h"
#include"WEAPON.h"

class PLAY;
class SWORD;
class SHIELD;
class ADD_HP;
class ADD_R;
class ADD_F;
class ADD_D;

using namespace std;

class PACKAGE{
private:
	SWORD sword;//0
	SHIELD shield;//1
	ADD_HP add_hp;//2
	ADD_D add_d;//3
	ADD_F add_f;//4
	ADD_R add_r;//5

	bool bag[6];
	string name[6];

public:
	PACKAGE();
	~PACKAGE();
	friend ostream &operator <<(ostream& os, const PACKAGE& p) {
		string op = "this is your bag:\n";
		for (int i = 0; i < 6; i++)
			if (p.bag[i] == true)
				op += p.name[i] + "\n";
		os << op;
		return os;
	}
	void ADD(char);
	bool USING(int number);
	int get_sword() { return (this->sword).getting(); }
	int get_shield() { return (this->shield).getting();}
	int get_hp() { return (this->add_hp).getting(); }
	int get_d() { return (this->add_d).getting(); }
	int get_f() { return (this->add_f).getting(); }
	int get_r() { return (this->add_r).getting(); }
};

#endif
