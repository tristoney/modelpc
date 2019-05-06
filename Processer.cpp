#include "Processer.h"




Processer::Processer(int ra, int rb, int rans, ProgramStatusReg& rps)
	:reg_a(ra),reg_b(rb),reg_ans(rans),reg_ps(rps)
{
}


Processer::~Processer()
{
}

int Processer::GetRa()
{
	return reg_a;
}

int Processer::GetRb()
{
	return reg_b;
}

int Processer::GetRans()
{
	return reg_ans;
}

void Processer::SetRa(int a)
{
	reg_a = a;
}

void Processer::SetRb(int b)
{
	reg_b = b;
}

void Processer::SetRans(int ans)
{
	reg_ans = ans;
}

void Processer::add()
{
	reg_ans = reg_a + reg_b;
}

void Processer::sub()
{
	reg_ans = reg_a- reg_b;
}

void Processer::cmp()
{
	int flag = (reg_a == reg_b);
	//cout << "compare flag is: " << flag << endl;
	reg_ps.SetZF(flag);
	//cout << "ZF = " << reg_ps.GetZF() << endl;
}
