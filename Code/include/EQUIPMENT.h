#ifndef EQUIPMENT_H
#define EQUIPMENT_H

const int Initial_H = 5;//加血量
const int Initial_F = 1;//加命量
const int Initial_R = 1;//攻击量
const int Initial_D = 1;//防御量

//HP
class ADD_HP {
private:
	int number;

public:
	ADD_HP(int number = Initial_H);
	~ADD_HP() ;
	int getting();
};

//ATTACK
class ADD_R {
private:
	int number;

public:
	ADD_R(int number = Initial_R);
	~ADD_R();
	int getting();
};

//LIFE
class ADD_F {
private:
	int number;

public:
	ADD_F(int number = Initial_F);
	~ADD_F();
	int getting();
};

//DEFENCE
class ADD_D {
private:
	int number;

public:
	ADD_D(int number=Initial_D);
	~ADD_D();
	int getting();
};

#endif
