#pragma once
#ifndef REGI_H
#define REGI_H

#include "common.h"
#include "memo.h"

class regi
{
private:
	//int flag;//���ּĴ�������,flag = 0 AC�Ĵ�����flag = 1 DR����Ĵ�����flag = 2 IR ָ��Ĵ�����flag = 3 AR��ַ�Ĵ���
	string data;
public:
	regi();
	virtual ~regi();
	string  GetData();//���Ĵ�������
	void SetData(string);//�ı�Ĵ�������
};

class IRegi :public regi
{
public:
	vector<string> ins;
	vector<string>::iterator iter;
	vector<string> GetData();
	void SetData(memo);
};




#endif // !REGI_H

