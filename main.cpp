//-----------------------------------------------//
//              Binary Search Tree               //
//               Usecase Testing                 //
//                                               //
// Ethan Tecson, Andrew Angulo, Daniel Ziabicki  //
//-----------------------------------------------//

#include "usecase.cpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    // Create the BST from the CSV file
    BST<string, string>* bst = create_bst<string, string>("binhex.txt");

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
