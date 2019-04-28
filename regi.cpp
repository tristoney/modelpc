#include "regi.h"



regi::regi(int Flag, int Data) :flag(0), data(0x0)
{
	flag = Flag;
	data = Data;
}


regi::~regi()
{

}

int regi::GetData()
{
	return data;
}

void regi::SetData(int Data)
{
	this->data = Data;
}