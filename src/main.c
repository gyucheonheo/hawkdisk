#include "../include/MyDiskBench.h"
#include "../include/MyDiskBenchArgs.h"
#include "../include/usage.h"
#include <stdio.h>
#include <getopt.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>

int getConcurrency(int dataset);
const long getFilesize(int dataset);
int getRecord(int record);

int main(int argc, char ** argv){

	int opt, dataset, pattern,record, concurrency;
	int dflag = 0, pflag = 0, rflag = 0;
	while( (opt = getopt(argc, argv, "d:p:r:")) != -1 ){
		switch(opt){
			case 'd':
				dflag = 1;
				dataset = atoi(optarg);
				break;
			case 'p':
				pattern = atoi(optarg);
				pflag = 1; break;
			case 'r':
				record = atoi(optarg);
				rflag = 1;
				 break;
			default:
				usage();
				return EXIT_FAILURE;
		}
	}

	if( !(dflag & pflag & rflag) ){ 
		usage();
		return EXIT_FAILURE;
	}	
	int i;
	concurrency = getConcurrency(dataset);

	struct threadData tdata[concurrency];
	for(i = 0; i < concurrency; i++){
		tdata[i].record = getRecord(record);
		tdata[i].dataset_number = dataset;
		tdata[i].pattern = pattern;
		tdata[i].nth_file_number = i+1;
		tdata[i].filesize = getFilesize(dataset);	
	}

	for(i = 0; i < concurrency; i++){
		pthread_create(&(tdata[i].pid), NULL, taskFunction, (void *)&tdata[i]);
	}

	for(i = 0; i < concurrency; i++){
		pthread_join(tdata[i].pid, NULL);
	}
	for(i = 0;i < concurrency; i++){
		double throughput = ((double)tdata[i].filesize / tdata[i].elapseTime)/(double)1000000;
		double ops = ((double)tdata[i].filesize / (double)tdata[i].record) / tdata[i].elapseTime;
		printf("time : %lf, throughput : %lf MB/sec, ops : %lf ops/sec\n", 
				tdata[i].elapseTime,
				throughput,
				ops
				);
	}
	return EXIT_SUCCESS;
}
	int
	getConcurrency(int dataset){
		if(dataset == 1) return 1;
		if(dataset == 2) return 2;
		if(dataset == 3) return 4;
		if(dataset == 4) return 8;
		if(dataset == 5) return 12;
		if(dataset == 6) return 24;
		if(dataset == 7) return 48;
		return -1;

	}
	const long
	getFilesize(int dataset){
		const long MEGABYTE = 1000 * 1000;
		const long GIGABYTE = MEGABYTE * 1000;
		if(dataset == 1) return 10*GIGABYTE;
		if(dataset == 2) return 5*GIGABYTE;
		if(dataset == 3) return 2.5*GIGABYTE;
		if(dataset == 4) return 1.25*GIGABYTE;
		if(dataset == 5) return 833.33*MEGABYTE;
		if(dataset == 6) return 416.67*MEGABYTE;
		if(dataset == 7) return 208.33*MEGABYTE; 
		return -1;
	}
	int
	getRecord(int r){
		if(r == 4) return 4*1024;
		if(r == 64) return 64*1024;
		if(r == 1) return 1024*1024;
		if(r == 16) return 16*1024*1024;
		return -1; 
	}


