#ifndef USECASE_H
#define USECASE_H
using namespace std;
#include <iostream>
#include "bst.cpp" 

// Create BST from a CSV file
template <typename D, typename K>
BinarySearchTree<Data, Key>* create_bst(string fname); //fname is the CSV file name

// Convert binary to hexadecimal using BST
template <typename Data, typename Key>
string convert(BinarySearchTree<D, K>* bst, string bin);


string bin_to_hex(string bin_str) const;

#endif // USECASE_H
