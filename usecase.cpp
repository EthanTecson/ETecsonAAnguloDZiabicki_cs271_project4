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
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

template <typename Data, typename Key>
BST<Data, Key>* create_bst(string fname){ //fname is the CSV file name
    
    // Opening the file
    ifstream file(fname);
    string line;

    // Creating empty BST
    BST<Data, Key>* fileBST = new BST<Data, Key>;

    // Reading data (All info from Data Systems)
    while(getline(file, line)){
        stringstream ss(line);
        string item;
        Data data;
        Key key;

        // Get the values from each line
        getline(ss, item, ',');
        data = item; //Grabs the hexadecimal
        getline(ss, item, ',');
        key = item; //Grabs the Binary value

        fileBST->insert(data, key);

    }

    return fileBST;
} 

template<typename Data, typename Key>
string convert(BST<Data, Key>* bst, string bin){

    stringstream hex_value;

    // bin is less than 4
    if (bin.size() < 4){
        while (bin.size() < 4){
            bin = "0" + bin;
        }
    }
    if (bin.size() % 4 != 0){
        while (bin.size() % 4 != 0){
            bin = "0" + bin;
        }
    }

    // regular operations
    for (int i = 0; i < bin.size(); i+=4){
        string substring = bin.substr(i,4);
        hex_value << bst->search(bst->getRoot(), substring)->getData();
    } 

    return hex_value.str();
}