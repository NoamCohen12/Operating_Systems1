#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // for pid_t
#include <sys/wait.h>  // for waitpid
#include <unistd.h>    // for fork, pipe
#include <fcntl.h>     // for open
// this assigment work like echo "Avner" >> "phonebook.txt" command

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please use: %s \"<name>,<phone>\".\n", argv[0]);
        exit(1);
    }
    // command echo not work just with O_APPEND it is should also have O_WRONLY
    int __pipedes = open("phonebook.txt", O_APPEND | O_WRONLY); // open return file descriptor of the file

    if (__pipedes == -1)
    {
        perror("__pipedes");
        exit(1);
    }

    pid_t process1;               // process1
    if ((process1 = fork()) == 0) // create a child process
    {
        dup2(__pipedes, STDOUT_FILENO); // redirect the output of the process to the file
        execlp("echo", "echo", argv[1], NULL); // execute the echo command
    }

    waitpid(process1, NULL, 0); // wait for the child process to finish
    close(__pipedes);           // close the file descriptor

    return 0;
}
