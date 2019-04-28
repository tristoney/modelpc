#pragma once
#ifndef BUS_H
#define BUS_H

#include "common.h"
class bus
{
private:
	string data;//4位16进制整数
public:
	bus(string Data);
	~bus();
	void WriteBus(string);
	string ReadBus();
};

#endif // !BUS_H



