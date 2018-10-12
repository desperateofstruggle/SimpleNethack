#include"monster.h"
#include"player.h"
#include <iomanip>
#include<string>
#include<sstream>
template <typename T>
std::string to_string(T value) {
	ostringstream oss;
	oss << value;
	return oss.str();
}
int max(int a, int b) {
	if (a < 0)a *= -1;
	if (b < 0)b *= -1;
	return (a > b) ? a : b;
}
MONSTER::MONSTER(int x, int y, int hp, int def, int atk,int ming) {
	this->ATK = atk;
	this->DEF = def;
	this->HP = hp;
	this->life = ming;
	this->pos_x = x;
	this->pos_y = y;
	this->pre = maps.getmap(x, y);
	this->pre = '.';
}
MONSTER::~MONSTER() {
	cout << setfill(' ') << setw(82) << left << "monster is killed!"<<endl;
}

bool MONSTER::ishere(int x, int y) {
	if (x == this->pos_x&&y == this->pos_y)return true;
	else return false;
}
bool MONSTER::isalive() {
	if (this->life >= 1) {
		return true;
	}
	else {
		return false;
	}
}

//怪物寻径
void MONSTER::move(PLAY &target) {
	int nearest = 9999, min = 9999;
	if (max(this->pos_x - target.getx(), this->pos_y - target.gety())>15)return;
	if (max(this->pos_x - target.getx(), this->pos_y - target.gety()) == 1) {
		this->attack(target);
		return;
	}
	int next_x = 9999, next_y = 9999;
	for (int X = -1; X < 2; X++) {
		for (int Y = -1; Y < 2; Y++) {
			if (maps.getmap(X + this->pos_x, Y + this->pos_y) == 'M'||maps.getmap(X + this->pos_x, Y + this->pos_y) == ' ' || maps.getmap(X + this->pos_x, Y + this->pos_y) == '|' || maps.getmap(X + this->pos_x, Y + this->pos_y) == '-')continue;
			nearest = max((this->pos_x + X - target.getx()), (this->pos_y + Y - target.gety()));
			if (min > nearest) {
				min = nearest;
				next_x = X;
				next_y = Y;
			}
		}
	}
	if ((next_x != 9999) && (next_y != 9999)) {
		maps.changemap(this->pos_x, this->pos_y, this->pre);
		this->pos_x += next_x;
		this->pos_y += next_y;
		changepre(maps.getmap(pos_x, pos_y));
		maps.changemap(pos_x, pos_y, 'M');
	}
}

//被攻击函数
void MONSTER::beattacking(int beATK) {
	if (beATK - DEF > 0) {
		HP = HP - beATK + DEF;
	}
	if (this->gethp() <= 0) {
		this->changelife(this->getlife() - 1);
		if (!(this->isalive())) {
			cout  << setfill(' ')<< setw(82)<<left<<"This monster is killed by you!"<<endl;
			maps.changemap(pos_x, pos_y, pre);
			return;
		}
		else{
			this->changehp(5);
			cout << setfill(' ') << setw(82) << left << "You have killed one life of the monster!"<<endl;
			string out = "The monster still has " + to_string(this->getlife()) + " lives and still has " + to_string(this->gethp()) + " now!";
			cout << setfill(' ') << setw(82) << left << out << endl;
			return;
		}
	}
	else{
		string out = "The monster still has " + to_string(this->getlife()) + " lives and still has " + to_string(this->gethp()) + " now!";
		cout << setfill(' ') << setw(82) << left << out << endl;
		//cout << setfill(' ')<< setw(82)  << left << "This monster still has " << this->gethp() << " HP and " << this->getlife()<< " lives now!"<<endl;
		return;
	}
}

//进攻玩家函数
void MONSTER::attack(PLAY& target) {
	target.be_attack(this->ATK);
	return;
}

//获取数据
int MONSTER::gethp() {
	return this->HP;
}
int MONSTER::getdef() {
	return this->DEF;
}
int MONSTER::getatk() {
	return this->ATK;
}
int MONSTER::getx() {
	return this->pos_x;
}
int MONSTER::gety() {
	return this->pos_y;
}
int MONSTER::getlife() {
	return this->life;
}
char MONSTER::getpre() {
	return this->pre;
}

//更改数据
void MONSTER::changehp(int hp) {
	this->HP = hp;
}
void MONSTER::changedef(int def) {
	this->DEF = def;
}
void MONSTER::changeatk(int atk) {
	this->ATK = atk;
}
void MONSTER::changedirection(int x, int y) {
	this->pos_x = x;
	this->pos_y = y;
}
void MONSTER::changelife(int life) {
	this->life = life;
}
void MONSTER::changepre(char PRE) {
	this->pre = PRE;
}
