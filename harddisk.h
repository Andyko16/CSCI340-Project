/*
 * Title: harddisk.h
 * Author: Andy Ko
 * Created on: December 3, 2017
 * Description: Header of Harddisk class
 *
 */



#ifndef __HARDDISK_H__
#define __HARDDISK_H__


#include "process.h"

using namespace std;

class Harddisk
{
public:
	Harddisk();
    ~Harddisk();

    void destroy(process& p);

	void add_process(process& p);
	process finish();
	void add_file(string file);
	void display(ostream& os, int i);
	bool has_process();


private:
	//pointer to the process that is currently used by hard disk
	//Any process after that pointer is in the ready queue of the hard disk
	process HD_queue;

};



#endif /* __HARDDISK_H__*/
