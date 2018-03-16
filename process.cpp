/*
 * Title: process.cpp
 * Author: Andy Ko
 * Created on: December 2, 2017
 * Description: Implementation of Process class
 *
 */



#include "process.h"

#include <string>

using namespace std;

Process::Process()
{
	PID = 0;
	PRIORITY = -1;
}

Process::Process(int pid, int priority)
{
	PID = pid;
	PRIORITY = priority;
}


void Process::set_pid(int pid)
{
	PID = pid;
}
void Process::set_priority(int priority)
{
	PRIORITY = priority;
}
void Process::set_file(string file)
{
	file_name = file;
}

int Process::pid()
{
	return PID;
}
int Process::priority()
{
	return PRIORITY;
}
string Process::file()
{
    return file_name;
}



//Deconstructor for node
process_node::~process_node()
{
    next = NULL;
}
