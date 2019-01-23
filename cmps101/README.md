# Prerequisites
* g++
* cmake 2.8 (minimum)


# Build instructions
```asm
mkdir build     # create a build directory
cmake ..
make
```

# Run sorttester program

```sh
./sorttester test_resources/testcases.txt test_resources/InsertSortLinkedOutput.txt
```

# Sample output:
```sh
$ ./sorttester ../test_resources/testcases.txt ../test_resources/InsertSortLinkedOutput.txt 

3 line(s) verified in the file. 2 line(s) contain successfully sorted integers.
```