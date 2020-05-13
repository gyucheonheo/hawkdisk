#include <stdio.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "../include/MyDiskBenchArgs.h"
#include "../include/MyDiskBenchRandom.h"
#include "../include/MyDiskBenchSequential.h"
#define BILLION 1000000000L

void*
taskFunction(void *t_args){
	struct threadData *args = (struct threadData *)t_args;
	int record = args->record; 
	int dataset = args->dataset_number;
	const long filesize = args->filesize; 
	int nth = args->nth_file_number;
	int pattern = args->pattern; 
	
	char filename[30];
	sprintf(filename, "d%d_%d.dat", dataset, nth);

	if(pattern == 0 || pattern == 1){
		args->elapseTime = sequentialTaskFunction(filename, record, filesize, pattern);	
	}
	else if(pattern == 2 || pattern == 3){
		args->elapseTime = randomTaskFunction(filename, record, filesize, pattern);
	}
	else{
		perror("Invalid pattern");
		return NULL;
	}
	return NULL;
}
