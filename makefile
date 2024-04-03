# Makefile for project 4
# 
#-----------------------

all: test usecase # runs everything at once

test: test_bst.o # CHANGE THIS TO 'TEST' LATER (Only have this name due to multiple test files)
		g++ -o test test_bst.o bst.cpp

test_bst.o: test_bst.cpp
		g++ -c test_bst.cpp

usecase: main.o
		g++ -o usecase main.o bst.cpp usecase.cpp

main.o:
		g++ -c main.cpp

clean: # Removes all executable files that were made
		rm -f test usecase *.o *.exe





#For when doin in vscode on Windows:
# del /Q /F test usecase CTest MTest *.o *.exe

#For when on linux & Mac:
# rm -f test usecase *.o *.exe
