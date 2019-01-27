//
// Created by alfredd on 1/22/19.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void VerifySorted(FILE *unsortedFD, FILE *sortedFD);

void GetIntegerArrayFromLine(char *sortedLine,vector<int> *v);

int CompareIntegerArrays(vector<int> *v1, vector<int> *v2);

int CountOnes(int *array, int index);

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
        out1 = getline(&sortedLine, &sortedLength, sortedFD);
        out2 = getline(&unsortedLine, &unsortedLength, unsortedFD);


        vector<int> *v1, *v2;
        v1= new vector<int>;
        v2= new vector<int>;
        GetIntegerArrayFromLine(sortedLine, v1);


        GetIntegerArrayFromLine(unsortedLine, v2);

        if(v1->size() != v2->size()) {
            results[resultIndex]=0;
        } else {
            results[resultIndex]=CompareIntegerArrays(v1, v2);
        }
        free(sortedLine);
        free(unsortedLine);
        delete v1;
        delete v2;
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

int CompareIntegerArrays(vector<int> *v1, vector<int> *v2) {

    sort(v2->begin(), v2->end());

    int status=1;
    int i=0;
    for(i =0;i<v1->size();i++) {
        if (v1->at(i) !=v2->at(i)) {
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

void GetIntegerArrayFromLine(char *sortedLine,vector<int> *v) {
    char *found = sortedLine;
    while (true) {
        char * end = strchr(found, ' ');
        int value = strtol(found,&end,10);
        v->push_back(value);
        found = end+1;
        if (strcmp(end, "\n")==0) {
            break;
        }
    }
}