#!/bin/bash

# -T : Use POSIX pthreads for throughput tests
# -t <integer> : Run Iozone ina throughput mode, <integer> tells Iozone the number of threads
# -s <integer>[kmg] : used to specify file size 
# -r <integer>[kmg] : used to specify record size
# -F filename filename filename ?
#    Specify each of the temporary file names to be used in the throughput testing. The number of names should be equal to the number of processes or threads that are specified.

# -I : Use DIRECT IO if possible for all file operations. Tells the filesystem that all operations to the file are to bypass the buffer cache and go directly to disk. (not available on all platforms) 

# -O : Give results in operations per second.  

declare -a d1=$(ls ./dataset | grep d1)
declare -a d2=$(ls ./dataset | grep d2)
declare -a d3=$(ls ./dataset | grep d3)
declare -a d4=$(ls ./dataset | grep d4)
declare -a d5=$(ls ./dataset | grep d5)
declare -a d6=$(ls ./dataset | grep d6)
declare -a d7=$(ls ./dataset | grep d7)

declare -a allThreads=(1 2 4 8 12 24 48)

declare -a allRecords=("64k" "1m" "16m")
declare -a allAccessPatterns=(0 1 2)

echo "64kb record"
iozone -T -s "10000000k" -t 1 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "5000000k" -t 2 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "2500000k" -t 4 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "1250000k" -t 8 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "833330k" -t 12 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "416670k" -t 24 -i 0 -i 2 -r "64k" -I -O
iozone -T -s "208330k" -t 48 -i 0 -i 2 -r "64k" -I -O


echo "1mb record"
iozone -T -s "10000000k" -t 1 -i 0 -i 2 -r "1m" -I -O

iozone -T -s "2500000k" -t 4 -i 0 -i 2 -r "1m" -I -O
iozone -T -s "1250000k" -t 8 -i 0 -i 2 -r "1m" -I -O
iozone -T -s "833330k" -t 12 -i 0 -i 2 -r "1m" -I -O
iozone -T -s "416670k" -t 24 -i 0 -i 2 -r "1m" -I -O
iozone -T -s "208330k" -t 48 -i 0 -i 2 -r "1m" -I -O


echo "16mb record"
iozone -T -s "10000000k" -t 1 -i 0 -i 2 -r "16m" -I -O

iozone -T -s "2500000k" -t 4 -i 0 -i 2 -r "16m" -I -O
iozone -T -s "1250000k" -t 8 -i 0 -i 2 -r "16m" -I -O
iozone -T -s "833330k" -t 12 -i 0 -i 2 -r "16m" -I -O
iozone -T -s "416670k" -t 24 -i 0 -i 2 -r "16m" -I -O
iozone -T -s "208330k" -t 48 -i 0 -i 2 -r "16m" -I -O


