//-----------------------------------------------//
//              Binary Search Tree               //
//                 Testing File                  //
//                                               //
// Ethan Tecson, Andrew Angulo, Daniel Ziabicki  //
//-----------------------------------------------//

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "bst.cpp"

using namespace std;

// Empty Testing
/**
 * case 1: Test an empty BST
 * case 2: Insert into BST, test empty
 * case 3: Remove all elements from BST, test empty
 * case 4: negative key
 * case 5: Insert multiple elements and Remove All
 * case 6: Insert duplicate elements and then Remove one instance of duplicates
 */
void test_empty() {
    try
    {
        // case 1:
        BST<string, int> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result. List should be empty but got : " << bst.to_string() << endl;
        }
        // case 2:
        bst.insert("one",1);
        if(bst.empty()) {
            cout << "Incorrect empty result. BST should not be empty but got : "<< bst.to_string() <<  endl;
        }
        // case 3:
        bst.remove(1);
        if(!bst.empty()){
            cout << "Incorrect empty result. BST should be empty but got : " << bst.to_string() << endl;
        }
        // case 4:
        bst.insert("negative one", -1);
        if(bst.empty()) {
            cout << "Incorrect empty result. BST should not be empty but got : " << bst.to_string() << endl;
        }
        bst.remove(-1);

        // case 5:
        bst.insert("one",1);
        bst.insert("two", 2);
        bst.insert("three", 3);
        bst.insert("four", 4);
        bst.insert("five", 5);
        bst.insert("six", 6);
        // Remove all elements
        bst.remove(1);
        bst.remove(2);
        bst.remove(3);
        bst.remove(4);
        bst.remove(5);
        bst.remove(6);
        if (!bst.empty()) {
            cout << "Incorrect empty result. BST should not be empty but got : " << bst.to_string() << endl;
        }

        // case 6:
        bst.insert("eight", 8);
        bst.insert("eight", 8);
        bst.remove(8);
        if (bst.empty()) {
            cout << "Incorrect empty result. BST should not cbe empty but got : " << bst.to_string() << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}


// Insert Testing
/**
 * case 1: Insert into empty BST
 * case 2: Insert into already made BST
 * case 3: Inserting balanced values
 * case 4: Remove from BST and then insert into BST
 * case 5: Remove from middle of BST and then insert into BST
 * case 6: BST with floats
 * case 7: Inserting float balanced values
 * case 8: Inserting a bunch of negative values
 * case 9: Using strings as key and data
 */
void test_insert() {
    try {
        // case 1:
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        // case 2: 
        for(int i = 2; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }

        // case 3:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 6, 9, 4, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }

        // case 4:
        balanced_bst.remove(10);
        balanced_bst.insert("some data", 10);
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 6, 9, 4, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }

        // case 5:
        balanced_bst.remove(7);
        balanced_bst.insert("some data", 7);
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 7 10"){
            cout << "Incorrect result from inserting keys {5, 2, 8, 1, 3, 6, 9, 4, 7, 10}. Expected 5 2 8 1 3 6 9 4 7 10 but got : " << bst_str << endl;
        }

        // case 6:
        BST<float, float> float_bst;
        float_bst.insert(1.1, 1.1);
        if(float_bst.to_string() != "1.1") {
            cout << "Incorrect result of inserting (1.1, 1.1). Expected 1.1 but got : " << float_bst.to_string() << endl;
        }

        // case 7: 
        float float_vals[10] = {5.1, 2.1, 7.1, 1.1, 3.1, 4.1, 6.1, 9.1, 8.1, 10.1};
        BST<float, float> float_balanced_bst;
        float starting_float = 1.1;
        for(int i = 0; i < 10; i++) {
            float_balanced_bst.insert(starting_float, float_vals[i]);
            starting_float ++;
        }
        bst_str = float_balanced_bst.to_string();
        if(bst_str != "5.1 2.1 7.1 1.1 3.1 6.1 9.1 4.1 8.1 10.1") {
            cout << "Incorrect result of inserting keys {5.1, 2.1, 7.1, 1.1, 3.1, 6.1, 9.1, 4.1, 8.1, 10.1}. Expected 5.1 2.1 7.1 1.1 3.1 6.1 9.1 4.1 8.1 10.1 but got : " << bst_str << endl;
        }

        // case 8:
        int negative_vals[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
        BST<string, int> negative_bst;
        for(int i = 0; i < 10; i++) {
            negative_bst.insert("some data", negative_vals[i]);
        }
        bst_str = negative_bst.to_string();
        if (bst_str != "-1 -2 -3 -4 -5 -6 -7 -8 -9 -10"){
            cout << "Incorrect result of inserting keys -1 to -10 in order. Expected -1 -2 -3 -4 -5 -6 -7 -8 -9 -10 but got : " << bst_str << endl;
        }

        // case 9:
        string string_vals[10] = {"e", "b", "c", "d", "a", "f", "g", "h", "i", "j"};
        BST<string, string> string_bst;
        for(int i = 0; i < 10; i++) {
            string_bst.insert("some data", string_vals[i]);
        }
        if (string_bst.to_string() != "e b f a c g d h i j"){
            cout << "Incorrect result from inserting {e, b, f, a, c, g, d, h, i, j}. Expected e b f a c g d h i j but got : " << string_bst.to_string() << endl;
        }
        
    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

// Insert Testing
/**
 * case 1: Test an empty BST
 * case 2: Insert into BST, test get
 * case 3: Remove all elements from BST, test get
 * case 4: Test empty negative BST and then test with negative int data and key for both
 * case 5: Test empty float BST and then with float data and key
 * case 6: Test with string data and key
 */
void test_get() {
    try {
        // case 1:
        BST<string, int> bst;
        string val = bst.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        // case 2:
        bst.insert("one",1);
        val = bst.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
        // case 3:
        bst.remove(1);
        val = bst.get(1);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        
        // case 4:
        BST<int, int> negative_bst;
        int negative_val = negative_bst.get(0);
        if(negative_val!=0) {
            cout << "Incorrect get result from empty negative int bst. Expected 0 but got " << negative_val << endl;
        }
        int negative_vals[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
        int negative_num = -1;
        for(int i = 0; i < 10; i++) {
            negative_bst.insert(negative_num, negative_vals[i]);
            negative_num--;
        }
        negative_val = negative_bst.get(-5);
        if(negative_val!=-5) {
            cout << "Incorrect get result from empty bst. Expected -5 but got " << negative_val << endl;
        }

        // case 5:
        BST<float, float> float_bst;
        float float_val = float_bst.get(0.0);
        if(float_val!=0.0) {
            cout << "Incorrect get result from empty float bst. Expected 0 but got " << float_val << endl;
        }
        float float_vals[10] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
        float float_num = 1.1;
        for(int i = 0; i < 10; i++) {
            float_bst.insert(float_num, float_vals[i]);
            float_num = float_num + 1.1;
        }
        float_val = float_bst.get(5.5);
        if(float_val!=5.5) {
            cout << "Incorrect get result from float bst. Expected 5.5 but got " << float_val << endl;
        }

        // case 6:
        BST<string, string> string_bst;
        string string_val = string_bst.get(" ");
        if(string_val!="") {
            cout << "Incorrect get result from empty string bst. Expected 0 but got " << string_val << endl;
        }
        string string_vals[10] = {"e", "b", "c", "d", "a", "f", "g", "h", "i", "j"};
        for(int i = 0; i < 10; i++) {
            string_bst.insert("some data", string_vals[i]);
        }
        string_val = string_bst.get("f");
        if(string_val!="some data") {
            cout << "Incorrect get result from string bst. Expected 'some data' but got " << string_val << endl;
        }

    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}


// Remove Testing
/**
 * case 1: Test an empty BST
 * case 2: Test on balanced bst
 * case 3: Test where removed item has left child
 * case 4: Test where removed item has right child
 * case 5: Test on strings
 * case 6: Test on negatives
 */
void test_remove() {
    try {
        // case 1:
        try {
        BST<string, int> balanced_bst;
    
        // Attempt to remove from an empty BST
        balanced_bst.remove(0);

        }
        catch (exception& e) {
            // If an exception is caught, print the error message
            cerr << "Error occurred while trying to remove from an empty BST: " << e.what() << endl;
        }

        // case 2:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }

        // case 3:
        BST<string, int> bst;
        bst.insert("some data", 5);
        bst.insert("some data", 4);
        bst.remove(5);
        if(bst.to_string() != "4") {
            cout << "Incorrect result of removing the root that has a left child (5). Expected 4 but got : " << bst.to_string() << endl;
        }

        // case 4:
        bst.insert("some data", 5);
        bst.remove(4);
        if(bst.to_string() != "5") {
            cout << "Incorrect result of removing the root that has a right child (4). Expected 5 but got : " << bst.to_string() << endl;
        }

        // case 5:
        BST<string, string> string_bst;
        string_bst.insert("some data", "e"); 
        string_bst.insert("some data", "b");
        string_bst.insert("some data", "g");
        string_bst.insert("some data", "a");
        string_bst.insert("some data", "c");
        string_bst.insert("some data", "d");
        string_bst.insert("some data", "f");
        string_bst.insert("some data", "i");
        string_bst.insert("some data", "h");
        string_bst.insert("some data", "j"); 

        // node with only right child
        string_bst.remove("c");
        if(string_bst.to_string()!= "e b g a d f i h j") {
            cout << "Incorrect result with removing from string BST. Tried removing node with only right child (c) and expected e b g a d f i h j but got : " << string_bst.to_string() << endl;
        }

        // Removing right child of root that has both right and left child
        string_bst.remove("g");
        if(string_bst.to_string()!= "e b h a d f i j") {
            cout << "Incorrect result with removing from string BST. Tried removing node with right and left child (g) and expected e b h a d f i j but got : " << string_bst.to_string() << endl;
        }

        // Removing Root
        string_bst.remove("e");
        if(string_bst.to_string()!= "f b h a d i j") {
            cout << "Incorrect result with removing from string BST. Tried removing root (e) and expected f b h a d i j but got : " << string_bst.to_string() << endl;
        }

        // Case 6:
        BST<string, int> negative_bst;
        int negative_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        for(int i = 0; i < 10; i++) {
            negative_bst.insert("some data", negative_vals[i]);
        }

        // node with only right child
        negative_bst.remove(-3);
        if(negative_bst.to_string()!= "-5 -7 -2 -9 -6 -4 -1 -10 -8") {
            cout << "Incorrect result with removing from negative int BST. Tried removing node with only right child (-4) and expected -5 -7 -2 -9 -6 -4 -1 -10 -8 but got : " << negative_bst.to_string() << endl;
        }

        // Removing right child of root that has both right and left child
        negative_bst.remove(-7);
        if(negative_bst.to_string() != "-5 -6 -2 -9 -4 -1 -10 -8") {
            cout << "Incorect result with removing form negative int BST. Tried removing node with right and left child (-7) and expected -5 -6 -2 -9 -4 -1 -10 -8 but got : " << negative_bst.to_string() << endl;
        }

        // Removing Root
        negative_bst.remove(-5);
        if(negative_bst.to_string()!="-4 -6 -2 -9 -1 -10 -8") {
            cout << "Incorrect result with removing from negative int BST. Tried removing root (-5) and expected -4 -6 -2 -9 -1 -10 -8 but got : " << negative_bst.to_string() << endl;
        }


    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

// max_data Testing
// 1. max_data from empty tree
// 2. Insert into BST, then test remove
// 3. DIfferent data types and data/key values
//   a. int data and int key
//   b. float data and float key
//   c. string data and string key
//   d. negative data and negative key
void test_max_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

// max_key Testing
// 1. max_key from empty tree
// 2. Insert into BST, then test remove
// 3. DIfferent data types and data/key values
//   a. int data and int key
//   b. float data and float key
//   c. string data and string key
//   d. negative data and negative key
void test_max_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

// min_data Testing
// 1. min_data from empty tree
// 2. Insert into BST, then test remove
// 3. DIfferent data types and data/key values
//   a. int data and int key
//   b. float data and float key
//   c. string data and string key
//   d. negative data and negative key
void test_min_data() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

// min_key Testing
// 1. min_key from empty tree
// 2. Insert into BST, then test remove
// 3. DIfferent data types and data/key values
//   a. int data and int key
//   b. float data and float key
//   c. string data and string key
//   d. negative data and negative key
void test_min_key() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

// Successor Testing
// 1. in_order from empty tree
// 2. Insert into BST, then test case where successor is node->right.min()
// 3. Test case where successor is an ancestor that is eventually a left child
// 4. Test case where successor is the root
// 5. DIfferent data types and data/key values
//   a. int data and int key
//   b. float data and float key
//   c. string data and string key
//   d. negative data and negative key (This is really important to think about)
void test_successor() {
    try {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if(succ != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if(succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

// in_order Testing
// 1. in_order test on empty tree
// 2. Insert into BST, then test in_order
// 3. DIfferent data types and data/key values
//   a. int key
//   b. float key
//   c. string key
//   d. negative key (This is really important to think about)
void test_in_order() {
    try {
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

// Trim Testing
// 1. trim testing for empty tree
// 2. Insert a bunch into BST, then test different ranges of trim
// 3. Try negative trim values
// 4. Try trim with 0
// 5. DIfferent data types and data/key values
//   a. int key
//   b. float key
//   c. string key
//   d. negative key (This is really important to think about)
void test_trim() {
    try {
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

// void test_binhex(){
//     try {
//         BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
//         string bin1 = "111010100101";
//         string expected_hex1 = "EA5";

//         string hex1 = convert<string,string>(bst1, bin1);
//         delete bst1;

//         if(hex1!=expected_hex1) {
//             cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
//         }
       
//     } catch(exception& e) {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }

//     try {
//         BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
//         string bin2 = "110101";
//         string expected_hex2 = "35";

//         string hex2 = convert<string,string>(bst2, bin2);
//         delete bst2;

//         if(hex2!=expected_hex2) {
//             cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
//         }
       
//     } catch(exception& e) {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }
// }

int main() {
    
    test_empty();
    test_insert();
    test_get();
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    test_trim();
    // test_binhex();

    cout << "Testing completed" << endl;
    
    return 0;
}
