#!/usr/local/bin/python3
import sys


def getIntegerListFromFile(filepath):
    nn = []

    with open(filepath) as fp:
        line = fp.readline()
        cnt = 1
        while line:
            n=[]
            line = line.strip()
            sn = line.split(" ")
            for i in sn:
                if i.isdigit():
                    n.append(int(i))

            nn.append(n)
            cnt += 1
            line = fp.readline()
    return nn


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("Usage: %s input.txt output.txt" % sys.argv[0])
        exit(1)
    sorted_nums, unsorted_nums = [], []
    unsortd = getIntegerListFromFile(sys.argv[1])
    sorted = getIntegerListFromFile(sys.argv[2])
    sortedResults=[]
    for i in range(0,len(unsortd)):
        if len(sorted[i]) != len(unsortd[i]):
            sortedResults.append(False)
            continue
        for j in range(0, len(unsortd[i])):
            unsortd[i].sort()
            if sorted[i][j] != unsortd[i][j]:
                equal=False
                sortedResults.append(equal)
                continue
        sortedResults.append(True)
    count =0
    for i in sortedResults:
        count = count+1 if i is True else count
    print("%d lines of %d are sorted." %(count, len(sorted)))

