/*
 * Title: main.cpp
 * Author: Andy Ko
 * Created on: December 2, 2017
 * Description: A program that simulates some aspects of operating systems.
 * Purpose: The simulation is based on the text input that the program receives from the user.
 *
 */

#include "CPU.h"
#include "process.h"
#include "harddisk.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>


using namespace std;

void removespaces(string & line);

int main(int argc, char * argv[]) {
    int Max_RAM_Memory = 4000000000;
    int User_RAM = -1;
    int Frame_size = -1;
    int HardDiskCounter = 0;
    int process_counter = 0;
    CPU core;
    string User_cmd;

	cout << "How much RAM memory is there on the simulated computer? \n"
        << "Your program receives the number in bytes (no kilobytes or words). \n";
	while (User_RAM > Max_RAM_Memory && User_RAM < 0)
	{
        cout << "Enter any postive integer up to 4000000000 (4 billions):\n";
		getline(cin, User_cmd);
        User_RAM = atoi(User_cmd.c_str());
	}


    cout << "\nWhat is the size of a frame? \n";
	while (Frame_size <= 0)
    {
        cout << "Enter any postive integer. \n";
		getline(cin, User_cmd);
        Frame_size= atoi(User_cmd.c_str());
    }
    core.buildFrameTable(User_RAM,Frame_size);

    cout << "\nHow many hard disks the simulated computer has? \n";
	while (HardDiskCounter <= 0)
    {
        cout << "Enter any postive integer. \n";
		getline(cin, User_cmd);
        HardDiskCounter = atoi(User_cmd.c_str());
    }
    core.set_HD_size(HardDiskCounter);

    cout << "\nSimulation is now running. Please enter a command. \n";

    while (User_cmd != "e")
    {
        getline(cin, User_cmd);
        removespaces(User_cmd);
        int num;
        string file = "";
        unsigned int space = User_cmd.find_first_of(" ");
        string letter = User_cmd.substr(0,space);
        User_cmd = User_cmd.substr(space+1);
        removespaces(User_cmd);

        if (letter == "A")
        {
            int pid = ++process_counter;
            int priority = atoi(User_cmd.c_str());
            Process p;
            p.set_pid(pid);
            p.set_priority(priority);
            process tmp = new process_node(p,NULL);
            core.add_process(tmp);
        }
        else
        if (letter == "t")
        {
            core.terminate();
        }
        else
        if (letter == "d")
        {
            space = User_cmd.find_first_of(" ");
            num = atoi(User_cmd.substr(0,space).c_str());

            //Invalid command
            if (space >= User_cmd.length())
                continue;
            file = User_cmd.substr(space+1);

            core.HD_request(num, file);
        }
        else
        if (letter == "D")
        {
            space = User_cmd.find_first_of(" ");
            num = atoi(User_cmd.substr(0,space).c_str());

            core.HD_finish(num);
        }
        else
        if (letter == "m")
        {
            space = User_cmd.find_first_of(" ");
            num = atoi(User_cmd.substr(0,space).c_str());
            if(num > User_RAM)
            {
                cout << "Must be in the range: 0 - " << User_RAM << "\n";
                continue;
            }

            core.insert_frame(num);
        }
        else
        if (letter == "S")
        {
            if(User_cmd == "r")
                core.display(cout);
            else
            if(User_cmd == "i")
                core.HD_display(cout);
            else
            if(User_cmd == "m")
                core.FT_Display(cout);
        }
            cout << "------------------------------------------------------\n";
    }
}

//removes all spacebars in front of the line
void removespaces(string & line)
{
    if(line.length() > 0)
    {
        int i = 0;
        while(line[i] == ' ' || line[i] == '\t')
        {
            i++;
        }
        line = line.substr(i);
    }
}
