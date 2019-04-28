#include "regi.h"



regi::regi():data()
{	
}


regi::~regi()
{
}

string regi::GetData()
{
	return data;
}

void regi::SetData(string Data)
{
	this->data = Data;
}

vector<string> IRegi::GetData()
{
	return ins;
}

void IRegi::SetData(memo Ins)
{
	while (Ins.iter != Ins.data.end())
	{
		this->ins.push_back(Ins.GetData(Ins.iter));
	}
}