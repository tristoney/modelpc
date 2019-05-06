#include "common.h"
#include "Controller.h"
#include "Memory.h"
#include "Processer.h"
#include "Register.h"

Memory memory(1024);
Register ra("ra",0);
Register rb("rb", 0);
ProgramCounterReg rpc("rpc",0);
ProgramStatusReg rps("rps", 0);

Processer processer(0, 0, 0, rps);
Controller controller(memory, processer, ra, rb, rpc, rps);

int main()
{
	cout << "\n\n\n\n";
	cout << "				Welcome to my model-pc!" << endl;
	cout << "				Press 1 to get start!" << endl;
	cout << "				Press 0 to get quit!" << endl;
	int startbtn;
	do
	{
		cin >> startbtn;
		if (startbtn <0 && startbtn >1 )
			cout << "Press '1' or '0' ,please." << endl;
		else break;
	} while (1);
	system("cls");
	while (startbtn)//开始工作
	{
		cout << "Please input your code file's name:" << endl;
		string file_name;
		cin >> file_name;
		int max_ins = controller.load_asm(file_name);//代码长度
		//cout << max_ins << endl;
		system("cls");
		if (max_ins)
		{
			cout << "Please chosse your working-mode:(continous is defaulted)" << endl;
			cout << "1. single-step" << endl;
			cout << "2. continous" << endl;
			int mode;
			do
			{
				cin >> mode;
				if (startbtn < 1 && startbtn > 2)
					cout << "Press '1' or '2' ,please." << endl;
				else break;
			} while (1);
			system("cls");
			if (mode != 1)
			{
				int cnt = 1;
				for (int i = 0; i != max_ins; i = rpc.GetData())
				{
					cout << "Step " << cnt << "--> ";
					controller.run_asm();
					cnt++;
				}
				cout << "\n\nThe final state of the registers are:" << endl;
				cout << "PC = " << rpc.GetData() << endl;
				cout << "RA = " << ra.GetData() << endl;
				cout << "RB = " << rb.GetData() << endl;
				cout << "The result is: " << memory.data[500][0] << endl;
			}
			else if (mode == 1)
			{
				int cnt = 1;
				cout << "In single-step mode, machine run one instruction each time." << endl;
				for (int i = 0; i != max_ins; i = rpc.GetData())
				{
					cout << "PC = " << rpc.GetData() << endl;
					cout << "RA = " << ra.GetData() << endl;
					cout << "RB = " << rb.GetData() << endl;
					cout << "Next instruction is: ";
					for (int j = 0; j < (int)memory.data[rpc.GetData()].size(); j++)
					{
						cout << memory.data[rpc.GetData()][j] << " ";
					}
					cout << endl;
					int next = 0;
					cout << "Press '1' to continue." << endl;
					cin >> next;
					if (next)
					{
						system("cls");
						cout << "Step " << cnt << "--> ";
						controller.run_asm();
						cnt++;
					}
					cout << "\n\n";
				}
				system("cls");
				cout << "\n\n\n\nThe result is:" << memory.data[500][0] << endl;
			}
		}
		else if (max_ins == 0)
		{
			cout << "No code offered." << endl;
		}
		startbtn = 0;
	}
	return 0;
}