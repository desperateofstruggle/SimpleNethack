#include"WEAPON.h"

SWORD::SWORD(int num) {
	this->number = num;
}
SWORD::~SWORD(){}
int SWORD::getting() {
	return this->number;
}

SHIELD::SHIELD(int num) {
	this->number = num;
}
SHIELD::~SHIELD(){}
int SHIELD::getting() {
	return this->number;
}
