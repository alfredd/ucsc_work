#!/usr/bin/env bash
if [ "$#" != "1" ] ;
then
    echo "USAGE: $0 setup|clean"
    exit 1
fi

if [ "$1" == "setup" ] ;
then
    echo "Setting up scripts for grading CMPS 101 assignments."
    sleep 1

    cd
    workspace=".cmps101-ta"
    binaries="bin"
    mkdir bin -p
    cd $binaries
    binaries=`pwd`
    unlink "$binaries/dc.sh"
    unlink "$binaries/isltester"

    cd

    mkdir $workspace -p
    cd $workspace
    workspace=`pwd`


    wget https://github.com/alfredd/ucsc_work/archive/master.zip
    unzip master.zip  -d scripts


    cd $workspace

    chmod +x "$workspace/scripts/ucsc_work-master/cmps101/scripts/deadline_cloner.sh"
    ln -s "$workspace/scripts/ucsc_work-master/cmps101/scripts/deadline_cloner.sh" "$binaries/dc.sh"


    chmod +x "$workspace/scripts/ucsc_work-master/cmps101/scripts/sorttester.py"
    ln -s "$workspace/scripts/ucsc_work-master/cmps101/scripts/sorttester.py" "$binaries/isltester"

    rm "$workspace/master.zip" -rf

    echo
    echo "---------------------------------------------------------------------------------"
    echo "Scripts are installed under $binaries. Executables are setup under $workspace. Please do not delete this directory."
    echo "---------------------------------------------------------------------------------"

elif [ "$1" == "clean" ]
then
    echo "Deleting all CMPS 101 grading scripts."
    cd
    workspace=".cmps101-ta"
    binaries="bin"
    unlink "$binaries/dc.sh"
    unlink "$binaries/isltester"
    rm $workspace -rf
    echo
    echo "Unlinked and Deleted: "
    echo "    $binaries/dc.sh"
    echo "    $binaries/isltester"
    echo "    $workspace"
else
    echo "USAGE: $0 setup|clean"
fi
