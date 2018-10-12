#ifndef player_h
#define player_h
#include<iostream>
#include"monster.h"
#include"global.h"
#include"PACKAGE.h"
using namespace std;

class PACKAGE;

class PLAY {
private:
	int HP;
	int ATK;
	int DEF;
	int pos_x;
	int pos_y;
	int life;
	bool alive;
	string name;
	int judge(int, int);
	char  pre;//记录这家伙进入该位置前时该位置的字符
	PACKAGE my_bag;

public:
	PLAY(string&);//构建对象
	~PLAY();

	void changechar(char);//改变pre
	char getpre();//获取pre

	void action(char);//作为输入的判断函数在进行下一步操作
	bool move(int,int);//单纯的移动函数，若是不能移动返回false和原因(用0-5来表示)
	
	int gethp();
	int getdef();
	int getatk();
	int getx();
	int gety();
	int getlife();
	string getname();

	void changehp(int);
	void changedef(int);
	void changeatk(int);
	void changedirection(int, int);
	void changelife(int);

	int findmonster(int, int);//根据坐标找怪物的下标
	void attack(int);//初步作为进攻怪物函数（利用怪物的下标进行锁定）
	void be_attack(int);
	
	void openpackage();//打开背包
	void getting(char);//获取物品
	void usingpackage(int);//使用背包内物品
	
	void displaying();//打印玩家基本信息
	
	bool isalive();//判断死了没有
	
};

#endif
