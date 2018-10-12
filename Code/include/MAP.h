#ifndef MAP_H
#define MAP_H
#include<iostream>
using namespace std;

class MAP {
private:
	char map[100][100];
	int floor;

public:
	MAP();
	~MAP();
	void printmap();
	void changemap(int pos_x, int pos_y, char copy_);
	char getmap(int pos_x, int pos_y);
};

#endif
