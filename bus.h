#pragma once
class bus
{
private:	
	int data;//4λ16��������
public:
	bus(int Data);
	~bus();
	void WriteBus(int);
	int ReadBus();
};

