/*
 * Title: harddisk.cpp
 * Author: Andy Ko
 * Created on: December 3, 2017
 * Description: Implementation of Harddisk class
 *
 */


#include "process.h"
#include "harddisk.h"

#include <ostream>

using namespace std;

Harddisk::Harddisk()
{
    HD_queue = NULL;
}

Harddisk::~Harddisk()
{
    destroy(HD_queue);
}

void Harddisk::destroy(process& p)
{
    if(p != NULL)
    {
        destroy(p->next);
        p->next = NULL;
		delete p;
		p = NULL;
	}
}

void Harddisk::add_process(process& p)
{
	process cur_pt = HD_queue;

	// There is no ready queue
	if (HD_queue == NULL)
	{
		HD_queue = p;
		return;
	}

    // Going to end of queue
	while (cur_pt->next != NULL)
	{
	    cur_pt = cur_pt->next;
	}
	//First Come First Serve
	cur_pt->next = p;


}
process Harddisk::finish()
{
    if (HD_queue == NULL)
        return HD_queue;
	process temp = HD_queue;
	HD_queue = HD_queue->next;
	temp->next = NULL;
    return temp;

}
void Harddisk::add_file(string file)
{
    HD_queue->p.set_file(file);
}
void Harddisk::display(ostream& os, int i)
{
    if (HD_queue == NULL)
    {
        os << "Harddisk #" << i << ": \n";
        return;
    }
    os << "Harddisk #" << i << ": \t PID:" << HD_queue->p.pid() << "\t File: " << HD_queue->p.file() << endl;
    process tmp = HD_queue->next;
    if(tmp != NULL)
    {
        os << "Ready Queue:\t PID:" << tmp->p.pid() << "\t File Name: " << tmp->p.file() << endl;
        tmp = tmp->next;
    }
    while(tmp != NULL)
    {
        os << "\t\t PID:" << tmp->p.pid() << "\t File Name: " << tmp->p.file() << endl;
        tmp = tmp->next;
    }

}


bool Harddisk::has_process()
{
    return HD_queue != NULL;
}



/*
private:
	//pointer to the process that is currently used by hard disk
	//Any process after that pointer is in the ready queue of the hard disk
	process* HD_queue;
	*/
