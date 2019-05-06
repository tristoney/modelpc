#pragma once
#ifndef REGI_H
#define REGI_H

#include "common.h"

class Register//�Ĵ�������
{
private:
	int data;
	string name;//�Ĵ�����
public:
	Register(string n,int d);
	virtual ~Register();
	int  GetData();//���Ĵ�������
	void SetData(int);//�ı�Ĵ�������
	string GetName();//�õ��Ĵ�������
};

class ProgramCounterReg :public Register//�����������
{
public:
	ProgramCounterReg(string name, int data);
	~ProgramCounterReg();
	void inc();
	void reset();
};

class ProgramStatusReg :public Register
{
private:
	int cf;//0,1
	int zf;//0,1
	int sf;//0,1
	int of;//0,1
public:
	ProgramStatusReg(string name, int data, int cf = 0, int zf = 0, int sf = 0, int of = 0);
	~ProgramStatusReg();
	int GetCF();
	int GetZF();
	int GetSF();
	int GetOF();
	void SetCF(int data);
	void SetZF(int data);
	void SetSF(int data);
	void SetOF(int data);
	void Reset();
};





#endif // !REGI_H

