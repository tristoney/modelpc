#include "bus.h"



bus::bus(int Data):data (0x0)
{
	data = Data;
}


bus::~bus()
{
}

void WriteBus(int Data)
{
	this->data = Data;
}

int ReadBus()
{
	return data;
}