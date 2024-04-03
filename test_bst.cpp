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

// empty Testing
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


// insert Testing
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

// get Testing
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


// remove Testing
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

// max_data testing
/**
 * case 1: max_data from empty tree
 * case 2: Test on balanced bst
 * case 3: Test after remove
 * case 4: Test on int
 * case 5: Test on negative values
 * case 6: Test on string data
 */
void test_max_data() {
    try {
        // case 1:
        BST<string, int> empty_bst;
        if(empty_bst.max_data() != ""){
            cout << "Incorrect result of max_data. Expected 0 but got : " << empty_bst.max_data() << endl;
        }

        // case 2:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }

        // case 3:
        balanced_bst.remove(10);
        if (balanced_bst.max_data() != "9 data") {
            cout << "Incorrect result of max_data. Expected \"9 data\" but got : " << balanced_bst.max_data() << endl;
        }

        // case 4:
        BST<int, int> int_bst;
        if(int_bst.max_data() != 0){
            cout << "Incorrect result of max_data. Expected 0 but got : " << int_bst.max_data() << endl;
        }

        int int_vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        for(int i = 0; i < 10; i++) {
            int_bst.insert(i + 1, int_vals[i]);
        }

        if(int_bst.max_data() != 10){
            cout << "Incorrect result of max_data. Expected 10 but got : " << int_bst.max_data() << endl; 
        }

        // case 5:
        int negative_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        BST<int, int> negative_balanced_bst;
        for(int i = 0; i < 10; i++) {
            negative_balanced_bst.insert(negative_vals[i], negative_vals[i]);
        }

        if(negative_balanced_bst.max_data() != -1){
            cout << "Incorrect result of max_data. Expected -1 but got : " << negative_balanced_bst.max_data() << endl;
        }

        // case 6:
        BST<string, string> string_bst;

        if(string_bst.max_data() != ""){
            cout << "Incorrect result of max_key. Expected '' but got : " << string_bst.max_key() << endl;
        }

        string_bst.insert("1", "e"); 
        string_bst.insert("2", "b");
        string_bst.insert("3", "g");
        string_bst.insert("4", "a");
        string_bst.insert("5", "c");
        string_bst.insert("6", "d");
        string_bst.insert("7", "f");
        string_bst.insert("8", "i");
        string_bst.insert("9", "h");
        string_bst.insert("10", "j"); 

        if(string_bst.max_data() != "10"){
            cout << "Incorrect result of max_data. Expected '10' but got : " << string_bst.max_data() << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

// max_key testing
/**
 * case 1: max_key from empty tree
 * case 2: Test on balanced bst
 * case 3: Test after remove
 * case 4: Test on negative values
 * case 5: Test on string keys
 */
void test_max_key() {
    try {
        // case 1:
        BST<string, int> empty_bst;
        if(empty_bst.max_key() != 0){
            cout << "Incorrect result of max_key. Expected 0 but got : " << empty_bst.max_key() << endl;
        }

        // case 2:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }

        // case 3:
        balanced_bst.remove(8);
        if (balanced_bst.max_key() != 10){
            cout << "Incorrect result of max_key. Expected 10 but got : " << balanced_bst.max_key() << endl;
        }
        balanced_bst.remove(10);
        if (balanced_bst.max_key() != 9){
            cout << "Incorrect result of max_key. Expected 9 but got : " << balanced_bst.max_key() << endl;
        }

        // case 4:
        int negative_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        BST<string, int> negative_balanced_bst;
        for(int i = 0; i < 10; i++) {
            negative_balanced_bst.insert(to_string(negative_vals[i]) + " data", negative_vals[i]);
        }

        if(negative_balanced_bst.max_key() != -1){
            cout << "Incorrect result of max_key. Expected -1 but got : " << negative_balanced_bst.max_key() << endl;
        }

        // case 5:
        BST<string, string> string_bst;

        if(string_bst.max_key() != ""){
            cout << "Incorrect result of max_key. Expected '' but got : " << string_bst.max_key() << endl;
        }

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

        if(string_bst.max_key() != "j"){
            cout << "Incorrect result of max_key. Expected k but got : " << string_bst.max_key() << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

// min_data testing
/**
 * case 1: min_data from empty tree
 * case 2: Test on balanced bst
 * case 3: Test after remove
 * case 4: Test on int
 * case 5: Test on negative values
 * case 6: Test on string data
 */
void test_min_data() {
    try {
        // case 1:
        BST<string, int> empty_bst;
        if(empty_bst.min_data() != ""){
            cout << "Incorrect result of min_data. Expected 0 but got : " << empty_bst.min_data() << endl;
        }

        // case 2:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }

        // case 3:
        balanced_bst.remove(1);
        if (balanced_bst.min_data() != "2 data") {
            cout << "Incorrect result of min_data. Expected \"2 data\" but got : " << balanced_bst.min_data() << endl;
        }

        // case 4:
        BST<int, int> int_bst;
        if(int_bst.min_data() != 0){
            cout << "Incorrect result of min_data. Expected 0 but got : " << int_bst.min_data() << endl;
        }

        int int_vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        for(int i = 0; i < 10; i++) {
            int_bst.insert(i + 1, int_vals[i]);
        }

        if(int_bst.min_data() != 4){
            cout << "Incorrect result of min_data. Expected 4 but got : " << int_bst.min_data() << endl; 
        }

        // case 5:
        int negative_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        BST<int, int> negative_balanced_bst;
        for(int i = 0; i < 10; i++) {
            negative_balanced_bst.insert(negative_vals[i], negative_vals[i]);
        }

        if(negative_balanced_bst.min_data() != -10){
            cout << "Incorrect result of min_data. Expected -10 but got : " << negative_balanced_bst.min_data() << endl;
        }

        // case 6:
        BST<string, string> string_bst;

        if(string_bst.min_data() != ""){
            cout << "Incorrect result of min_data. Expected '' but got : " << string_bst.min_data() << endl;
        }

        string_bst.insert("1", "e"); 
        string_bst.insert("2", "b");
        string_bst.insert("3", "g");
        string_bst.insert("4", "a");
        string_bst.insert("5", "c");
        string_bst.insert("6", "d");
        string_bst.insert("7", "f");
        string_bst.insert("8", "i");
        string_bst.insert("9", "h");
        string_bst.insert("10", "j"); 

        if(string_bst.min_data() != "4"){
            cout << "Incorrect result of min_data. Expected '4' but got : " << string_bst.min_data() << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

// min_key testing
/**
 * case 1: min_key from empty tree
 * case 2: Test on balanced bst
 * case 3: Test after remove
 * case 4: Test on negative values
 * case 5: Test on string keys
 */
void test_min_key() {
    try {
        // case 1:
        BST<string, int> empty_bst;
        if(empty_bst.min_key() != 0){
            cout << "Incorrect result of min_key. Expected 0 but got : " << empty_bst.min_key() << endl;
        }

        // case 2:
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 1 but got : " << min_k << endl;
        }

        // case 3:
        balanced_bst.remove(3);
        if (balanced_bst.min_key() != 1){
            cout << "Incorrect result of min_key. Expected 1 but got : " << balanced_bst.min_key() << endl;
        }
        balanced_bst.remove(1);
        if (balanced_bst.min_key() != 2){
            cout << "Incorrect result of min_key. Expected 2 but got : " << balanced_bst.min_key() << endl;
        }

        // case 4:
        int negative_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        BST<string, int> negative_balanced_bst;
        for(int i = 0; i < 10; i++) {
            negative_balanced_bst.insert(to_string(negative_vals[i]) + " data", negative_vals[i]);
        }

        if(negative_balanced_bst.min_key() != -10){
            cout << "Incorrect result of min_key. Expected -10 but got : " << negative_balanced_bst.min_key() << endl;
        }

        // case 5:
        BST<string, string> string_bst;

        if(string_bst.min_key() != ""){
            cout << "Incorrect result of max_key. Expected '' but got : " << string_bst.max_key() << endl;
        }

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

        if(string_bst.min_key() != "a"){
            cout << "Incorrect result of min_key. Expected a but got : " << string_bst.min_key() << endl;
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
        BST<int, int> int_tree;
        int succ = int_tree.successor(0);
        if(succ != 0) {
            cout << "Incorrect result of successor of 0. Expected 0 but got : " << succ << endl;
        }
        int vals1[13] = {-3, -8, -17, 5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        for(int i = 0; i < 13; i++){
            int_tree.insert(vals1[i], vals1[i]);
        }
        succ = int_tree.successor(3);
        if(succ != 4) {
            cout << "Incorrect result of successor of 3. Expected 4 but got : " << succ << endl;
        }
        succ = int_tree.successor(5);
        if(succ != 6) {
            cout << "Incorrect result of successor of 5. Expected 6 but got : " << succ << endl;
        }
        succ = int_tree.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
        succ = int_tree.successor(9);
        if(succ != 10) {
            cout << "Incorrect result of successor of 9. Expected 10 but got : " << succ << endl;
        }
        succ = int_tree.successor(-3);
        if(succ != 1) {
            cout << "Incorrect result of successor of -3. Expected 1 but got : " << succ << endl;
        }
        succ = int_tree.successor(-5);
        if(succ != 0) {
            cout << "Incorrect result of successor of -5. Expected 0 but got : " << succ << endl;
        }

        //====================================================================================================
        
        BST<float, float> float_tree;
        float succ_flo = float_tree.successor(0);
        if(succ_flo != 0) {
            cout << "Incorrect result of successor of 0. Expected 0 but got : " << succ_flo << endl;
        }
        float vals2[13] = {-3.1, -8.2, -17.3, 5.4, 2.5, 7.6, 1.7, 3.8, 4.9, 6.1, 9.2, 8.3, 10.4};
        for(int i = 0; i < 13; i++){
            float_tree.insert(vals2[i], vals2[i]);
        }
        succ_flo = float_tree.successor(-3.1);
        if(std::to_string(succ_flo).substr(0, 3) != "1.7") {
            cout << "Incorrect result of successor of -3.1. Expected 1.7 but got : " << succ_flo << endl;
        }
        succ_flo = float_tree.successor(5.4);
        if(std::to_string(succ_flo).substr(0, 3) != "6.1") {
            cout << "Incorrect result of successor of 5.4. Expected 6.1 but got : " << succ_flo << endl;
        }
        succ_flo = float_tree.successor(10.4);
        if(std::to_string(succ_flo).substr(0, 1) != "0") {
            cout << "Incorrect result of successor of 10.4. Expected 0 but got : " << succ_flo << endl;
        }
        succ_flo = float_tree.successor(9.2);
        if(std::to_string(succ_flo).substr(0, 4) != "10.4") {
            cout << "Incorrect result of successor of 9.2 Expected 10.4 but got : " << succ_flo << endl;
        }
        succ_flo = float_tree.successor(-5);
        if(std::to_string(succ_flo).substr(0, 1) != "0") {
            cout << "Incorrect result of successor of -5. Expected 0 but got : " << succ_flo << endl;
        }
        succ_flo = float_tree.successor(8.3);
        cout << succ_flo << endl;
        if(std::to_string(succ_flo).substr(0, 3) != "9.2") {
            cout << "Incorrect result of successor of 8.3. Expected 9.2 but got : " << succ_flo << endl;
        }

        //====================================================================================================
        
        BST<string, string> string_tree;
        string succ_str = string_tree.successor("benjamin");
        if(succ_str != "") {
            cout << "Incorrect result of successor of benjamin. Expected  but got : " << succ_str << endl;
        }
        string vals3[5] = {"hello", "world", "hello world", "green", "apple"};
        for(int i = 0; i < 5; i++){
            string_tree.insert(vals3[i], vals3[i]);
        }
        succ_str = string_tree.successor("apple");
        if(succ_str != "green") {
            cout << "Incorrect result of successor of apple. Expected green but got : " << succ_str << endl;
        }
        succ_str = string_tree.successor("hello");
        if(succ_str != "hello world") {
            cout << "Incorrect result of successor of hello. Expected hello world but got : " << succ_str << endl;
        }
        succ_str = string_tree.successor("hello world");
        if(succ_str != "world") {
            cout << "Incorrect result of successor of hello world. Expected world but got : " << succ_str << endl;
        }
        succ_str = string_tree.successor("green");
        if(succ_str != "hello") {
            cout << "Incorrect result of successor of green Expected hello but got : " << succ_str << endl;
        }
        succ_str = string_tree.successor("homer simpson");
        if(succ_str != "") {
            cout << "Incorrect result of successor of homer simpson Expected  but got : " << succ_str << endl;
        }

        //====================================================================================================
        
        BST<char, char> char_tree;
        char succ_char;
        char vals4[5] = {'a', 'b', 'c', 'd', 'e'};
        for(int i = 0; i < 5; i++){
            char_tree.insert(vals4[i], vals4[i]);
        }
        succ_char = char_tree.successor('a');
        if(succ_char != 'b') {
            cout << "Incorrect result of successor of a. Expected b but got : " << succ_char << endl;
        }
        succ_char = char_tree.successor('b');
        if(succ_char != 'c') {
            cout << "Incorrect result of successor of b. Expected c but got : " << succ_char << endl;
        }
        succ_char = char_tree.successor('c');
        if(succ_char != 'd') {
            cout << "Incorrect result of successor of c. Expected d but got : " << succ_char << endl;
        }
        succ_char = char_tree.successor('d');
        if(succ_char != 'e') {
            cout << "Incorrect result of successor of d Expected e but got : " << succ_char << endl;
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
        string bst_str = bst.in_order();
        if(bst_str != ""){
            cout << "Incorrect in_order result after testing on empty tree. Expected  but got : " << bst_str << endl;
        }
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.in_order();
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
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10, 5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 but got : " << bst_str << endl;
        }
    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }



    try {
        BST<string, string> bst;
        string bst_str = bst.in_order();
        if(bst_str != ""){
            cout << "Incorrect in_order result after testing on empty tree. Expected  but got : " << bst_str << endl;
        }
        string vals[5] = {"hello", "world", "I am hungry", "the window is open", "it is not raining"};
        for(int i = 1; i <= 5; i++) {
            bst.insert("some data", vals[i]);
        }
        bst_str = bst.in_order();

        if(bst_str != "I am hungry hello it is not raining the window is open world") {
            cout << "Incorrect in_order result after inserting strings. Expected I am hungry hello it is not raining the window is open world but got : " << bst_str << endl;
        }
        for(int i = 5; i >= 1; i--) {
            bst.insert("some data", vals[i]);
        }
        bst_str = bst.in_order();
        if(bst_str != "hello world I am hungry the window is open it is not raining it is not raining the window is open I am hungry world hello") {
            cout << "Incorrect in_order result after inserting keys more strings. Expected really long string but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }


    try {
        BST<string, float> bst;
        string bst_str = bst.in_order();
        if(bst_str != ""){
            cout << "Incorrect in_order result after testing on empty tree. Expected  but got : " << bst_str << endl;
        }
        float vals[5] = {0.1, 0.2, 0.3, 0.4, 0.5};
        for(int i = 0; i < 5; i++) {
            bst.insert("some data", vals[i]);
        }
        bst_str = bst.in_order();
        if(bst_str != "0.1 0.2 0.3 0.4 0.5") {
            cout << "Incorrect in_order result after inserting strings. Expected 0.1 0.2 0.3 0.4 0.5 but got : " << bst_str << endl;
        }
        for(int i = 0; i < 5; i++) {
            bst.insert("some data", vals[i]);
        }
        bst_str = bst.in_order();
        if(bst_str != "0.1 0.1 0.2 0.2 0.3 0.3 0.4 0.4 0.5 0.5") {
            cout << "Incorrect in_order result after inserting strings. Expected 0.1 0.1 0.2 0.2 0.3 0.3 0.4 0.4 0.5 0.5 but got : " << bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }


    try {
        BST<string, int> bst;
        string bst_str = bst.in_order();
        if(bst_str != ""){
            cout << "Incorrect in_order result after testing on empty tree. Expected  but got : " << bst_str << endl;
        }
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting strings. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        for(int i = 1; i <= 3; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.in_order();
        if(bst_str != "1 1 2 2 3 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting strings. Expected 1 1 2 2 3 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        for(int i = 10; i >= 4; i--) {
            bst.insert("some data", i);
        }
        bst_str = bst.in_order();
        if(bst_str != "1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10") {
            cout << "Incorrect in_order result after inserting strings. Expected 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 but got : " << bst_str << endl;
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
// 5. Different data types and data/key values
//   a. int key
//   b. float key
//   c. string key
//   d. negative key (This is really important to think about)
void test_trim() {
    try {
        BST<int, int> int_tree;
        int_tree.trim(-1,1);
        if(int_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=-1, high=1. Expected  but got : " << int_tree.to_string() << endl;
        }

        int vals1[9] = {3, 0, 4, 2, 1, 5, 8, 7, 9};
        for(int i = 0; i < 9; i++){
            int_tree.insert(vals1[i], vals1[i]);
        }
        int_tree.trim(50, 80);
        if(int_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=50, high=80. Expected  but got : " << int_tree.to_string() << endl;
        }
        for(int i = 0; i < 9; i++){
            int_tree.insert(vals1[i], vals1[i]);
        }
        int_tree.trim(1, 5);
        if(int_tree.to_string() != "3 4"){
            cout << "Incorrect tree after trimming  with low=1, high=5. Expected 3 4 5 but got : " << int_tree.to_string() << endl;
        }
        int_tree.trim(0, 0);
        if(int_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << int_tree.to_string() << endl;
        }
        int_tree.insert(0, 0);
        int_tree.trim(0, 0);
        if(int_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << int_tree.to_string() << endl;
        }

        //====================//====================//====================//====================//====================

        BST<float, float> float_tree;
        float_tree.trim(-1.3,1.7);
        if(float_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=-1.3, high=1.7. Expected  but got : " << float_tree.to_string() << endl;
        }

        float vals2[9] = {3.5, 0, 4.1, 2.2, 1.3, 5.4, 8.9, 7.8, 9.7};
        for(int i = 0; i < 9; i++){
            float_tree.insert(vals2[i], vals2[i]);
        }
        float_tree.trim(50.5, 80.5);
        if(float_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=50, high=80. Expected  but got : " << float_tree.to_string() << endl;
        }
        for(int i = 0; i < 9; i++){
            float_tree.insert(vals2[i], vals2[i]);
        }
        float_tree.trim(1.2, 5.5);
        if(float_tree.to_string() != "3.5 4.1"){
            cout << "Incorrect tree after trimming  with low=1, high=5. Expected 3.5 4.1 but got : " << float_tree.to_string() << endl;
        }
        float_tree.trim(0, 0);
        if(float_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << float_tree.to_string() << endl;
        }
        float_tree.insert(0, 0);
        float_tree.trim(0, 0);
        if(float_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << float_tree.to_string() << endl;
        }

        //====================//====================//====================//====================//====================

        BST<string, string> string_tree;
        string_tree.trim("a", "b");
        if(string_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=-1.3, high=1.7. Expected  but got : " << string_tree.to_string() << endl;
        }

        string vals3[9] = {"hello", "there", "my name is", "bob", "it is rainy today", "the rain is sad", "but soon it will be sunny", "and then", "the sun is happy"};
        for(int i = 0; i < 9; i++){
            string_tree.insert(vals3[i], vals3[i]);
        }
        string_tree.trim("pillow", "zillow");
        if(string_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=pillow, high=zillow. Expected  but got : " << string_tree.to_string() << endl;
        }
        for(int i = 0; i < 9; i++){
            string_tree.insert(vals3[i], vals3[i]);
        }
        //a b c d e f g h i j k l m n o p q r s t u v w x y z
        string_tree.trim("bonjour", "loon");
        if(string_tree.to_string() != "hello there"){
            cout << "Incorrect tree after trimming  with low=1, high=5. Expected hello there but got : " << string_tree.to_string() << endl;
        }
        string_tree.trim("", "");
        if(string_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << string_tree.to_string() << endl;
        }
        string_tree.insert("", "");
        string_tree.trim("", "");
        if(string_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=0, high=0. Expected  but got : " << string_tree.to_string() << endl;
        }

        //====================//====================//====================//====================//====================

        BST<char, char> char_tree;
        char_tree.trim('a', 'b');
        if(char_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=a, high=b. Expected  but got : " << char_tree.to_string() << endl;
        }

        char vals4[5] = {'c', 'b', 'a', 'd', 'e'};
        for(int i = 0; i < 5; i++){
            char_tree.insert(vals4[i], vals4[i]);
        }
        char_tree.trim('a', 'e');
        if(char_tree.to_string() != "c b d"){
            cout << "Incorrect tree after trimming  with low=pillow, high=zillow. Expected c b d but got : " << char_tree.to_string() << endl;
        }
        for(int i = 0; i < 5; i++){
            char_tree.insert(vals4[i], vals4[i]);
        }
        char_tree.trim('-', '!');
        if(char_tree.to_string() != ""){
            cout << "Incorrect tree after trimming  with low=, high=. Expected  but got : " << char_tree.to_string() << endl;
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
