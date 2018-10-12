#include"PACKAGE.h"
#include <iomanip>

PACKAGE::PACKAGE() {
	for (int i = 0; i < 6; i++)this->bag[i] = false;
	this->name[0] = "Weapon_Sword";
	this->name[1] = "Weapon_Shield";
	this->name[2] = "BUFF_HP";
	this->name[3] = "BUFF_Denfense";
	this->name[4] ="BUFF_life" ;
	this->name[5] = "BUFF_ATTACK";
}
PACKAGE::~PACKAGE(){}

void PACKAGE::ADD(char symbol)
{
	switch (symbol)
	{
	case 'S':
		this->bag[0] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have Weapon_Sword now!"<<endl;
		break;
	case 'T':
		this->bag[1] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have Weapon_Shield now!"<<endl;
		break;
	case 'A':
		this->bag[2] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have BUFF_HP now!"<<endl;
		break;
	case 'B':
		this->bag[3] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have BUFF_Denfense now!"<<endl;
		break;
	case 'C':
		this->bag[4] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have BUFF_life now!"<<endl;
		break;
	case 'D':
		this->bag[5] = true;
		std::cout << setfill(' ') << setw(82) << left << "You have BUFF_ATTACK now!"<<endl;
		break;
	}
	return;
}

bool PACKAGE::USING(int number)
{
	if (this->bag[number] == true) {
		this->bag[number] = false;
		system("cls");
		cout << "The " << this->name[number] << " is used.\n";
		return true;
	}
	else{
		system("cls");
		return false;
	}
}
