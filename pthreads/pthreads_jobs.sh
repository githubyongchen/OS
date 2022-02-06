#!/bin/sh
#$ -V
#$ -cwd
#$ -S /bin/bash
#$ -N Pthreads_Job
#$ -o $JOB_NAME.o$JOB_ID
#$ -e $JOB_NAME.e$JOB_ID
#$ -q omni
#$ -pe sm 36
#$ -l h_vmem=5.3G
#$ -l h_rt=48:00:00
#$ -P quanah

echo "Testing helloworld_pthreads.exe ..."
./helloworld_pthreads.exe
echo -e "###\n"

echo "Testing pthreads_pi.exe ..."
./pthreads_pi.exe
echo -e "###\n"

echo "Testing producer_consumer_model.exe ..."
./producer_consumer_model.exe
echo -e "###\n"

echo "Testing pthreads_findmin.exe ..."
./pthreads_findmin.exe -S 1 -N 100000000 -T 1
./pthreads_findmin.exe -S 1 -N 100000000 -T 2
./pthreads_findmin.exe -S 1 -N 100000000 -T 4
./pthreads_findmin.exe -S 1 -N 100000000 -T 8
./pthreads_findmin.exe -S 1 -N 100000000 -T 16
./pthreads_findmin.exe -S 1 -N 100000000 -T 32 
echo -e "###\n"
