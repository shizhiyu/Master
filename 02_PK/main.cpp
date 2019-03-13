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
	//设置随机数种子
	srand(time(NULL));
	cout << "欢迎来到天下第一武道大会" << endl;
	cout << "请选择你的英雄:" << endl;
	FileManeger fm;
	map<string, map<string, string>> mHero;
	fm.loadCSVData("Hero.csv", mHero);
	for (size_t i = 0; i < mHero.size(); i++)
	{
		cout << i + 1 << "、" << mHero[to_string(i + 1)]["heroName"] << " " << mHero[to_string(i + 1)]["heroInfo"] << endl;
	}
	int selected = 0;
	cin >> selected;
	getchar();//去掉缓冲区的回车
	
	//实例化一个英雄
	Hero hero(selected);
	cout << "你选的英雄是" << hero.heroName << endl;

	cout << "请选择你要装备的武器：" << endl;
	map<string, map<string, string>> mWeapon;
	fm.loadCSVData("Weapons.csv", mWeapon);
	cout << "0、赤手空拳" << endl;
	for (size_t i = 0; i < mWeapon.size(); i++)
	{
		cout << i + 1 << "、" << mWeapon[to_string(i + 1)]["weaponName"] << endl;
	}
	cin >> selected;
	getchar();//获取回车

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

	//英雄装备武器
	hero.EquipWeapon(weapon);

	//随机生成怪物
	map<string, map<string, string>> mMonster;
	fm.loadCSVData("Monsters.csv", mMonster);
	cout << mMonster.size() << endl;
	int id = rand() % mMonster.size() + 1;//1~5
	Monster monster(id);

	while (true)
	{
		system("cls");
		

		//英雄打怪物
		if (hero.heroHp > 0)
		{
			hero.Attack(&monster);
		}
		else
		{
			cout << "英雄一挂，请充值复活!" << endl;
			break;
		}

		//怪物打英雄
		if (monster.monsterHp > 0)
		{
			monster.Attack(&hero);
		}
		else
		{
			cout << "恭喜你过关，请充值解锁下一关!" << endl;
			break;
		}

		cout << "英雄<" << hero.heroName << ">剩余血量为:" << hero.heroHp << endl;
		cout << "怪物<" << monster.monsterName << ">剩余血量为:" << monster.monsterHp << endl;
		getchar();//按一下回车 干一架
	}

	system("pause");
	return EXIT_SUCCESS;
}