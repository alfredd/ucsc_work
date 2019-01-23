#!/bin/bash
argc=$#

if [ "$argc" != "2" ] ;
then
    echo "Invalid usage. Cannot continue executing the program."
    echo "usage: $0 cruzid_list.txt "DEADLINE DateString"
    echo "      example"
    echo "          $0 cruzid_list.txt "\"2019-01-01 23:59:59\""
fi

filename=$1
datestring=$2
git_directory="ucsc_gitlab"

echo "Starting git clone-ing. Project repositories will be created under ./$git_directory"
mkdir -p "$git_directory"

for cruzid in `cat $filename`;
do
    echo "Cloning repo for $cruzid" ;
    git clone
done