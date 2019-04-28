#pragma once
class bus
{
private:	
	int data;//4位16进制整数
public:
	bus(int Data);
	~bus();
	void WriteBus(int);
	int ReadBus();
};

