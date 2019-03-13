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
	int damage = 0;//�˺�
	int crit = 0;//����
	int addHp = 0;//��Ѫ
	int isFrozen = 0;//����

	if (this->pWeapon == NULL)//û������
	{
		damage = this->heroAtk;
	}
	else//������
	{
		damage = this->heroAtk + this->pWeapon->baseDamage;

		//��ȡ����
		crit = this->pWeapon->getCrit();
		if (crit > 0)
		{
			damage += crit;
			cout << "Ӣ��<" << this->heroName << ">�����˱������" << crit << "�����˺�" << endl;
		}

		//��ȡ��ѪЧ��
		addHp = this->pWeapon->getSuckBlood();
		if (addHp > 0)
		{
			cout << "Ӣ��<" << this->heroName << ">��������Ѫ�ָ�" << addHp << "Ѫ��" << endl;
		}

		//��ȡ����Ч��
		isFrozen = this->pWeapon->getFrozen();
		if (isFrozen)
		{
			cout << "Ӣ��<" << this->heroName << ">�����˱���"<< endl;
			monster->isFrozen = isFrozen;
		}	
	}

	//Ӣ�۹�������
	int trueDamage = (damage - monster->monsterDef) > 0 ? (damage - monster->monsterDef) : 1;
	monster->monsterHp -= trueDamage;
	cout << this->heroName << "����������" << trueDamage << "�˺���" << endl;

	//Ӣ����Ѫ
	this->heroHp += addHp;
}

void Hero::EquipWeapon(Weapon * weapon)
{
	if (weapon == NULL)
	{
		cout << "С�Ӻ�2333��������!" << endl;
	}
	else
	{
		this->pWeapon = weapon;
		cout << "<" << this->heroName << ">װ����<" << weapon->weaponName << ">!" << endl;
	}
	return;
}
