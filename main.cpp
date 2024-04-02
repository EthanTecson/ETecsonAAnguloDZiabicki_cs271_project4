#include "usecase.cpp"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // Create the BST from the CSV file
    BinarySearchTree<string, string>* bst = create_bst("binhex.txt");

    // Test case 1
    string bin1 = "111010100101";
    string hex1 = convert(bst, bin1);
    cout << "Hexadecimal representation of " << bin1 << " is " << hex1 << endl;

    // Test case 2
    string bin2 = "110101";
    string hex2 = convert(bst, bin2);
    cout << "Hexadecimal representation of " << bin2 << " is " << hex2 << endl;

    // Don't forget to delete the BST when you're done with it
    delete bst;

    cout << "Testing Completed" << endl;
    return 0;
}
