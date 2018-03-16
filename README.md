# CSCI340-Project
A program that simulates some aspect operation systems. There are no real system programming involved. 
The whole simulation is based on the text inputs that the program receives from user.

The program constantly listens for the user inputs. The user inputs signal some system events.
The program simulates the corresponding system behavior. The possible inputs are:

A priority 
  'A' input means that a new process has been created. This process has the priority priority. 
  For example, the input A 2 means that a new process has arrived. This process has the priority of 2.
t
  The process that currently uses the CPU terminates.
d number file_name
  The process that currently uses the CPU requests the hard disk #number. It wants to read or write file "file_name".
D number
  The hard disk #number has finished the work for one process.
m address
  The process that currently uses CPU requests a memory operation for address "address".
S r
  Shows what process is currently using the CPU and what processes are waiting in the ready-queue.
S i
  Shows what processes are currently using the hard disks and what processes are waiting to use them. 
S m 
  Shows the state of memory.
