#pragma once
#include "weapon.h"
class BoardSword :public Weapon
{
public:

	BoardSword();
	~BoardSword();

	//��ȡ�����˺�
	virtual int getBaseDamage();
	//����Ч�� ����ֵ����0 ��������
	virtual int getCrit();
	//��ȡ��Ѫ ����ֵ����0 ������Ѫ
	virtual int getSuckBlood();
	//����Ч�� ����true �������
	virtual int getFrozen();

	//��������
	virtual bool isTrigger(int rate);
};

