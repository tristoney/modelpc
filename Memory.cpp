#include "Memory.h"



Memory::Memory(int sz):size(sz)
{
	data = new vector<string> [this->size];
}


Memory::~Memory()
{
	delete []data;
}

void Memory::SetData(vector<string> d, int addr)
{
	data[addr] = d;
}

vector<string> Memory::GetData(int addr)
{
	return data[addr];
}
