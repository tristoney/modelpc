#pragma once
#ifndef MEMORY_H
#define MEMIRY_H

#include "common.h"
class Memory
{
private:
	int size;//ÄÚ´æ´óÐ¡£¨×Ö£©
public:
	vector<string> *data;
	Memory(int size);
	~Memory();
	void SetData(string value, int addr);
	vector<string> GetData(int addr);
	void Reset();
};
#endif // !MEMORY_H

