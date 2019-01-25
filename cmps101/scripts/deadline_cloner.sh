#!/bin/bash
argc=$#
program_name=$0

function usage_and_exit() {

    if [ "$argc" != "3" ] ;
    then
        echo "Invalid usage. Cannot continue executing the program."
        echo "usage: $program_name cruzid_list.txt DEADLINE_DateString DEST_BRANCH_NAME"
        echo "      example"
        echo "          $program_name cruzid_list.txt \"2019-01-01 23:59:59\""
        exit 1
    fi
}

usage_and_exit

filename=$1
datestring=$2
branch_name=$3
git_directory="cmps101_$branch_name"

echo "Starting git clone-ing. Project repositories will be created under ./$git_directory"
mkdir -p "$git_directory"

if ! [[ -e "$filename" ]] ;
then
    echo "File does not exist.";
    usage_and_exit ;
fi
base_directory=`pwd`
x=0
for cruzid in `cat $filename`;
do

    echo "Cloning repo for $cruzid" ;
    cd "$git_directory"
    git clone git@gitlab.soe.ucsc.edu:cmps101/winter19-01/$cruzid.git > /dev/null 2>&1
    cd "$cruzid"
    git checkout -b $branch_name `git rev-list -1 --until="$datestring" master`
    x=$(( $x+1 ))
    cd "$base_directory"

done
echo "git clone report:"
echo
echo "REPORT: Attempted to clone $x repositories under $base_directory/$git_directory"
echo "Confirming project repositories."
y=0
for cruzid in `cat $filename` ;
do
    if [[ -d "$git_directory/$cruzid" ]] ;
    then
        y=$(( $y+1 ))
    else
        echo "project for $cruzid not cloned. Please clone manually by running:"
        echo "1)    git clone git@gitlab.soe.ucsc.edu:cmps101/winter19-01/$cruzid.git"
        echo "2)    git checkout -b $branch_name `git rev-list -1 --until="$datestring" master`"
    fi
done

echo "Confirmed $y repositories cloned out of $x. All projects are located under $base_directory/$git_directory"