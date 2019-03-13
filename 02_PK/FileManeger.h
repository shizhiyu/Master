#pragma once
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

class FileManeger
{
public:
	FileManeger();
	~FileManeger();

	//∂®“ÂloadCSVData
	void loadCSVData(string path, map<string, map<string, string>> &m);
	void praseLineToVector(string line, vector<string> &v);
};

