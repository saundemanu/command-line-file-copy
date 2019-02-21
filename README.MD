# CSC 415 - Project 2 - File copy

## Student Name : Emanuel Saunders

## Student ID   : 917273245

## Build Instructions

 The program was tested in Ubuntu~18.04 on gcc version 7.3.0

### Using the Makefile

In the terminal in the project folder, run: 

```make```


### Building Manually

In the terminal in the project folder:

run: 

```gcc -I -Wall filecopy.c -o fc~```




This compiles the file an exectuable: 

fc

## Run Instructions

In the terminal in the project folder, run: 

```./fc```

Enter the desired file to copy at the first prompt.

Enter the desired output file at the second prompt.

## strace/dtruss output

% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
#### writing to files, called to copy to output and print messages to stdout
 58.24    0.009821          16       616           write
#### reading from files, called to get input from files and get user input from stdin
 41.58    0.007011          11       616           read
#### close files, deallocate file descriptors, unlock record locks owned by process 
  0.18    0.000031           8         4           close
#### returns information about files, used on open and close
  0.00    0.000000           0         4           fstat
#### maps and unmaps files into device memory; used on open, (file creation?), and closing. 
  0.00    0.000000           0         5           mmap
#### sets protection on calling process's memory, used on open and close to set whether or not files can be read, written, or executed 
  0.00    0.000000           0         4           mprotect
#### deletes mappings for specified address range, called on termination
  0.00    0.000000           0         1           munmap
#### changes the location of program break, controls heap/stack size
  0.00    0.000000           0         3           brk
#### checks user permissions for a file
  0.00    0.000000           0         3         3 access
#### executes a program
  0.00    0.000000           0         1           execve
#### sets architecture thread state, gets and sets subfunctions
  0.00    0.000000           0         1           arch_prctl
#### opens file relative to directory file descriptor, takes relative path whereas open uses wd
  0.00    0.000000           0         4           openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.016863                  1262         3 total
