#ifndef monster_h
#define monster_h
#include<iostream>
#include"global.h"
using namespace std;

class PLAY;

class MONSTER{
private:
	int HP;
	int ATK;
	int DEF;
	int pos_x;
	int pos_y;
	int life;
	char pre;

public:
	MONSTER(int x=2,int y=2,int hp=2,int def=2,int atk=2,int ming=1);
	~MONSTER();
	bool ishere(int, int);
	bool isalive();
	void move(PLAY&);

	int gethp();
	int getdef();
	int getatk();
	int getx();
	int gety();
	int getlife();
	char getpre();

	void changehp(int);
	void changedef(int);
	void changeatk(int);
	void changedirection(int, int);
	void changelife(int);
	void changepre(char);

	void attack(PLAY&);
	void beattacking(int);
};


#endif/*monster.h*/
