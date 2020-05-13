#ifndef __MY_DISK_BENCH_ARGS_H__
#define __MY_DISK_BENCH_ARGS_H__

#include <pthread.h>

struct
threadData {
	pthread_t pid;
	int record;
	int dataset_number;
	long filesize;
	int nth_file_number;
	int pattern;
	double elapseTime;
};

#endif

