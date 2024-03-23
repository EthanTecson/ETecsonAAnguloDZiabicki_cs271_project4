# Makefile for project 4
# 
#-----------------------

all: test # runs everything at once

test: test_bst_example.o
		g++ -o test test_bst_example.o

test_hashtable_example.o: test_bst_example.cpp
		g++ -c test_bst_example.cpp


clean: # Removes all executable files that were made
		rm -f test *.o *.exe






#For when doin in vscode on Windows:
# del /Q /F test  *.o *.exe

#For when on linux & Mac:
# rm -f test *.o *.exe
