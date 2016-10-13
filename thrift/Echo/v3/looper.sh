#!/usr/bin/env bash


outDir=results_remote_o

mkdir $outDir

#for msgLen in 1 10 100 1000 10000 20000 40000 60000 100000 200000 400000 1000000
for msgLen in 60000
do
    echo remote $msgLen
#    ./CppClient -s snares-08.cs.wisc.edu -p 9090 -n 1000 -l $msgLen >> $outDir/$msgLen.txt
done



#for msgLen in 1 10 100 1000 10000 20000 40000 60000 100000 200000 400000 1000000
for msgLen in 40000 60000
do
    echo out : $outDir/$msgLen.txt
    tail -1000 $outDir/$msgLen.txt | awk -F '\t' '{print $1}' > $outDir/${msgLen}_RTT.txt
    tail -1000 $outDir/$msgLen.txt | awk -F '\t' '{print $2}' > $outDir/${msgLen}_BW.txt
    tail -1000 $outDir/$msgLen.txt | awk -F '\t' '{print $3}' > $outDir/${msgLen}_Overhead.txt
done
