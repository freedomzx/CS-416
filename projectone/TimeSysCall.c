#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

void pidHunThouTimes();

// Place any necessary global variables here

int main(int argc, char *argv[]){
	struct timeval start, end; //structs for recording beginning and end time

	gettimeofday(&start, NULL); //retrieve start timer
	pidHunThouTimes(); //grab pid 100000 times as per instructio
	gettimeofday(&end, NULL); //retrieve end timer

	//get time elapsed by adding seconds + microseconds
	float microseconds = ((end.tv_sec - start.tv_sec) * 1000000) + ((end.tv_usec - start.tv_usec)); 
	printf("Syscalls Performed: 100000\nTotal Elapsed Time: %f microseconds\nAverage Time Per Syscall: %f microseconds\n", microseconds, microseconds/100000);
	return 0;
}

void pidHunThouTimes(){
	int i = 0;
	for(i = 0; i < 100000; i++) getpid();
}