#!/bin/bash
argc=$#
program_name=$0
function usage_and_exit() {

    if [ "$argc" != "3" ] ;
    then
        echo "Invalid usage. Cannot continue executing the program."
        echo "usage: $program_name cruzid_list.txt "DEADLINE DateString"
        echo "      example"
        echo "          $program_name cruzid_list.txt "\"2019-01-01 23:59:59\""
    fi
}

usage_and_exit

filename=$1
datestring=$2
branch_name=$3
git_directory="ucsc_gitlab"

echo "Starting git clone-ing. Project repositories will be created under ./$git_directory"
mkdir -p "$git_directory"

if ! [[ -e "$filename" ]] ;
then
    echo "File does not exist.";
    usage_and_exit ;
fi

for cruzid in `cat $filename`;
do
    echo "Cloning repo for $cruzid" ;
    git clone git@gitlab.soe.ucsc.edu:cmps101/winter19-01/$cruzid.git ./$git_directory/
    cd $git_directory/$cruzid
    git checkout -b $branch_name `git rev-list -1 --before="$datestring" master`
done