
#pragma once
#ifndef PROCESSER_H
#define PROCESSER_H
#include "common.h"
#include "Register.h"

class Processer
{
private:
	int reg_a;
	int reg_b;
	int reg_ans;
	ProgramStatusReg &reg_ps;//Ϊ������ָ��
public:
	Processer(int , int, int, ProgramStatusReg&);
	~Processer();
	int GetRa();
	int GetRb();
	int GetRans();
	void SetRa(int a);
	void SetRb(int b);
	void SetRans(int ans);
	void add();
	void sub();
	void cmp();
	void Reset();
};


#endif // !PROCESSER_H


