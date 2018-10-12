#include"player.h"
#include"global.h"
#include <cctype>
#include<iomanip>
#include<sstream>
const int initial_HP = 20;
const int initial_ATK = 5;
const int initial_DEF = 2;
const int initial_x = 20;
const int initial_y = 1;
const int initial_pre = '.';
const int initial_life = 2;
template <typename T>
std::string to_string(T value) {
	ostringstream oss;
	oss << value;
	return oss.str();
}
PLAY::PLAY(string& name_) {
	name = name_;
	pos_x = initial_x;
	pos_y = initial_y;
	HP = initial_HP;
	ATK = initial_ATK;
	DEF = initial_DEF;
	pre = initial_pre;
	life = initial_life;
	alive = true;
}
PLAY::~PLAY() {
	cout << "销毁玩家完毕\n";
}

bool PLAY::isalive() {
	if (this->life >= 1) {
		return true;
	}
	else {
		return false;
	}
}
void PLAY::attack(int symbol) {
	(*monsters[symbol]).beattacking(this->ATK );
	if (!(*monsters[symbol]).isalive()) {
		delete monsters[symbol];
		monsters[symbol] = NULL;
	}
	return;
}

void PLAY::be_attack(int beATK) {
	if (beATK - this->getdef() > 0) { 
		this->changehp(this->getdef()-beATK); 
	}
	else{
		cout << setfill(' ') << setw(82) << left << "You successfully defensed!\n"<<endl;
		return;
	}
	if (this->gethp() <= 0) {
		this->changelife( - 1);
		this->HP = initial_HP;
		if (!(this->isalive())) {
			alive = false;
			cout << "Killed!\n";
			return;
		}
		else{
			cout << setfill(' ') << setw(82) << left << "Your lives is  decreased!"<<endl;
			return;
		}
	}
	else {
		cout << setfill(' ') << setw(82) << left << "Your HP is decreased!"<<endl;
		return;
	}
}

int PLAY::findmonster(int x, int y) {
	for (int i = 0; i < 20; i++) {
		if (monsters[i]==NULL)continue;
		if (!(*(monsters[i])).ishere(x, y)) continue;
		else {
			return i;
		}
	}
}

void PLAY::action(char act) {
	switch (act)
	{
	case 'w':
	case 'W':
		if(!move(0,-1)){
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）"<<endl;
		}
		break;

	case's':
	case'S':
		if (!move(0,1)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）"<<endl;
		}
		break;

	case'a':
	case'A':
		if (!move(-1,0)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）"<<endl;
		}
		break;

	case'd':
	case'D':
		if (!move(1,0)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）" << endl;
		}
		break;

	case'q':
	case'Q':
		if (!move(-1,-1)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）" << endl;
		}
		break;

	case'e':
	case'E':
		if (!move(1,-1)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）" << endl;
		}
		break;

	case'z':
	case'Z':
		if (!move(-1,1)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）" << endl;
		}
		break;

	case'c':
	case'C':
		if (!move(1,1)) {
			cout << setfill(' ') << setw(82) << left << "Please enter again（请再次输入）" << endl;
		}
		break;

	default:
		break;
	}
}

//0是墙 1是路 2是怪物 3是装备或道具 4是小钥匙 5是其他 6是通关
bool PLAY:: move(int x,int y) {
	switch (judge(pos_x+x,pos_y+y))
	{
	case 0 :return false;
	case 1:
		maps.changemap(pos_x, pos_y, getpre());
		pos_x += x;
		pos_y += y;
		changechar(maps.getmap(pos_x, pos_y));
		maps.changemap(pos_x, pos_y, '@');
		return true;

	case 2:
		attack(this->findmonster(pos_x + x, pos_y + y));
		return true;

	case 3:
		my_bag.ADD(maps.getmap(pos_x + x, pos_y + y));
		maps.changemap(pos_x, pos_y, getpre());
		pos_x += x;
		pos_y += y;
		changechar('.');
		maps.changemap(pos_x, pos_y, '@');
		return true;
	
	case 4:
		maps.changemap(72, 4, '-');
		maps.changemap(44, 1, '.');
		maps.changemap(9, 11, '#');
		maps.changemap(pos_x, pos_y, getpre());
		maps.changemap(21, 3, 'M');
		maps.changemap(21, 2, 'M');
		monsters[18] = new MONSTER(21, 3, 1, 2, 3, 5);
		monsters[19] = new MONSTER(21, 2, 1, 2, 3, 4);
		pos_x += x;
		pos_y += y;
		changechar('.');
		maps.changemap(pos_x, pos_y, '@');
		cout << "You got the fragment of the necklace of Yendor,now you check carefully of the map and tried to continue to get the entired necklace!\n";
		return true;

	case 5:
		cout << setfill(' ') << setw(82) << left << "不可前进区域。"<<endl;
		return false;
	
	case 6:
		cout << setfill(' ') << setw(82) << left << "找到圣石了！！！！！！！！！"<<endl;
		return true;

	default:return false;
		break;
	}
}

