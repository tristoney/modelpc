#pragma once
#ifndef MEMO_H
#define MEMO_H

#include "common.h"

class memo
{
public:
	vector<string> data;
	vector<string>::iterator iter;
	memo();
	~memo();
	string GetData(vector<string>::iterator);
};


#endif // !MEMO_H