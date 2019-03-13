#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"FileManeger.h"
#include"Hero.h"
#include"Knife.h"
#include"boardSword.h"
#include"dragonSword.h"
#include"Monster.h"
#include<ctime>
using namespace std;

int main(int *argc, char *argv[])
{
	//�������������
	srand(time(NULL));
	cout << "��ӭ�������µ�һ������" << endl;
	cout << "��ѡ�����Ӣ��:" << endl;
	FileManeger fm;
	map<string, map<string, string>> mHero;
	fm.loadCSVData("Hero.csv", mHero);
	for (size_t i = 0; i < mHero.size(); i++)
	{
		cout << i + 1 << "��" << mHero[to_string(i + 1)]["heroName"] << " " << mHero[to_string(i + 1)]["heroInfo"] << endl;
	}
	int selected = 0;
	cin >> selected;
	getchar();//ȥ���������Ļس�
	
	//ʵ����һ��Ӣ��
	Hero hero(selected);
	cout << "��ѡ��Ӣ����" << hero.heroName << endl;

	cout << "��ѡ����Ҫװ����������" << endl;
	map<string, map<string, string>> mWeapon;
	fm.loadCSVData("Weapons.csv", mWeapon);
	cout << "0�����ֿ�ȭ" << endl;
	for (size_t i = 0; i < mWeapon.size(); i++)
	{
		cout << i + 1 << "��" << mWeapon[to_string(i + 1)]["weaponName"] << endl;
	}
	cin >> selected;
	getchar();//��ȡ�س�

	Weapon *weapon = NULL;
	switch (selected)
	{
	case 0:
		weapon = NULL;
		break;
	case 1:
		weapon = new Knife;
		break;
	case 2:
		weapon = new BoardSword;
		break;
	case 3:
		weapon = new DragonSword;
		break;
	}

	//Ӣ��װ������
	hero.EquipWeapon(weapon);

	//������ɹ���
	map<string, map<string, string>> mMonster;
	fm.loadCSVData("Monsters.csv", mMonster);
	cout << mMonster.size() << endl;
	int id = rand() % mMonster.size() + 1;//1~5
	Monster monster(id);

	while (true)
	{
		system("cls");
		

		//Ӣ�۴����
		if (hero.heroHp > 0)
		{
			hero.Attack(&monster);
		}
		else
		{
			cout << "Ӣ��һ�ң����ֵ����!" << endl;
			break;
		}

		//�����Ӣ��
		if (monster.monsterHp > 0)
		{
			monster.Attack(&hero);
		}
		else
		{
			cout << "��ϲ����أ����ֵ������һ��!" << endl;
			break;
		}

		cout << "Ӣ��<" << hero.heroName << ">ʣ��Ѫ��Ϊ:" << hero.heroHp << endl;
		cout << "����<" << monster.monsterName << ">ʣ��Ѫ��Ϊ:" << monster.monsterHp << endl;
		getchar();//��һ�»س� ��һ��
	}

	system("pause");
	return EXIT_SUCCESS;
}