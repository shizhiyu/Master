#include "Knife.h"
#include"FileManeger.h"


Knife::Knife()
{
	//从武器文件中导入小刀的数据
	FileManeger fm;
	map<string, map<string, string>> m;

	fm.loadCSVData("Weapons.csv", m);

	//将小刀的数据 放入 Knife成员中
	string id = m["1"]["weaponId"];

	this->weaponName = m[id]["weaponName"];
	this->baseDamage = atoi(m[id]["weaponAtk"].c_str()) ;
	this->critPlus = atoi(m[id]["weaponCritPlus"].c_str());
	this->critRate = atoi(m[id]["weaponCritRate"].c_str());
	this->suckPlus = atoi(m[id]["weaponSuckPlus"].c_str());
	this->suckRate = atoi(m[id]["weaponSuckRate"].c_str());
	this->frozenRate = atoi(m[id]["weaponFrozenRate"].c_str());
}


Knife::~Knife()
{
}

int Knife::getBaseDamage()
{
	return this->baseDamage;
}

int Knife::getCrit()
{
	if (this->isTrigger(this->critRate))
	{
		return this->baseDamage * this->critPlus;
	}
	return 0;
}

int Knife::getSuckBlood()
{
	if (this->isTrigger(this->suckRate))
	{
		return this->baseDamage * this->suckPlus;
	}
	return 0;
}

int Knife::getFrozen()
{
	if (this->isTrigger(this->frozenRate))
	{
		return 1;
	}
	return 0;
}

bool Knife::isTrigger(int rate)
{
	int num = rand() % 100;
	if (num < rate)
	{
		return true;
	}

	return false;
}
