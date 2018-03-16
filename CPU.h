/*
 * Title: CPU.h
 * Author: Andy Ko
 * Created on: December 2, 2017
 * Description: Header of CPU class
 *
 */



#ifndef __CPU_H__
#define __CPU_H__


#include "harddisk.h"
#include "process.h"
#include "frametable.h"


using namespace std;

class CPU
{
public:
	CPU();
    ~CPU();

    void destroy(process& p);

	void set_HD_size(int i);
	void terminate();
	void HD_return(process& p);
	void add_process(process& p);
	void HD_request(int number, string s);
	void HD_finish(int number);
	void display(ostream& out);
	void HD_display(ostream& out);

    void buildFrameTable(int Ram_size, int Frame_size);
    void insert_frame(int m);
    void insert_frame(process&p , int m);
    void remove_frame();
    void FT_Display(ostream& os);



private:
	//pointer to the process that is currently runned by CPU
	//Any process after that point is in the ready queue
	process head_queue;
	Harddisk *HD;
	int HD_size;
    Frametable *FT;
    int frame_size;
    int num_frame;
    int ram_size;
    int timestamp;
};


#endif /* __CPU_H__*/
