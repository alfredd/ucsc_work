# Prerequisites
* g++
* cmake 2.8 (minimum) OR make

# Build and run via make

```sh
make
./sorttester test_resources/testcases.txt test_resources/Incorrect_InsertSortLinkedOutput.txt
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
* 2 out of 3 lines are correctly sorted in the test_resources/Incorrect_InsertSortLinkedOutput.txt file.
```sh
./sorttester test_resources/testcases.txt test_resources/Incorrect_InsertSortLinkedOutput.txt 

3 line(s) verified in the file. 2 line(s) contain successfully sorted integers.
```

* 3 out of 3 lines are correctly sorted in the test_resources/Correct_InsertSortLinkedOutput.txt file.
```sh
./sorttester test_resources/testcases.txt test_resources/Correct_InsertSortLinkedOutput.txt 

3 line(s) verified in the file. 3 line(s) contain successfully sorted integers.
```