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
	char  pre;//��¼��һ�����λ��ǰʱ��λ�õ��ַ�
	PACKAGE my_bag;

public:
	PLAY(string&);//��������
	~PLAY();

	void changechar(char);//�ı�pre
	char getpre();//��ȡpre

	void action(char);//��Ϊ������жϺ����ڽ�����һ������
	bool move(int,int);//�������ƶ����������ǲ����ƶ�����false��ԭ��(��0-5����ʾ)
	
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

	int findmonster(int, int);//���������ҹ�����±�
	void attack(int);//������Ϊ�������ﺯ�������ù�����±����������
	void be_attack(int);
	
	void openpackage();//�򿪱���
	void getting(char);//��ȡ��Ʒ
	void usingpackage(int);//ʹ�ñ�������Ʒ
	
	void displaying();//��ӡ��һ�����Ϣ
	
	bool isalive();//�ж�����û��
	
};

#endif
