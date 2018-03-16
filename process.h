/*
 * Title: process.h
 * Author: Andy Ko
 * Created on: December 2, 2017
 * Description: Header of Process class
 *
 */



#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <string>


using namespace std;

class Process
{
public:
	Process();
	Process(int pid, int priority);

	void set_pid(int pid);
	void set_priority(int priority);
	void set_file(string file);

	int pid();
	int priority();
	string file();



private:
	int PID;
	int PRIORITY;
	string file_name;
};

typedef struct process_node* process;
struct process_node
{
    //Data members
	Process p;
	process next;

	//Constructor
	process_node(const Process &p, process n):
	    p(p),next(n) {}

    //Deconstructor
    ~process_node();

};

#endif /* __PROCESS_H__*/
