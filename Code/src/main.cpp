#include<iostream>
#include<string>
#include <conio.h>
#include<iomanip>
#include"player.h"
#include"global.h"

using namespace std;

//��Ϸ���
void details() {
	cout << "��ӭ��������ĵ������磬�������ֻ��Ҫ���һ���򵥵������Ǿ��ǣ�"<<endl;
	cout << "1.������" << endl;
	cout << "2.�����ŷ���ȡ��Yendor������" << endl;
	cout << "ǰ���ɣ�ɧ�꣡(��Ȼ��������Ĵ���)��\n";
}

//���������
void directionhelp() {
	cout << "'w'/'W'����up\n";
	cout << "'s'/'S'����down\n";
	cout << "'a'/'A'����left\n";
	cout << "'d'/'D'����right\n";
	cout << "'q'/'Q'����left-up\n";
	cout << "'e'/'E'����right-up\n";
	cout << "'z'/'Z'����left-down\n";
	cout << "'c'/'C'����right-down\n";
}
//��������ʹ��˵��
void usingfun(PLAY& play) {
	cout << "THIS IS THE USING SYSTEM OF " << play.getname() << "'s PACKAGE:\n";
	cout << "You can take it to use your equipment or weapon(use enter botton):\n";
	cout << "0����Weapon_Sword\n";
	cout << "1����Weapon_Shield\n";
	cout << "2����BUFF_HP\n";
	cout << "3����BUFF_Denfense\n";
	cout << "4����BUFF_life\n";
	cout << "5����BUFF_ATTACK\n";
}
void basusingfun() {
	cout << "You can take it to do what you desire to do:\n";
	cout << "o����check your package\n";
	cout << "u����use your equipment or your weapon in your package\n";
	cout << "h����to know what the direction button is\n";
	cout << "m����details about this game\n";
}
//�̶��������ɺ���
void createmonster() {
	monsters[0] = new MONSTER(21, 1,3,2,2,1);
	monsters[1] = new MONSTER(21, 4, 3, 3, 2, 1);
	monsters[2] = new MONSTER(41,16,3,3,3,1);
	monsters[3] = new MONSTER(43, 15, 3, 3, 3, 1);
	monsters[4] = new MONSTER(53, 9, 4, 3, 4, 1);
	monsters[5] = new MONSTER(55, 8, 4, 3, 4, 1);
	monsters[6] = new MONSTER(71, 9, 5, 3, 3, 1);
	monsters[7] = new MONSTER(71, 11, 5, 4, 3, 1);
	monsters[8] = new MONSTER(73,3,5,4,3,1);
	monsters[9] = new MONSTER(76,1,5,4,3,1);
	monsters[10] = new MONSTER(78, 2, 5, 3, 3, 1);
	monsters[11] = new MONSTER(34,1,5,2,3,2);
	monsters[12] = new MONSTER(41,1,3,2,3,2);
	monsters[13] = new MONSTER(7,10,8,3,5,1);
	monsters[14] = new MONSTER(7,12,4,3,4,2);
	monsters[15] = new MONSTER(1,3,5,5,4,3);
	monsters[16] = new MONSTER(2,2,5,5,4,2);
	monsters[17] = new MONSTER(5,3,5,5,4,1);
}

int main() {
	for (int i = 0; i < 10; i++) {
		monsters[i] = NULL;
	}

	//�ж���Ϸ��С���顱�������
	int flag = 0;
	int flag1 = 0;
	
	//��������
	string namne;
	details();
	cout << "name:";
	cin >> namne;
	system("cls");
	PLAY person(namne);

	//�������������
	createmonster();

	while (person.isalive()) {
		maps.printmap();
		person.displaying();
		basusingfun();
		char c = getch();
		system("cls");
		switch (c)
		{
		case 'o':
			system("cls");
			cout << "THIS IS " << person.getname() << "'s PACKAGE:\n";
			person.openpackage(); 
			cout << "Press 'q' to exit!(Press Enter botton to continue)\n";
			char d;
			cin >> d;
			while (d != 'q'){
				cin >> d;
			}
			system("cls");
			break;
		
		case 'h':
			directionhelp();
			cout << "Enter 'q' to exit!(Press Enter botton to continue)\n";
			char p ;
			cin >> p;
			while (p != 'q') {
				system("cls");
				directionhelp();
				cout << "Enter 'q' to exit!(Press Enter botton to continue)\n";
				cin >> p;
			}
			system("cls");
			break;
		
		case 'm':details(); break;

		case'u':
			system("cls");
			usingfun(person);
			int n;
			cin >> n;
			person.usingpackage(n);
			break;

		case'w':
		case'W':
		case's':
		case'S':
		case'a':
		case'A':
		case'd':
		case'D':
		case'q':
		case'Q':
		case'e':
		case'E':
		case'z':
		case'Z':
		case'c':
		case'C':
			person.action(c); 
			if (maps.getmap(1, 2) == '@') {
				flag = 1;
				break;
			}
			for (int i = 0; i < 20; i++) {
				if (monsters[i] == NULL)continue;
				else {
					(*(monsters[i])).move(person);
				}
			}
			break;

		default:cout << setfill(' ') << setw(82) << left << "invalid input���Ƿ����룬�޴˲�������"<<endl;
			break;
		}
		if (!person.isalive()) {
			cout << "It's too sad to tell you,you're dead!\nG   M   A   E     O   V   E   R    !   !   !\n";
			break;
		}
		if (flag == 1) {
			cout << "YOU WIN!!!"<<endl;
			cout << "�ŷ���ǳ���л�㣬���������ɧ��ƺŽ���ˣ���˵:'�´��ټ�����'" << endl;
			break;
		}
			
		
		if (monsters[13]==NULL && monsters[14]==NULL&&flag1==0) {
			maps.changemap(1, 5, '.');
			cout << "The last door to the necklace of Yendor is opened."<<endl;
			flag1 = 1;
		}

		for (int i = 0; i < 20; i++) {
			if (monsters[i] == NULL)continue;
			if (!(*(monsters[i])).isalive()) {
				delete monsters[i];
				monsters[i] = NULL;
			}
		}
	}

	
	//����ͷ��ڴ�
	for (int i = 0; i < 20; i++) {
		if (monsters[i] == NULL)continue;
		if (!(*(monsters[i])).isalive()) {
			delete monsters[i];
			monsters[i] = NULL;
		}
	}
	system("pause");
	system("pause");
	return 0;
}
