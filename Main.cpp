#include <iostream>
#include <string>
#include "windows.h"
#include "PlayerClass.h"
#include "EnemyClass.h"
using namespace std;

Player User;
Player *UserPtr = &User;
EnemyClass Wolf;
EnemyClass *WolfPtr = &Wolf;
bool IsWolfDead{ false };
bool IsPlayerDead{ false };

//DONE: Recursive function doesn't work for AskClass(), find alternate way to show stats and have confirmation screen. (Reason it doesn't work might be because its returning a value to the function itself rather than the main function.)
//Add arrays for class stats.
//Use polymorphism and create an enemy class to create a combat system before progressing code any further.
//May need to reorganize code. Need to concatinate the convoluted fight code into a single function, if possible. May need a class for "current values", base unit class? Other stuff to be determined.
//Most important: Not assigning classes correctly. Class of the object isn't kept after the if statement. Figure out fix.
//To fix: Dynamic Class assigning

int AskClass() {
	string PickClass{};
	string confirm{};
	cout << "Please select a class:" << endl;
	cout << "Warrior, Mage, Ranger" << endl;
	cin >> PickClass;
	int *ClassPtr = &User.GClass;
	if (PickClass == "Warrior") {
		cout << "You have selected warrior. Your initial damage is 10, health is 150, power is 0, and speed is 5. " << endl;
		return 1;
	}

	if (PickClass == "Mage") {
		cout << "You have selected mage. Your initial damage is 5, health is 100, power is 10, and speed is 5." << endl;
		return 2;
	}

	if (PickClass == "Ranger") {
		cout << "You have selected ranger. Your initial damage is 20, health is 75, power is 0, and speed is 10." << endl;
		return 3;
	}
}

int Attack(Player y, EnemyClass x) {
	y.CurrentHealth = y.CurrentHealth - x.damage;
	return y.CurrentHealth;
}

Player *PlayerPtr = &User;

void BeginCombat() {
	cout << "Your abilities are " << endl;
}



void ContinueCombatWolf() {
	string PlayerTurn{};
	cout << "Your turn. 'Hit' or 'Run'?" << endl;
	cin >> PlayerTurn;
	if (PlayerTurn == "Hit") {
		Wolf.CurrentHealth = Wolf.CurrentHealth - User.Strike();
		cout << "Wolf has " << Wolf.CurrentHealth << " health remaining." << endl;
		if (Wolf.CurrentHealth <= 0) {
			IsWolfDead = true;
		};
	}
	if (PlayerTurn == "Run") {
		Sleep(200);
		cout << "Run away failed!" << endl;
	}
	if (User.CurrentHealth <= 0) {
		IsPlayerDead = true;
	};
	//Try polymorphism when wolf is a derived class of enemyclass.
	if (IsWolfDead == false) {
		User.CurrentHealth = User.CurrentHealth - Wolf.Roar();
		cout << "You have " << User.CurrentHealth << " health remaining." << endl;
	};
};



int main() {
	cout << "Test Game" << endl;
	User.GClass = AskClass();
	cout << "Do you accept this class?" << endl;
	string accept{};
	cin >> accept;
	if (accept == "No") {
		while (accept == "No") {
			User.GClass = AskClass();
			cout << "Do you accept this class?" << endl;
			cin >> accept;

		}
	}
	if (User.GClass == 1) {
		cout << "You are a warrior." << endl;
		User.MaxHealth = 150;
		User.CurrentHealth = 150;
		User.PhysDmg = 20;
	}
	if (User.GClass == 2) {
		cout << "You are a mage." << endl;
		User.MaxHealth = 100;
		User.CurrentHealth = 100;
		User.PhysDmg = 5;
	}
	if (User.GClass == 3) {
		cout << "You are a ranger." << endl;
		User.MaxHealth = 75;
		User.CurrentHealth = 75;
		User.PhysDmg = 15;
	}
	cout << "This game is a work in progress and is limited to the console using cout. Your journey begins in a forest. You see three paths ahead of you. What would you like to do?" << endl;
	cout << "You can type: 'Left', 'Right', or 'Middle'" << endl;
	string path{};
	cin >> path;
	if (path == "Left") {
		cout << "You went left." << endl;
		Sleep(1000);
		cout << "You're ambushed by a wolf! The wolf has 50 health, and 20 damage." << endl;
		Wolf.CurrentHealth = 50;
		Sleep(300);
		User.CurrentHealth = Attack(User, Wolf);
		cout << "The wolf attacks you first." << endl;
		cout << "Wolf deals " << Wolf.damage << " damage to you. Your health is now " << User.CurrentHealth << endl;
		Sleep(350);
		cout << "What do you do?" << endl;
		Sleep(200);
		cout << "'Hit', 'Run'" << endl;
		string Action{};
		cin >> Action;
		if (Action == "Hit") {
			Wolf.CurrentHealth = Wolf.CurrentHealth - User.Strike();
			Sleep(350);
			cout << "Wolf has " << Wolf.CurrentHealth << " health left." << endl;
		}
		if (Action == "Run") {
			cout << "Run away failed!" << endl;
		}
		cout << "Wolf's turn: " << endl;
		WolfPtr->PRoar(User.CurrentHealth);
		while ((Wolf.CurrentHealth > 0) && User.CurrentHealth > 0) {
			ContinueCombatWolf();
		};
		if (Wolf.CurrentHealth <= 0) {
			cout << "Fight over!" << endl;
		};
		if (User.CurrentHealth <= 0) {
			Sleep(200);
			cout << "You have died!" << endl;
			Sleep(800);
			cout << "Game over." << endl;
		};


	}
	if (path == "Right") {
		cout << "You went right.";
	}
	if (path == "Middle") {
		cout << "You went through the middle path.";
	}
	system("pause");
}