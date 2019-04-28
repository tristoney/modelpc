#pragma once
class regi
{
private:
	int flag;//区分寄存器类型,flag = 0 AC寄存器，flag = 1 DR缓冲寄存器，flag = 2 IR 指令寄存器，flag = 3 AR地址寄存器
	int data;//4位16进制
public:
	regi(int,int);
	~regi();
	int  GetData();//读寄存器数据
	void SetData(int);//改变寄存器数据
};

