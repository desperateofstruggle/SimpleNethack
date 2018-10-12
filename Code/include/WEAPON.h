#ifndef WEAPON_H
#define WEAPON_H

const int Initial_SWORD = 1;
const int Initial_SHIELD = 2;

class SWORD {
private:
	int number;

public:
	SWORD(int number = Initial_SWORD);
	~SWORD();
	int getting();
};

class SHIELD {
private:
	int number;

public:
	SHIELD(int number = Initial_SHIELD);
	~SHIELD();
	int getting();
};

#endif
