/*
 * Title: frametable.h
 * Author: Andy Ko
 * Created on: December 3, 2017
 * Description: Header of Frametable class
 *
 */

#ifndef __FRAMETABLE_H__
#define __FRAMETABLE_H__

#include <ostream>

using namespace std;

class Frametable
{
public:
	Frametable();
    void set_size(int frame);
    void set_frame(int pid, int num, int time);
    int PAGE();
    int PID();
    int TIME();

    void display(ostream& os);

private:
    int page;
    int pid;
    int time_stamp;
    int frame[3];
//    int frame_size;
};


#endif /* __FRAMETABLE_H__*/

