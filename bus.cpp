#include "bus.h"


bus::bus(string Data):data ()
{
	data = Data;
}


bus::~bus()
{
}


void bus::WriteBus(string Data)
{
	this->data = Data;
}

string bus::ReadBus()
{
	return data;
}