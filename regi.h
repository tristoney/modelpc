#pragma once
#ifndef REGI_H
#define REGI_H

#include "common.h"
#include "memo.h"

class regi
{
private:
	//int flag;//区分寄存器类型,flag = 0 AC寄存器，flag = 1 DR缓冲寄存器，flag = 2 IR 指令寄存器，flag = 3 AR地址寄存器
	string data;
public:
	regi();
	virtual ~regi();
	string  GetData();//读寄存器数据
	void SetData(string);//改变寄存器数据
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

