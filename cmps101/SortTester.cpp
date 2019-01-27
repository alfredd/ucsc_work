//
// Created by alfredd on 1/22/19.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>


void VerifySorted(FILE *unsortedFD, FILE *sortedFD);

int GetIntegerArrayFromLine(char *sortedLine, int *temp);

int CompareIntegerArrays(int *sa, int n1, int *usa, int n2);

int CountOnes(int *array, int index);

using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <TestCasesInput.txt> <SortedOutputFromInsertSortLinked.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *unsortedFD = fopen(argv[1], "r");
    FILE *sortedFD = fopen(argv[2], "r");
    VerifySorted(unsortedFD, sortedFD);
    fclose(unsortedFD);
    fclose(sortedFD);
}

void VerifySorted(FILE *unsortedFD, FILE *sortedFD) {
    int results[100000]={0}, resultIndex=0, out1, out2;
    while (true) {
        char *sortedLine, *unsortedLine;
        size_t sortedLength, unsortedLength;
        out1= getline(&sortedLine, &sortedLength, sortedFD);


        int sortedArray[100000] = {0};
        int n1 = GetIntegerArrayFromLine(sortedLine, sortedArray);
        int unsortedArray [100000] = {0};

        out2 = getline(&unsortedLine, &unsortedLength, unsortedFD);
        int n2 = GetIntegerArrayFromLine(unsortedLine, unsortedArray);
        if(n1!=n2) {
            results[resultIndex]=0;
        } else {
            results[resultIndex]=CompareIntegerArrays(sortedArray, n1,unsortedArray, n2);
        }
//        free(unsortedArray);
        free(sortedLine);
        free(unsortedLine);
        if (out1==-1 || out2==-1)
            break;
        printf("Verified line %d, sorted? %d (0 means not sorted, 1 means sorted)\n", resultIndex, results[resultIndex]);

        resultIndex+=1;
    }
    if(out2!= out1) {
        printf("Mismatch in the number of lines in the input text files.\n");
    }
    printf("\n\nRESULTS:\n\t%d line(s) verified in the file. %d line(s) contain successfully sorted integers.\n", resultIndex, CountOnes(results, resultIndex));
}

int CountOnes(int *array, int index) {
    int ones=0;
    for (int i = 0; i < index; ++i) {
        if(array[i] ==1 )
            ++ones;
    }
    return ones;
}

int CompareIntegerArrays(int *sa, int n1, int *usa, int n2) {
    vector<int> v1;// = new vector<int>;
    for (int j = 0; j < n2; ++j) {
        v1.push_back(usa[j]);
    }
    sort(v1.begin(), v1.end());
    int status=1;
    for(int i =0;i<n1;i++) {
        if (v1.at(i) != sa[i]) {
            status=0;
            break;
        }
    }
    return status;
}

/*
int GetIntegerArrayFromLine(char *sortedLine, int *temp) {
    int n = 0;
    char *found = sortedLine;
    while (found != NULL) {
        sscanf(&sortedLine[found - sortedLine], "%d", &temp[n]);
        found = strchr(&sortedLine[(found - sortedLine + 1)], ' ');
        n += 1;
    }
    return  n;
}*/

int GetIntegerArrayFromLine(char *sortedLine, int *temp) {
    int n = 0;
    char *found = sortedLine;
    while (true) {

        char * end = strchr(found, ' ');
        int value = strtol(found,&end,10);
        temp[n]=value;
        found = end+1;
        n += 1;
        if (strcmp(end, "\n")==0) {
            break;
        }
    }
    return  n;
}