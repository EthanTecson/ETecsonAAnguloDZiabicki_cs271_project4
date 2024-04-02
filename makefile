# Makefile for project 4
# 
#-----------------------

all: test usecase # runs everything at once

test: test_bst_example.o
		g++ -o test test_bst_example.o bst.cpp

test_bst_example.o: test_bst_example.cpp
		g++ -c test_bst_example.cpp

usecase: main.o
		g++ -o usecase main.o bst.cpp usecase.cpp

main.o:
		g++ -c main.cpp
clean: # Removes all executable files that were made
		rm -f test usecase *.o *.exe





#For when doin in vscode on Windows:
# del /Q /F test usecase *.o *.exe

#For when on linux & Mac:
# rm -f test usecase *.o *.exe
