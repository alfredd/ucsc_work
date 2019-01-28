#!/usr/bin/env bash
workspace="~/cmps101-grading"
binaries="~/bin"
mkdir $binaries -p

mkdir $workspace
cd $workspace
workspace=`pwd`

unlink "$binaries/dc.sh"
unlink "$binaries/isltester"

wget https://github.com/alfredd/ucsc_work/archive/master.zip
unzip master.zip  -d cmps101_scripts


cd $workspace
ln -s "$workspace/cmps101_scripts/ucsc_work-master/cmps101/scripts/deadline_cloner.sh" "$binaries/dc.sh"

chmod +x "$workspace/cmps101_scripts/ucsc_work-master/cmps101/scripts/deadline_cloner.sh"

ln -s "$workspace/cmps101_scripts/ucsc_work-master/cmps101/scripts/deadline_cloner.sh" "$binaries/dc.sh"

chmod +x "$workspace/cmps101_scripts/ucsc_work-master/cmps101/scripts/sorttester.py"
ln -s "$workspace/cmps101_scripts/ucsc_work-master/cmps101/scripts/sorttester.py" "$binaries/isltester"
