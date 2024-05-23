#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <first name>\n", argv[0]);
        exit(1);
    }

    int fd[2]; // fd[0] is for reading, fd[1] is for writing

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }

    int pid1;
    int pid2;
    int pid3;

    if ((pid1 = fork()) == 0)
    {
        // Child 1
        close(fd[0]);   // because we're not reading from the pipe
        dup2(fd[1], 1); // 1 is the stdout file descriptor
        close(fd[1]);   // fininshing writing to the pipe
        execlp("grep", "grep", argv[1], "phonebook.txt", NULL); // search for the first name in the phonebook, and returning the line
        perror("execlp"); // if execlp fails
        exit(1);
    }
    else if (pid1 == -1)
    {
        perror("fork");
        exit(1);
    }

    if ((pid2 = fork()) == 0)
    {
        // Child 2
        close(fd[1]);   // because we're not writing to the pipe
        dup2(fd[0], 0); // 0 is the stdin file descriptor
        close(fd[0]);   // finishing reading from the pipe
        execlp("cut", "cut", "-d,", "-f2", NULL);
        perror("execlp"); // if execlp fails
        exit(1);
    }
    else if (pid2 == -1)
    {
        perror("fork");
        exit(1);
    }

    if ((pid3 = fork()) == 0)
    {
        // Child 3
        close(fd[1]);   // because we're not writing to the pipe
        dup2(fd[0], 0); // 0 is the stdin file descriptor
        close(fd[0]);   // finishing reading from the pipe
        execlp("sed", "sed", "s/ //g", NULL);
        perror("execlp"); // if execlp fails
        exit(1);
    }
    else if (pid3 == -1)
    {
        perror("fork");
        exit(1);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
