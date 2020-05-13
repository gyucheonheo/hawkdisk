#!/bin/bash

COUNT=1000000

echo "Dataset 1"
dd if=/dev/urandom of=./read/d1_1.dat bs=10000 count=$COUNT
echo "Dataset 2"
dd if=/dev/urandom of=./read/d2_1.dat bs=5000 count=$COUNT 
dd if=/dev/urandom of=./read/d2_2.dat bs=5000 count=$COUNT

echo "Dataset 3"

for i in {1..4}
do
	dd if=/dev/urandom of=./read/d3_$i.dat bs=2500 count=$COUNT
done

echo "Dataset 4"

for i in {1..8}
do
	dd if=/dev/urandom of=./read/d4_$i.dat bs=1250 count=$COUNT
done

echo "Dataset 5"

for i in {1..12}
do
	dd if=/dev/urandom of=./read/d5_$i.dat bs=83333 count=10000
done

echo "Dataset 6"

for i in {1..24}
do
	dd if=/dev/urandom of=./read/d6_$i.dat bs=41667 count=10000
done

echo "Dataset 7"

for i in {1..48}
do
	dd if=/dev/urandom of=./read/d7_$i.dat bs=20833 count=10000
done

