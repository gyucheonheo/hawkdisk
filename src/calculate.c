#include <time.h>
#include <stdio.h>
#define BILLION 1000000000L
double
printThroughput(void (*fnc)(int, int, long, char*), int fd, int record, long filesize, char* buf){
	struct timespec start, stop;
	clock_gettime( CLOCK_REALTIME, &start);
	fnc(fd,record, filesize, buf);
	clock_gettime( CLOCK_REALTIME, &stop);
	double accum = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / (double)BILLION;
	return accum;
/*	
	double throughput = ((double)filesize / accum)/(double)1000000;
	double ops = ((double)filesize/ (double)record) / accum;
	printf("Elapsed time : %lf second, Throughput : %lf MB/sec, OPS : %lf OPS/sec\n", accum, throughput, ops);
*/
}
