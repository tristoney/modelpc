#pragma once
class regi
{
private:
	int flag;//���ּĴ�������,flag = 0 AC�Ĵ�����flag = 1 DR����Ĵ�����flag = 2 IR ָ��Ĵ�����flag = 3 AR��ַ�Ĵ���
	int data;//4λ16����
public:
	regi(int,int);
	~regi();
	int  GetData();//���Ĵ�������
	void SetData(int);//�ı�Ĵ�������
};

