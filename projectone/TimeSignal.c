#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h> 

// Place any necessary global variables here
int signalCounter = 0;
struct timeval start, end; //structs for recording beginning and end time

void handle_sigfpe(int signum){

	if(signalCounter < 100000) signalCounter++;
	else{
		gettimeofday(&end, NULL); //retrieve end timer
		float microseconds = ((end.tv_sec - start.tv_sec) * 1000000) + ((end.tv_usec - start.tv_usec)); 
		printf("Exceptions Occurred: 100000\nTotal Elapsed Time: %f microseconds\nAverage Time Per Exception: %f microseconds\n", microseconds, microseconds/100000);
		exit(0);
	}
	//printf("%d ", signalCounter);
	return;
}

int main(int argc, char *argv[]){
	signal(SIGFPE, handle_sigfpe);
	int x = 5, y = 0, z = 0;
	gettimeofday(&start, NULL); //retrieve start timer
	z = x / y;
	return z;
}
