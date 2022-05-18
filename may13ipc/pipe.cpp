//Program to demonstrate an IPC using pipe
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#define MAX 256
using namespace std;

char msg1[] = "Hello User #1\n";
char msg2[] = "Hello User #2\n";
char msg3[] = "Hello User #3\n";
int prnerr(int ret,const char msg[]){
	if (ret < 0){
	
		perror(msg);
		exit(EXIT_FAILURE);
	}
	return 0;
}
int main()
{
	char buff[MAX];
	int pipefd[2],i,ret,len,status;
	pid_t child_pid;
	ret = pipe(pipefd);
	len = strlen(msg1);

	prnerr(ret,"Error Creating pipe");

	ret = write(pipefd[1],msg1,strlen(msg1));
	prnerr(ret,"Unable to write message to pipe");
	ret = write(pipefd[1],msg2,strlen(msg2));
	prnerr(ret,"Unable to write message to pipe");
	ret = write(pipefd[1],msg3,strlen(msg3));
	prnerr(ret,"Unable to write message to pipe");
	child_pid = fork();
	if (child_pid == 0){
		close(0);
		dup(pipefd[0]);
		close(pipefd[0]);
		close(pipefd[1]);
		execlp("tr","tr","a-z","A-Z",0);
	}
/*	for (i = 0; i < 3; i++){
		ret = read(pipefd[0],buff,len);
		prnerr(ret,"Error Reading the pipe");
		cout << buff << endl;
	}*/
	close(pipefd[0]);
	close(pipefd[1]);
	wait(&status);
	cout << "Child process Completed Sucessfully" << endl;
	
	return 0;
}


