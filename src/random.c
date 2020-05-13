#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include "../include/calculate.h"

void randomRead(int, int, long, char *);
void randomWrite(int, int, long, char *);

double
randomTaskFunction(char *filename, int record, long filesize, int pattern){
	int fd;
	char path[40];

	if(pattern == 2) {
		sprintf(path, "./dataset/write/%s", filename);
		fd = open(path, O_CREAT|O_DIRECT|O_WRONLY|O_TRUNC|O_SYNC, 0666);
	} else {
		sprintf(path, "./dataset/read/%s", filename);
		fd = open(path, O_RDONLY|O_RSYNC|O_DIRECT);
	}
	if(fd < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}	

	time_t t;
	srandom(time(&t));
	char *buf;
	posix_memalign((void **)&buf, 4096, sizeof(char)*record);
	posix_fadvise(fd, 0,0, POSIX_FADV_RANDOM | POSIX_FADV_NOREUSE);
	lseek(fd, 0, SEEK_SET);

	double ret;
	if(pattern == 2){
		ret = printThroughput(randomWrite, fd, record, filesize, buf);
	} else {
		ret = printThroughput(randomRead, fd, record, filesize, buf);
	}
	free(buf);
	close(fd);
	return ret;
}
	void
	randomWrite(int fd, int record, long filesize, char *buf){
		long writtenSoFar = 0;
		while( writtenSoFar < filesize ){
//			printf("RAND writeSoFar : %f FileSize : %f\n", (double)writtenSoFar / (double)1000000000, (double)filesize / (double)1000000000);
			if(lseek(fd, rand() % (filesize-record), SEEK_SET) < 0){
				perror("RAND LSEEK WRITE ERR: ");
				return;
			}
			long justWrote = (long)write(fd, buf, record);
			if(justWrote < 0){
				continue;
			} else if(justWrote == 0) {
				return;
			}else {
				writtenSoFar += justWrote;
				fsync(fd);
			}
		}
	}
	void
	randomRead(int fd, int record, long filesize, char *buf){
		long readSoFar = 0;
		while( readSoFar < filesize ){
	//		printf("RAND readSoFar : %f FileSize : %f\n", (double)readSoFar / (double)1000000000, (double)filesize / (double)1000000000);
			if(lseek(fd, rand() % (filesize-record), SEEK_SET) < 0){
				perror("RAND LSEEK READ ERR: ");
				return;
			}
			long justRed = (long)read(fd, buf, record);
			if(justRed<0){
				continue;
			} else if (justRed == 0){
				return;
			} else {
				readSoFar+= justRed;
			}
		}	
	}
