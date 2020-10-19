#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h> 

void forkFiveThouTimes();

// Place any necessary global variables here

int main(int argc, char *argv[]){
	struct timeval start, end; //structs for recording beginning and end time

	gettimeofday(&start, NULL); //retrieve start timer
	forkFiveThouTimes(); //fork 5000 times as per instructions
	gettimeofday(&end, NULL); //retrieve end timer

	float microseconds = ((end.tv_sec - start.tv_sec) * 1000000) + ((end.tv_usec - start.tv_usec)); 
	printf("Forks Performed: 5000\nTotal Elapsed Time: %f microseconds\nAverage Time Per Fork: %f microseconds\n", microseconds, microseconds/5000);
	return 0;
}

void forkFiveThouTimes(){
	int i = 0;
	for(i = 0; i < 5000; i++){
		if(fork() == 0) exit(0);
		else wait(NULL);
	}
}
