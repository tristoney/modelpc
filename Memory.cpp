#include "Memory.h"



Memory::Memory(int sz):size(sz)
{
	data = new vector<string> [this->size];
}


Memory::~Memory()
{
	delete []data;
}

void Memory::SetData(string value, int addr)
{
	vector<string>().swap(data[addr]);
	data[addr].push_back(value);
}

vector<string> Memory::GetData(int addr)
{
	return data[addr];
}

void Memory::Reset()
{
	for (int i = 0; i < size; i++)
		vector<string>().swap(data[i]);//清空内存字单元
}
