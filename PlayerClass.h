#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include <iostream>
#include <string>
using namespace std;
class Player
{
public:
	Player();
	int MaxHealth{ 100 };
	int CurrentHealth{100};
	int GClass{};
	int PhysDmg{ 10 };
	int Strike() {
		cout << "You strike the target with your weapon, dealing " << (PhysDmg + 5) << " damage." << endl;
		return PhysDmg + 5;

	}

};


#endif