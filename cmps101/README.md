# Prerequisites
* g++
* cmake 2.8 (minimum) OR make

# Build and run via make

```sh
make
./sorttester test_resources/testcases.txt test_resources/InsertSortLinkedOutput.txt
```

# Build and run via Cmake 
```sh
mkdir build     # create a build directory
cd build
cmake ..
make
./sorttester test_resources/testcases.txt test_resources/InsertSortLinkedOutput.txt
```

# Sample output:
```sh
./sorttester ../test_resources/testcases.txt ../test_resources/InsertSortLinkedOutput.txt 

3 line(s) verified in the file. 2 line(s) contain successfully sorted integers.
```