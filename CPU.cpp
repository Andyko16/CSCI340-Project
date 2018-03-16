/*
 * Title:   CPU.cpp
 * Author: Andy Ko
 * Created on: December 2, 2017
 * Description: Implementation of CPU class
 *
 */

#include "process.h"
#include "CPU.h"
#include "harddisk.h"

#include <ostream>

using namespace std;

CPU::CPU()
{
	head_queue = NULL;
	timestamp = 0;
}

CPU::~CPU()
{
	destroy(head_queue);
}

void CPU::destroy(process& p)
{
    if(p != NULL)
    {
        destroy(p->next);
        p->next = NULL;
		delete p;
		p = NULL;
	}
}

void CPU::set_HD_size(int i)
{
    HD_size = i;
    HD = new Harddisk[HD_size];
}

void CPU::terminate()
{
    if (head_queue == NULL)
        return;

    remove_frame();
	process temp = head_queue->next;
	head_queue->next = NULL;
	delete head_queue;
	head_queue = temp;
}

void CPU::HD_return(process& p)
{
    if (p == NULL)
        return;

	process cur_pt = head_queue;

	// There is no ready queue
	if (head_queue == NULL)
	{
		head_queue = p;
		return;
	}

	// Has the Greatest priority
	if (head_queue->p.priority() < p->p.priority())
	{
		p->next = head_queue;
		head_queue = p;
		return;
	}

    // Not first, thus in ready queue
	while (cur_pt->next != NULL)
	{
		if(cur_pt->next->p.priority() < p->p.priority())
		{
		    p->next = cur_pt->next;
            cur_pt->next = p;
            return;
		}
		cur_pt = cur_pt->next;
	}
	//p has the least priorty, thus at the end
	cur_pt->next = p;
}

void CPU::add_process(process& p)
{
    if (p == NULL)
        return;

    insert_frame(p,0);
	process cur_pt = head_queue;

	// There is no ready queue
	if (head_queue == NULL)
	{
		head_queue = p;
		return;
	}

	// Has the Greatest priority
	if (head_queue->p.priority() < p->p.priority())
	{
		p->next = head_queue;
		head_queue = p;
		return;
	}

    // Not first, thus in ready queue
	while (cur_pt->next != NULL)
	{
		if(cur_pt->next->p.priority() < p->p.priority())
		{
		    p->next = cur_pt->next;
            cur_pt->next = p;
            return;
		}
		cur_pt = cur_pt->next;
	}
	//p has the least priorty, thus at the end
	cur_pt->next = p;
}
void CPU::HD_request(int number, string s)
{
    if(number < 0 || number >= HD_size)
        return;
    if(head_queue == NULL)
        return;
	process p = head_queue;
    head_queue = head_queue->next;
    p->next = NULL;
    p->p.set_file(s);
	HD[number].add_process(p);
}
void CPU::HD_finish(int number)
{
    if(number < 0 || number >= HD_size)
        return;
    if(HD[number].has_process())
    {
        process p = HD[number].finish();
        HD_return(p);
    }
}

void CPU::HD_display(ostream& os)
{
	for(int i = 0; i < HD_size; i++)
		HD[i].display(os, i);
}
void CPU::display(ostream& os)
{
    if (head_queue == NULL)
    {
        os << "CPU: \n";
        return;
    }
    os << "CPU: \t\t PID:" << head_queue->p.pid() << "\t Priority: " << head_queue->p.priority() << endl;
    process tmp = head_queue->next;
    if (tmp != NULL)
    {
        os << "Ready Queue:\t PID:" << tmp->p.pid() << "\t Priority: " << tmp->p.priority() << endl;
        tmp = tmp->next;
    }
    while(tmp != NULL)
    {
        os << "\t\t PID:" << tmp->p.pid() << "\t Priority: " << tmp->p.priority() << endl;
        tmp = tmp->next;
    }
}

void CPU::buildFrameTable(int Ram_size, int Frame_size)
{
    num_frame = (int)(Ram_size/Frame_size);
    FT = new Frametable[num_frame];
    ram_size = Ram_size;
    frame_size = Frame_size;
}

void CPU::insert_frame(int m)
{
    if(head_queue == NULL)
        return;
    insert_frame(head_queue, m);
}


void CPU::insert_frame(process& p, int m)
{
    if(p == NULL)
        return;
    int LRU = 0;
    int page = (int)(m/frame_size);

    for(int i = 0; i< num_frame; i++)
    {
        if(p->p.pid() == FT[i].PID())
        {
            if(page == FT[i].PAGE())
            {
                FT[i].set_frame(page, p->p.pid(), ++timestamp);
                return;
            }
            else
            if(FT[LRU].TIME() > FT[i].TIME())
                LRU = i;
        }
        else
        if(FT[LRU].TIME() > FT[i].TIME())
            LRU = i;
    }
    FT[LRU].set_frame(page, p->p.pid(), ++timestamp);
}

void CPU::remove_frame()
{
    for(int i = 0; i < num_frame; i++)
    {
        if(head_queue->p.pid() == FT[i].PID() )
        {
            FT[i].set_frame(0,0,0);
        }
    }
}

void CPU::FT_Display(ostream& os)
{
    os << "Frame#\tPage#\tPID#\ttimestamp\n";
    for(int i = 0; i< num_frame; i++)
    {
        os << i <<"\t";
        FT[i].display(os);
    }
}





