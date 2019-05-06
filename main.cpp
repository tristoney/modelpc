#include "common.h"
#include "Controller.h"
#include "Memory.h"
#include "Processer.h"
#include "Register.h"

Memory memory(1024);
Register ra("ra",0);
Register rb("rb", 0);
Register rd("rd", 0);
ProgramCounterReg rpc("rpc",0);
ProgramStatusReg rps("rps", 0);
Processer processer(0, 0, 0, rps);
Controller controller(memory, processer, ra, rb, rd, rpc, rps);



int main()
{
	int startbtn = -1;
	while (startbtn)
	{
		memory.Reset();
		ra.Reset(); rb.Reset(); rd.Reset(); rpc.Reset(); processer.Reset();//重置内存和寄存器

		system("cls");
		cout << "\n\n\n\n";
		cout << "				Welcome to my model-pc!" << endl;
		cout << "				Press 1 to get start!" << endl;
		cout << "				Press 0 to get quit!" << endl;
		do
		{
			cin >> startbtn;
			if (startbtn < 0 && startbtn >1)
				cout << "Press '1' or '0' ,please." << endl;
			else break;
		} while (1);
		system("cls");
		if (startbtn == 1)//开始工作
		{
			cout << "Please input your code file's name:" << endl;
			string file_name;
			cin >> file_name;
			int max_ins = controller.load_asm(file_name);//代码长度
			
			system("cls");
			if (max_ins)//有代码读入
			{
				cout << " File load successfully, the lenth of the code is: " << max_ins << endl;
				cout << "\n\nPlease chosse your working-mode:(continous is defaulted)" << endl;
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
					cout << "The result is: " << rd.GetData() << endl;
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
						cout << "\n\nPress '1' to continue." << endl;
						cout << "Press '2' to set the value of register." << endl;
						cout << "Press '3' to set the memory." << endl;
						cin >> next;
						if (next == 1)
						{
							system("cls");
							cout << "Step " << cnt << "--> ";
							controller.run_asm();
							cnt++;
						}
						else if (next == 2)
						{
							system("cls");
							int value;
							cout << "What value do you want RA to store: ";
							cin >> value;
							ra.SetData(value);
							cout << "What value do you want RB to store: ";
							cin >> value;
							rb.SetData(value);
						}
						else if (next == 3)
						{
							system("cls");
							int value,addr;
							cout << "What value and where do you want to change in memory: ";
							cin >> value >> addr;
							memory.SetData(to_string(value), addr);
						}
						cout << "\n\n";
					}
					system("cls");
					cout << "\n\n\n\nThe result is:" << rd.GetData() << endl;
				}
			}
			else if (max_ins == 0)//无代码读入
			{
				cout << "No code offered." << endl;
			}
			cout << "\n\nPress any botten to return previous menu." << endl;
			char quit;
			cin >> quit;
		}
	}
	
	return 0;
}