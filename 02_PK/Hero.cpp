#include "Hero.h"
#include"FileManeger.h"
#include"weapon.h"
#include"Monster.h"
Hero::Hero()
{
}


Hero::~Hero()
{
}

Hero::Hero(int heroId)
{
	FileManeger fm;
	map<string, map<string, string>> m;
	fm.loadCSVData("Hero.csv", m);

	this->heroName = m[to_string(heroId)]["heroName"];
	this->heroInfo = m[to_string(heroId)]["heroInfo"];
	this->heroAtk = atoi(m[to_string(heroId)]["heroAtk"].c_str());
	this->heroDef = atoi(m[to_string(heroId)]["heroDef"].c_str());
	this->heroHp = atoi(m[to_string(heroId)]["heroHp"].c_str());
	this->pWeapon = NULL;

}

void Hero::Attack(Monster * monster)
{
	int damage = 0;//伤害
	int crit = 0;//暴击
	int addHp = 0;//吸血
	int isFrozen = 0;//冰冻

	if (this->pWeapon == NULL)//没有武器
	{
		damage = this->heroAtk;
	}
	else//有武器
	{
		damage = this->heroAtk + this->pWeapon->baseDamage;

		//获取暴击
		crit = this->pWeapon->getCrit();
		if (crit > 0)
		{
			damage += crit;
			cout << "英雄<" << this->heroName << ">触发了暴击造成" << crit << "暴击伤害" << endl;
		}

		//获取吸血效果
		addHp = this->pWeapon->getSuckBlood();
		if (addHp > 0)
		{
			cout << "英雄<" << this->heroName << ">触发了吸血恢复" << addHp << "血量" << endl;
		}

		//获取冰冻效果
		isFrozen = this->pWeapon->getFrozen();
		if (isFrozen)
		{
			cout << "英雄<" << this->heroName << ">触发了冰冻"<< endl;
			monster->isFrozen = isFrozen;
		}	
	}

	//英雄攻击怪物
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueDamage;
	cout << this->heroName << "攻击怪物，造成" << trueDamage << "伤害！" << endl;

	//英雄吸血
	this->heroHp += addHp;
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL)
	{
		cout << "小子很2333，等死吧!" << endl;
	}
	else
	{
		this->pWeapon = weapon;
		cout << "<" << this->heroName << ">装备了<" << weapon->weaponName << ">!" << endl;
	}
	return;
}
