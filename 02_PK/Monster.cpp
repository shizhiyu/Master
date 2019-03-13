#include "Monster.h"
#include"FileManeger.h"
#include"Hero.h"

Monster::Monster()
{
}


Monster::~Monster()
{
}

Monster::Monster(int monsterId)
{
	FileManeger fm;
	map<string, map<string, string>> m;

	fm.loadCSVData("Monsters.csv", m);

	this->monsterName = m[to_string(monsterId)]["monsterName"];
	this->monsterAtk = atoi(m[to_string(monsterId)]["monsterAtk"].c_str());
	this->monsterDef = atoi(m[to_string(monsterId)]["monsterDef"].c_str());
	this->monsterHp = atoi(m[to_string(monsterId)]["monsterHp"].c_str());
	this->isFrozen = false;
}

void Monster::Attack(Hero * hero)
{
	//ÅÐ¶Ï¹ÖÎïÊÇ·ñ±»±ù¶³
	if (this->isFrozen)
	{
		cout << "¹ÖÎï<" << this->monsterName << ">±»±ù¶³£¬Í£Ö¹Ò»»ØºÏ¹¥»÷!" << endl;
		this->isFrozen = false;
		return;
	}

	//ÕæÊµÉËº¦
	int damage = 0;
	damage = (this->monsterAtk - hero->heroDef)>0?(this->monsterAtk - hero->heroDef):1;

	//¹¥»÷
	hero->heroHp = hero->heroHp - damage;
	cout << "¹ÖÎï<" << this->monsterName << "> ¹¥»÷Ó¢ÐÛ<" << hero->heroName << ">Ôì³É" << damage << "ÉËº¦!" << endl;
}
