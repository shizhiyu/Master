#include "FileManeger.h"
#include<fstream>
#include<vector>

FileManeger::FileManeger()
{
}


FileManeger::~FileManeger()
{
}

void FileManeger::loadCSVData(string path, map<string, map<string, string>>& m)
{
	//���ļ�
	ifstream ifs;
	ifs.open(path);

	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��ȡ�ļ�����
	string firstLine;
	ifs >> firstLine;

	//����һ������ ������� fisrtV ��
	
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	vector<string> firstV;
	praseLineToVector(firstLine, firstV);

	//���з��� �Ժ����
	string otherLine;
	while (ifs >> otherLine)
	{
		//1,��ɪ,500,10,30,Ѫ�����
		vector<string> otherV;
		praseLineToVector(otherLine, otherV);

		//fisrtV ��ŵ�������  otherV���Եľ���ֵ
		map<string, string> m_t;
		for (size_t i = 0; i < firstV.size(); i++)
		{
			m_t.insert(make_pair(firstV[i], otherV[i]));//heroName----��ɪ
		}

		//��string --- m_t���뵽 m������ 1---m_t
		m.insert(make_pair(otherV[0], m_t));
	}
}

void FileManeger::praseLineToVector(string line, vector<string> &v)
{
	//line = monsterId,monsterName,monsterAtk,monsterDef,monsterHp
	int pos = 0;
	int start = 0;

	//���ҡ���������
	while (true)
	{
		pos = line.find(",", start);
		if (pos == -1)//δ�ҵ�
		{
			string tmp = line.substr(start, line.size() - start);
			v.push_back(tmp);
			break;
		}

		//�ҵ�
		string tmp = line.substr(start, pos - start);
		v.push_back(tmp);

		//��,����һ���ַ���ʼ����
		start = pos + 1;
	}

	return;
}