//0是墙 1是路 2是怪物 3是装备或道具 4是小钥匙 5是其他 6是通关钥匙
int PLAY::judge(int x, int y) {
	if (maps.getmap(x, y) == '-' || maps.getmap(x, y) == '|') {
		cout << "Is the wall. ";
		return 0;
	}
	else if(maps.getmap(x, y) == '#'|| maps.getmap(x, y) == '.'){
		return 1;
	}
	else if(maps.getmap(x, y) == 'M'){
		return 2;
	}
	else if(isalpha(maps.getmap(x, y))&& maps.getmap(x, y) != 'M'&&maps.getmap(x, y) != 'k'){
		return 3;
	}
	else if (maps.getmap(x, y) == 'k') {
		return 4;
	}
	else if(maps.getmap(x, y) == ' '){
		return 5;
	}
	else if (maps.getmap(x, y) == 'K') {
		return 6;
	}
}

void PLAY::openpackage() {
	cout << this->my_bag;
}
void PLAY::getting(char symbol) {
	my_bag.ADD(symbol);
}
void PLAY::usingpackage(int symbol) {
	if (my_bag.USING(symbol)) {
		switch (symbol)
		{
		case 0:ATK = ATK + my_bag.get_sword(); break;
		case 1:DEF = DEF + my_bag.get_shield(); break;
		case 2:
			if(this->HP<=15) HP = HP + my_bag.get_hp(); 
			else HP = 20;
			break;
		case 3:DEF = DEF + my_bag.get_d(); break;
		case 4:life = life + my_bag.get_f(); break;
		case 5:ATK = ATK + my_bag.get_r(); break;
		default:
			break;
		}
	}
	else {
		cout << setfill(' ') << setw(82) << left << "Your don't have this equipment or weapon"<<endl;
	}
	
}

//对之前位置所在字符的操作函数
void PLAY::changechar(char newone) {
	pre = newone;
}
char PLAY::getpre() {
	return pre;
}

//各种获取数据 
int PLAY::gethp() {
	return this->HP;
}
int PLAY::getdef() {
	return this->DEF;
}
int PLAY::getatk() {
	return this->ATK;
}
int PLAY::getx() {
	return this->pos_x;
}
int PLAY::gety() {
	return this->pos_y;
}
int PLAY::getlife() {
	return this->life;
}
string PLAY::getname() {
	return this->name;
}

//一堆改变数据的函数
void PLAY::changehp(int hp) {
	this->HP += hp;
}
void PLAY::changedef(int def) {
	this->DEF += def;
}
void PLAY::changeatk(int atk) {
	this->ATK += atk;
}
void PLAY::changedirection(int x, int y) {
	this->pos_x += x;
	this->pos_y += y;
}
void PLAY::changelife(int tlife) {
	this->life += tlife;
}

//基本数据(HP、DEF等)的print函数
void PLAY::displaying() {
	string out1 = "Your basical information: HP: " + to_string(this->gethp()) +"/20"+ " ATK: " + to_string(this->getatk()) + " DEF: " + to_string(this->getdef()) + " LIVES: " + to_string(this->getlife());
	cout << setfill(' ') << setw(82) << left << out1<< endl;
	string out2 = "Your coordinate is ( " + to_string(this->getx()) + " , " + to_string(this->gety()) + " )";
	cout << setfill(' ') << setw(82) << left << out2<< endl;
}
