/*
 * Title: frametable.cpp
 * Author: Andy Ko
 * Created on: December 15, 2017
 * Description: Implementation of Process class
 *
 */

 #include "frametable.h"
#include <ostream>

using namespace std;

Frametable::Frametable()
{
    page = 0;
    pid = 1;
    time_stamp = 2;
    frame[page] = 0;
    frame[pid] = 0;
    frame[time_stamp] = 0;
}

void Frametable::set_frame(int PAGE, int PID, int TIME)
{
//    frame[page] = (int)(num/frame_size);
    frame[page] = PAGE;
    frame[pid] = PID;
    frame[time_stamp] = TIME;
}

int Frametable::PAGE()
{
    return frame[page];
}
int Frametable::PID()
{
    return frame[pid];
}
int Frametable::TIME()
{
    return frame[time_stamp];
}


void Frametable::display(ostream& os)
{
    os << frame[page] << "\t" << frame[pid] << "\t" << frame[time_stamp] << endl;
}



/*
private:
    int page = 0;
    int pid = 1;
    int time_stamp = 2;
    int frame[3];
    int frame_size;
*/


