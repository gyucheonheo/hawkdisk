#include <stdio.h>
void
usage(){
  printf("\n");
  printf("USAGE: ./MyDiskBench -d <dataset> -p <access pattern> -r <record size>\n");
  printf("\n");
  printf("OPTIONS: \n");
  printf("\t -d Integer \t\t The given datasets (1,2,3,4,5,6,7)\n");
  printf("\t -p Integer \t\t The access pattern (0,1,2,3 will maps to ws, rs, wr, rr)\n"); 
  printf("\t -r Integer \t\t The record sizes (64, 1, 16)\n");
  printf("\t\t Note : 64 = 64KB, 1 = 1MB, 16 = 16MB\n");

  printf("Note : \n");
  printf("\t The number of threads will be set based up on the dataset\n");

  printf("Example : \n");
  printf("   ./MyDiskBench -d 3 -p 0 -r 64\n\n");
}
