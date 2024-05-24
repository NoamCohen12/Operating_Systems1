#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // for pid_t
#include <sys/wait.h>  // for waitpid
#include <unistd.h>    // for fork, pipe
#include <fcntl.h>     // for open
//this assigment work like grep "Avner" "phonebook.txt" | cut -d "," -f 2 | sed 's/ //'g command
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <first name>\n", argv[0]);
        exit(1);
    }

    int __pipedes[2]; // __pipedes[0] is for reading, __pipedes[1] is for writing

    if (pipe(__pipedes) == -1)
    {
        perror("pipe");
        exit(1);
    }
//process1
    pid_t process1;
    pid_t process2;
    pid_t process3;

    if ((process1 = fork()) == 0)//create a child process
    {
        // Child 1
        close(__pipedes[0]);                                           // because we're not reading from the pipe
        dup2(__pipedes[1], 1);                                         // 1 is the stdout file descriptor
        close(__pipedes[1]);                                           // fininshing writing to the pipe
        execlp("grep", "grep", argv[1], "phonebook.txt", NULL); // search for the first name in the phonebook, and returning the line
        perror("execlp");                                       // if execlp fails
        exit(1);
    }
    else if (process1 == -1)
    {
        perror("fork");
        exit(1);
    }

    if ((process2 = fork()) == 0)
    {
        // Child 2
        close(__pipedes[1]);   // because we're not writing to the pipe
        dup2(__pipedes[0], 0); // 0 is the stdin file descriptor
        close(__pipedes[0]);   // finishing reading from the pipe
        execlp("cut", "cut", "-d,", "-f2", NULL);
        perror("execlp"); // if execlp fails
        exit(1);
    }
    else if (process2 == -1)
    {
        perror("fork");
        exit(1);
    }

    if ((process3 = fork()) == 0)
    {
        // Child 3
        close(__pipedes[1]);   // because we're not writing to the pipe
        dup2(__pipedes[0], 0); // 0 is the stdin file descriptor
        close(__pipedes[0]);   // finishing reading from the pipe
        execlp("sed", "sed", "s/ //g", NULL);
        perror("execlp"); // if execlp fails
        exit(1);
    }
    else if (process3 == -1)
    {
        perror("fork");
        exit(1);
    }

    close(__pipedes[0]);
    close(__pipedes[1]);
 
    waitpid(process1, NULL, 0);
    waitpid(process2, NULL, 0);
    waitpid(process3, NULL, 0);

    return 0;
}
