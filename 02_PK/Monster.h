#pragma once
#include<iostream>
using namespace std;
class Hero;
class Monster
{
public:
	Monster();
	~Monster();
	Monster(int monsterId);
	void Attack(Hero *hero);
public:
	string monsterName;
	int monsterHp;
	int monsterAtk;
	int monsterDef;
	bool isFrozen;

};

