/*
 * Use your BST to solve the following problem:
 * You are given a csv file in which each line represents a hex, bin pair where each bin is a 4-bit binary and each
 * hex is the corresponding 1 digit hexadecimal. Use the csv to build a BST using your BST class where each
 * node in the tree is characterized by: (1) a key of the 4-bit binary and (2) data denoting the corresponding
 * hexadecimal conversion. Your program should then accomplish the following:
 * - Ask the user for a binary value for conversion.
 * - Convert the binary value to the corresponding hexadecimal.
 * - Display the result.
 * 
 * Two examples might be as follows:
 *
 * Enter binary representation for conversion:
 * 111010100101
 * Hexadecimal representation of 111010100101 is EA5
 * Enter binary representation for conversion:
 * 110101
 * Hexadecimal representation of 110101 is 35
 *
 */

#include "bst.cpp"
#include "usecase.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <bitset>

using namespace std;
template <typename Data, typename Key>
BinarySearchTree<Data, Key>* create_bst(string fname){ //fname is the CSV file name
    
    // Opening the file
    ifstream file(fname);
    string line;

    // Creating empty BST
    BST<Data, Key> fileBST;

    // Reading data (All info from Data Systems)
    while(getline(file, line)){
        stringstream ss(line);
        string item;
        Data d;
        Key k;

        // Get the values from each line
        getline(ss, item, ',');
        data = static_cast<Data>(stoi(item)); //Grabs the hexadecimal
        getline(ss, item, ',');
        key = static_cast<Key>(stoi(item)); //Grabs the Binary value

        fileBST.insert(data, key)

    }

    return fileBST;
} 

// Using bitset function to convert binary to hex
string bin_to_hex(string bin){
    bitset<32> set(bin_str);
    stringstream hex_stream;
    hex_stream << hex << set.to_ulong();
    return hex_stream.str(); //hex as a string
}

template<typename Data, typename Key>
string convert(BinarySearchTree<D, K>* bst, string bin){
    string hexValue = bin_to_hex(bin); //Hex value

    //Searching the node based on the Hex value which is data and returning the key
    return bst->searchData(bst->root, hexValue)->key; 
}

