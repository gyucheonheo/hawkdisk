#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../include/calculate.h"
 
void sequentialRead(int, int, long, char*);
void sequentialWrite(int, int, long, char*);

double
sequentialTaskFunction(char *filename, int record, long filesize, int pattern){
	int fd;
	char path[40];

	if(pattern == 0) {
		sprintf(path, "./dataset/write/%s", filename);
		fd = open(path, O_CREAT|O_WRONLY|O_SYNC|O_TRUNC|O_DIRECT, 0666); 
	}
	else {
		sprintf(path, "./dataset/read/%s", filename);
		fd = open(path, O_RDONLY|O_RSYNC|O_DIRECT);
	}
	if(fd < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}	

	char *buf; 
	posix_memalign((void**)&buf, 4096, sizeof(char)*record);
	posix_fadvise(fd, 0,0, POSIX_FADV_SEQUENTIAL | POSIX_FADV_NOREUSE);
	lseek(fd, 0, SEEK_SET);

	double ret;
	if(pattern == 0){
		ret = printThroughput(sequentialWrite, fd, record, filesize, buf);
	} else {
		ret = printThroughput(sequentialRead, fd, record, filesize, buf);
	}
	
	free(buf);
	close(fd);
	return ret;
}
	void
	sequentialWrite(int fd, int record, long filesize, char *buf){
		long writtenSoFar = 0;
		while( writtenSoFar < filesize ){
//			printf("SEQ writtenSoFar : %f FileSize : %f\n", (double)writtenSoFar / (double)1000000000, (double)filesize / (double)1000000000);
			long justWrote = (long)write(fd, buf, record);
			if(justWrote<= 0){
				return;
			}
			writtenSoFar += justWrote;
			fsync(fd);
		}
	}

	void
	sequentialRead(int fd, int record, long filesize, char *buf){
		long readSoFar = 0;
		while( readSoFar < filesize ){
//			printf("SEQ readSoFar : %ld FileSize : %ld\n", readSoFar , filesize);
			long justRed = (long)read(fd, buf, record);
			if(justRed<= 0){
				return;
			}
			readSoFar+= justRed;
		}
	}	

