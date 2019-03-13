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
	//打开文件
	ifstream ifs;
	ifs.open(path);

	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//读取文件数据
	string firstLine;
	ifs >> firstLine;

	//分析一行数据 并存放在 fisrtV 中
	
	//heroId,heroName,heroHp,heroAtk,heroDef,heroInfo
	vector<string> firstV;
	praseLineToVector(firstLine, firstV);

	//逐行分析 以后的行
	string otherLine;
	while (ifs >> otherLine)
	{
		//1,亚瑟,500,10,30,血厚防高
		vector<string> otherV;
		praseLineToVector(otherLine, otherV);

		//fisrtV 存放的是属性  otherV属性的具体值
		map<string, string> m_t;
		for (size_t i = 0; i < firstV.size(); i++)
		{
			m_t.insert(make_pair(firstV[i], otherV[i]));//heroName----亚瑟
		}

		//将string --- m_t放入到 m容器中 1---m_t
		m.insert(make_pair(otherV[0], m_t));
	}
}

void FileManeger::praseLineToVector(string line, vector<string> &v)
{
	//line = monsterId,monsterName,monsterAtk,monsterDef,monsterHp
	int pos = 0;
	int start = 0;

	//先找‘，’逗号
	while (true)
	{
		pos = line.find(",", start);
		if (pos == -1)//未找到
		{
			string tmp = line.substr(start, line.size() - start);
			v.push_back(tmp);
			break;
		}

		//找到
		string tmp = line.substr(start, pos - start);
		v.push_back(tmp);

		//从,号下一个字符开始查找
		start = pos + 1;
	}

	return;
}



