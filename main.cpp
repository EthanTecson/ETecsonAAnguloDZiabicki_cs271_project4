#include "usecase.cpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Create the BST from the CSV file
    BST<string, string>* bst = create_bst<string, string>("binhex.txt");

    // // Test case 1
    // string bin1 = "110101";
    // string hex1 = convert(bst, bin1);
    // cout << "Hexadecimal representation of " << bin1 << " is " << hex1 << endl;

    // // Test case 2
    // string bin2 = "00110101"; // 35, size() = 8
    // string hex2 = convert(bst, bin2);
    // cout << "Hexadecimal representation of " << bin2 << " is " << hex2 << endl;


    string userInput;
    cout << "Enter binary representation for conversion:" << endl;
    getline(cin, userInput);
    string bin = userInput;
    string hex = convert(bst, bin);
    cout << "Hexidecimal representation of " << bin << " is " << hex << endl;

    // // Don't forget to delete the BST when you're done with it
    delete bst;

    cout << "Testing Completed" << endl;
    return 0;
}
