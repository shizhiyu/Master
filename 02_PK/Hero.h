#pragma once
#include<iostream>

using namespace std;
//��ǰ����
class Monster;
class Weapon;
class Hero
{
public:
	Hero();
	~Hero();
	Hero(int heroId);

	void Attack(Monster *monster);
	void EquipWeapon(Weapon *weapon);
public:
	int heroHp;
	int heroAtk;
	int heroDef;
	string heroName;
	string heroInfo;
	Weapon *pWeapon;

};

