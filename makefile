# Makefile for project 4
# 
#-----------------------

all: test usecase CTest MTest # runs everything at once

test: test_bst_example.o
		g++ -o test test_bst_example.o bst.cpp

test_bst_example.o: test_bst_example.cpp
		g++ -c test_bst_example.cpp

usecase: main.o
		g++ -o usecase main.o bst.cpp usecase.cpp

main.o:
		g++ -c main.cpp

CTest: test_bst_charlie.o
		g++ -o CTest test_bst_charlie.o bst.cpp

test_bst_charlie.o: test_bst_charlie.cpp
		g++ -c test_bst_charlie.cpp

MTest: test_bst.o # CHANGE THIS TO 'TEST' LATER (Only have this name due to multiple test files)
		g++ -o MTest test_bst.o bst.cpp

test_bst.o: test_bst.cpp
		g++ -c test_bst.cpp

clean: # Removes all executable files that were made
		# rm -f test usecase CTest MTest *.o *.exe






#For when doin in vscode on Windows:
# del /Q /F test usecase *.o *.exe

#For when on linux & Mac:
# rm -f test usecase *.o *.exe
