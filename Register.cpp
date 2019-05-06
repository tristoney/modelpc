#include "Register.h"



Register::Register(string n,int d):name(n),data(d)
{	
}


Register::~Register()
{
}

int Register::GetData()
{
	return data;
}

void Register::SetData(int Data)
{
	this->data = Data;
}

string Register::GetName()
{
	return name;
}

void Register::Reset()
{
	SetData(0);
}

ProgramCounterReg::ProgramCounterReg(string name, int data):Register(name,data)
{
}

ProgramCounterReg::~ProgramCounterReg()
{
}

void ProgramCounterReg::inc()
{
	int d = GetData();
	SetData(d + 1);
}


ProgramStatusReg::ProgramStatusReg(string name, int data, int cf, int zf, int sf, int of)
	:Register(name,data),cf(cf),zf(zf),sf(sf),of(of)
{

}

ProgramStatusReg::~ProgramStatusReg()
{
}

int ProgramStatusReg::GetCF()
{
	return cf;
}

int ProgramStatusReg::GetZF()
{
	return zf;
}

int ProgramStatusReg::GetSF()
{
	return sf;
}

int ProgramStatusReg::GetOF()
{
	return of;
}

void ProgramStatusReg::SetCF(int data)
{
	this->cf = data;
}

void ProgramStatusReg::SetZF(int data)
{
	this->zf = data;
}

void ProgramStatusReg::SetSF(int data)
{
	this->sf = data;
}

void ProgramStatusReg::SetOF(int data)
{
	this->of = data;
}

void ProgramStatusReg::Reset()
{
	cf = 0, zf = 0, sf = 0, of = 0;
}
