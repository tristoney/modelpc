#include "Controller.h"


Controller::Controller(Memory& memo, Processer& proc, Register& ra, Register& rb, Register& rd, ProgramCounterReg& rpc, ProgramStatusReg& rps)
	:memory(memo),processer(proc),ra(ra),rb(rb),rd(rd),rpc(rpc),rps(rps)
{
}

Controller::~Controller()
{
}

int Controller::load_asm(string file_name)
{
	int addr = 0;//指令长度
	ifstream asm_file(file_name);
	if (!asm_file)
	{
		cout << "No such code file. Please check its name." << endl;
		exit(0);
	}
	else
	{
		string line;//读入的一行代码
		while (getline(asm_file, line))
		{
			stringstream ss(line);
			string word;
			while (ss >> word)
			{
				memory.data[addr].push_back(word);
			}
			addr++;
		}
	}
	asm_file.close();
	return addr;
}

bool Controller::run_asm()
{
	vector<string> instruction = memory.data[rpc.GetData()];
	string op = instruction[0];
	string dst = "";
	string src = "";
	if ((int)instruction.size() >= 2)
		dst = instruction[1];
	if ((int)instruction.size() == 3)
		src = instruction[2];
	if (op == "mov")//mov 指令 mov dst(寄存器） src（寄存器or立即数or内存）
	{
		if (src[0] <= '9' && src[0] >= '0')//源为立即数
		{
			if (dst == "ra")
				ra.SetData(atoi(src.c_str()));
			else if (dst == "rb")
				rb.SetData(atoi(src.c_str()));
		}
		else if (src == "ra")// mov rb ra
			rb.SetData(ra.GetData());
		else if (src == "rb")// mov ra rb
			ra.SetData(rb.GetData());
		else if (src[0] == '(')// mov dst (addr)
		{
			string::iterator iter;
			for (iter = src.begin(); iter < src.end(); iter++)
			{
				if (*iter == '(' || ')')
				{
					src.erase(iter);
					iter--;
				}
			}
			int addr = atoi(src.c_str());
			if (dst == "ra")
				ra.SetData(atoi(memory.GetData(addr)[0].c_str()));
			else if (dst == "rb")
				rb.SetData(atoi(memory.GetData(addr)[0].c_str()));
		}
		cout << "mov " << dst << " " << src << endl;
		rpc.inc();
		return true;
	}

	if (op == "add")//add指令 add dst(寄存器） src（寄存器or立即数）
	{
		if (src[0] <= '9' && src[0] >= '0')//源为立即数
		{
			if (dst == "ra")
			{
				processer.SetRa(ra.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.add();
				ra.SetData(processer.GetRans());
			}
			else if (dst == "rb")
			{
				processer.SetRa(rb.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.add();
				rb.SetData(processer.GetRans());
			}
		}
		else if (src == "ra")// add rb ra
		{
			processer.SetRa(rb.GetData());
			processer.SetRb(ra.GetData());
			processer.add();
			rb.SetData(processer.GetRans());
		}
		else if (src == "rb")// add ra rb
		{
			processer.SetRa(ra.GetData());
			processer.SetRb(rb.GetData());
			processer.add();
			ra.SetData(processer.GetRans());
		}
		cout << "add " << dst << " " << src << endl;
		rpc.inc();
		return true;
	}

	if (op == "sub")//sub指令 sub dst(寄存器） src（寄存器or立即数）
	{
		if (src[0] <= '9' && src[0] >= '0')//源为立即数
		{
			if (dst == "ra")
			{
				processer.SetRa(ra.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.sub();
				ra.SetData(processer.GetRans());
			}
			else if (dst == "rb")
			{
				processer.SetRa(rb.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.sub();
				rb.SetData(processer.GetRans());
			}
		}
		else if (src == "ra")// sub rb ra
		{
			processer.SetRa(rb.GetData());
			processer.SetRb(ra.GetData());
			processer.sub();
			rb.SetData(processer.GetRans());
		}
		else if (src == "rb")// sub ra rb
		{
			processer.SetRa(ra.GetData());
			processer.SetRb(rb.GetData());
			processer.sub();
			ra.SetData(processer.GetRans());
		}
		cout << "sub " << dst << " " << src << endl;
		rpc.inc();
		return true;
	}

	if (op == "cmp")//cmp dst(reg) src(reg/num)
	{
		if (src[0] <= '9' && src[0] >= '0')//源为立即数
		{
			if (dst == "ra")
			{
				processer.SetRa(ra.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.cmp();
			}
			else if (dst == "rb")
			{
				processer.SetRa(rb.GetData());
				processer.SetRb(atoi(src.c_str()));
				processer.cmp();
			}
		}
		else if (src == "ra")// cmp rb ra
		{
			processer.SetRa(rb.GetData());
			processer.SetRb(ra.GetData());
			processer.cmp();
		}
		else if (src == "rb")// cmp ra rb
		{
			processer.SetRa(ra.GetData());
			processer.SetRb(rb.GetData());
			processer.cmp();
		}
		cout << "cmp " << dst << " " << src << endl;
		rpc.inc();
		return true;
	}

	if (op == "jmp")//jmp dst(addr)
	{
		rpc.SetData(atoi(dst.c_str()));
		cout << "jmp " << dst << endl;
		return true;
	}

	if (op == "jne")//jne dst(addr)
	{
		//cout << "ZF = " << rps.GetZF() << endl;
		if (!rps.GetZF())
			rpc.SetData(atoi(dst.c_str()));
		else
			rpc.inc();
		cout << "jne " << dst << endl;
		return true;
	}

	if (op == "je")//jne dst(addr)
	{
		if (rps.GetZF())
			rpc.SetData(atoi(dst.c_str()));
		else
			rpc.inc();
		cout << "je " << dst << endl;
		return true;
	}

	if (op == "sto")// sto dst(addr) src(reg)
	{
		if (src == "ra")// sto addr ra
			memory.data[atoi(dst.c_str())].push_back(to_string(ra.GetData()));
		else if (src == "rb")// sto addr rb
			memory.data[atoi(dst.c_str())].push_back(to_string(rb.GetData()));
		cout << "sto " << dst << " " << src << endl;
		rpc.inc();
		return true;
	}

	if (op == "ret") //ret
	{
		rpc.inc();
		rd.SetData(ra.GetData());
		cout << "ret" << endl;
		return false;
	}

	else
	{
		return false;
	}
}
