#include "memo.h"



memo::memo():iter(data.begin())
{

}

memo::~memo()
{

}

string GetData(vector<string>::iterator iter)
{
	return *iter;
}