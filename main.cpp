#include "common.h"
#include "memo.h"
#include "bus.h"
#include "regi.h"

memo Memo[1000];

regi AC,DR,IR,AR;

int main()
{
	int PC = 0;//PC初始化为0
	int TF = 0;//控制
	int i = 0;//存储参数
	fstream file;
	file.open("asm.txt", ios::in);
	if (!file)
	{
		cerr << "file open failed!" << endl;
		exit(1);
	}
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string word;
		memo tmp;
		while (ss >> word)
		{
			tmp.data.push_back(word);
		}
		Memo[i++] = tmp;
	}
	file.close();


	int start = 0;
	int pause = 0;
	cout << "Press 1 to start working" << endl;
	cin >> start;
	if (start)
	{
		cout << "Please chose the working mode:" << endl;
		cout << "0 : single-step mode" << endl;
		cout << "1 : result-only mode" << endl;
		cin >> TF;
		switch (TF)
		{
		case 0:
			cout << "PC = " << PC << endl;
			cout << "AC = " << AC.GetData() << ',' << "DR = " << DR.GetData() << ',' << 
				"IR = " << 
		}
	}
}
