
#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "common.h"
#include "Memory.h"
#include "Processer.h"
#include "Register.h"

class Controller
{
private:
	Memory& memory;
	Processer& processer;
	Register& ra;
	Register& rb;
	Register& rd;
	ProgramCounterReg& rpc;
	ProgramStatusReg& rps;
public:
	Controller(Memory&, Processer&, Register&, Register&, Register&, ProgramCounterReg&, ProgramStatusReg&);
	~Controller();
	int load_asm(string file_name);
	bool run_asm();
};

#endif // !CONTROLLER_H



