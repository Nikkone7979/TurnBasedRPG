#pragma once
#include "PlayerClass.h"
#include <iostream>
#include <string>
using namespace std;
class EnemyClass :
	public Player
{
public:

	EnemyClass();
	int health{ 50 };
	int damage{ 20 };
	int power{ 0 };
	int speed{ 5 };
	virtual int SetInitialHealth() {
		return 100;
		}
	void PRoar(int x) {
		x = x - (power + 50);
			cout << "Wolf roars at you. " << "It deals " << (power + 50) << " damage." <<  " Your health is now " << x << endl;
		}
	int Roar() {
		cout << "The enemy wolf roars at you, dealing " << (power + 50) << " damage." << endl;
		return power + 50;

	}
};

