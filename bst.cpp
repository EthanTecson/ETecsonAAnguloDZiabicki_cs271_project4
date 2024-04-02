#include "bst.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

//===================================
// Node Class
//===================================

/**
 * @brief Empty Constructor for Node Class
 *
 * Creates a Node Object with no values for key or data
 *
 * @param none
 *
 * @note Pre-Condition: none
 * @note Post-Condition: Creates a Node object
 *
 * @returns none
 */
template <typename Data, typename Key>
Node<Data,Key>::Node(){
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

/**
 * @brief Constructor with values for Node Class
 *
 * Creates a Node Object with the data and key attributes equal 
 * to the data and key given in the argument
 *
 * @param d - data for node to be initiated with
 * @param k - key for node to be initiated with
 *
 * @note Pre-Condition: none
 * @note Post-Condition: Creates a Node object 
 *
 * @returns none
 */
template <typename Data, typename Key>
Node<Data,Key>::Node(Data d, Key k){

    data = d;
    key = k;

    left = nullptr;
    right = nullptr;
    parent = nullptr;
}


/**
 * @brief Deconstructor for Node Class
 *
 * Deallocates memory created for node objects
 *
 *@param none
 * 
 * @note Pre-Condition: none
 * @note Post-Condition:a All node objects deallocated
 *
 * @returns none
 */
template <typename Data, typename Key>
Node<Data, Key>::~Node() {
    // Nothing needed
}


/**
 * @brief Helper function for deleting Node objects
 *
 * Deallocates memory created for node objects in BST class
 *
 *@param node - node to be deleted
 * 
 * @note Pre-Condition: There exist a node object to be deleted
 * @note Post-Condition:a All node objects deallocated
 *
 * @returns none
 */
 template <typename Data, typename Key>
 void Node<Data, Key>::deleteNode(Node<Data, Key>* node){ //Havent tested since we have no insert func
    // If root isn't empty
    if(node != nullptr){
        // Recursively go into the children of the parent node
        deleteNode(node->left);
        deleteNode(node->right);

        // Delete them
        delete node;
    }
 }

//===================================
// BST Class
//===================================
/**
 * @brief  Constructor for BST Class
 *
 * Initiates a BST class object
 * 
 * @param - none
 * 
 * @note Pre-Condition: none
 * @note Post-Condition: BST object initiated
 *
 * @returns none
 */
template <typename Data, typename Key>
BST<Data, Key>::BST() {
    root = nullptr;
}



/**
 * @brief  Deconstructor for BST Class
 *
 * Deallocates memory for all nodes within BST
 * 
 * @param - none
 * 
 * @note Pre-Condition: There exist a BST to be deallocated
 * @note Post-Condition: All nodes within BST are deallocated
 *
 * @returns none
 */
template <typename Data, typename Key>
BST<Data, Key>::~BST() {
    if (root != nullptr) {
        root->deleteNode(root);
    }
}


/**
 * @brief  insert for BST Class
 *
 * Inserts a node into BST with specificed data and key
 * 
 * @param data - data of node that will be inserted
 * @param key - key of node that will be inserted
 * 
 * @note Pre-Condition: There exist a BST for node to be inserted
 * @note Post-Condition: BST has the inserted node
 *
 * @returns none
 */
template <typename Data, typename Key>
void BST<Data, Key>::insert(Data data, Key key) {
    // If tree is empty
    if(root == nullptr){
        root = new Node<Data, Key>(data, key);
    }else{
        // Find correct place for new node to be inserted
        Node<Data, Key> *temp = root;
        Node<Data, Key> *parent = nullptr;
        while(temp != nullptr){
            parent = temp;
            if(key < temp->key){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        // Correctly set parent of new node
        if(key < parent->key){
            parent->left = new Node<Data, Key>(data, key);
        }else{
            parent->right = new Node<Data, Key>(data, key);
        }
    }
}



/**
 * @brief get for BST Class
 *
 * gets data associated with given key
 * 
 * @param key - key of the node whose data will be returned
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns data corresponding to given key
 */
template <typename Data, typename Key>
Data BST<Data, Key>::get(Key key) const {
    Node<Data, Key> *temp = root;
    // Correctly search for key
    while(temp != nullptr && temp->key != key){
        if(key < temp->key){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    // If key is not in tree
    if(temp == nullptr){
        return Data();
    }else{
        return temp->data;
    }
}

/**
 * @brief remove_helper function for BST Class
 *
 * Helps remove function for BST class
 * 
 * @param root - root of BST
 * @param key - key of node to be removed
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: A BST without the node of the corresponding key, if no node with corresponding key was found, then none.
 *
 * @returns data corresponding to given key
 */
template <typename Data, typename Key>
Node<Data, Key>* BST<Data, Key>::remove_helper(Node<Data, Key>* root, Key key) {
    
    // if BST is empty
    if (root == nullptr) {
        return root;
    }

    // Searching for the key in the BST
    if (key < root->key) {
        root->left = remove_helper(root->left, key);
    } 
    else if (key > root->key) {
        root->right = remove_helper(root->right, key);
    } 
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node<Data, Key>* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == nullptr) {
            Node<Data, Key>* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: get the successor (smallest in the right subtree)
        Key successorKey = successor(root->key);

        // getting the node of the successor
        Node<Data, Key>* temp = search(root, successorKey);

        // copy the successor to this node
        root->key = temp->key;
        root->data = temp->data;

        // delete the successor
        root->right = remove_helper(root->right, temp->key);
    }
    return root;
}

/**
 * @brief remove function for BST Class
 *
 * Removes node within BST
 * 
 * @param key - key of node to be removed
 *
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: A BST without the node of the corresponding key, if no node with corresponding key was found, then none.
 *
 * @returns none
 */
template <typename Data, typename Key>
void BST<Data, Key>::remove(Key key) {
    root = remove_helper(root, key);
}

/**
 * @brief max_data function for BST Class
 *
 * returns data associated with the max key in the BST
 * 
 * @param none
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns data associated with the max key in the BST by using search() function to get node with max key
 */
template <typename Data, typename Key> 
Data BST<Data, Key>::max_data() const {
    return search(root, max_key())->data;
}

/**
 * @brief max_key function for BST Class
 *
 * returns the max key within the BST
 * 
 * @param none
 *
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns max key within the BST
 */
template <typename Data, typename Key>
Key BST<Data, Key>::max_key() const {
    Node<Data, Key> *temp = root;
    // Find right most node
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp->key;
}

/**
 * @brief min_data function for BST Class
 *
 * returns data associated with the min key in the BST
 * 
 * @param none
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns data associated with the min key in the BST by using search() function to get node with min key
 */
template <typename Data, typename Key> 
Data BST<Data, Key>::min_data() const {
    return search(root, min_key())->data;
}

/**
 * @brief min_key function for BST Class
 *
 * returns the min key within the BST
 * 
 * @param none
 *
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns min key within the BST
 */
template <typename Data, typename Key>
Key BST<Data, Key>::min_key() const {
    Node<Data, Key> *temp = root;
    // Find left most node
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp->key;
}

/**
 * @brief successor function for BST Class
 *
 * returns the successor key in the BST tree for the given key k
 * 
 * @param key - key of whose successor we are trying to find
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns successor of given key k
 */
template <typename Data, typename Key>
Key BST<Data, Key>::successor(Key key) const {
    Node<Data, Key>* node = search(root, key); //find the relevant node in the tree
    if(node == nullptr || node->key == max_key()){ //if there is no successor, return default key
        return Key();
    }
    else if(node->right != NULL) { //if there is a right child, the successor is the min key in the right subtree
        node = node->right;
        while(node->left != nullptr){
            node = node->left;
        }
        return node->key;
    }else{ //if there's no right child, it must be an ancestor. Iterate up the tree until the node is found.
        Node<Data, Key>* parent = node->parent;
        while (parent != NULL && node == parent->right) {
            node = parent;
            parent = parent->parent;
        }
        // Successor is root
        if(parent == nullptr){
            return root->key;
        // Successor was found as a left-child
        }else{
            return parent->key;
        }
    }
}


/**
 * @brief in_order function for BST Class
 *
 * returns string of keys within BST in ascneidng order
 * 
 * @param key - none
 * 
 * @note Pre-Condition: There exist a BST 
 * @note Post-Condition: none
 *
 * @returns string of keys within BST in ascneding order
 */
template <typename Data, typename Key>
string BST<Data, Key>::in_order() const {
    string str = in_order_tree_walk(root);
    return str.substr(0, str.size()-1);
}

/**
 * @brief Helper function for in_order function for BST class
 *
 * Returns a string of keys in ascending order within the BST
 * 
 * @param none
 *
 * @note Pre-Condition: There exists a BST to be walked.
 * @note Post-Condition: none
 * 
 * @returns - string of keys in ascending order within the BST
 */
template <typename Data, typename Key>
string BST<Data, Key>::in_order_tree_walk(Node<Data, Key> *x) const {
    stringstream ss;
    if (x != nullptr) {
        ss << in_order_tree_walk(x->left);
        ss << x->key << " ";
        ss << in_order_tree_walk(x->right);
    }
    return ss.str();
}

/**
 * @brief trim_helper function for BST Class
 *
 * Creates subtree whose keys are within the range of low and high
 * 
 * @param node - node to be checked if within range
 * @param low - minimum value range for new subtree
 * @param high - maximum value range for new subtree
 *
 * @note Pre-Condition: There exists a BST that has a range of keys.
 * @note Post-Condition: The same BST whose keys are within the range of low and high.
 *
 * @returns Pointer to the root of the trimmed subtree, which contains only nodes whose keys are within the specified range.
 */
template <typename Data, typename Key>
Node<Data, Key>* BST<Data, Key>::trim_helper(Node<Data, Key>* node, Key low, Key high) {
    if (node == nullptr) {
        return nullptr;
    }

    // trim the left and right subtrees
    node->left = trim_helper(node->left, low, high);
    node->right = trim_helper(node->right, low, high);

    // Checking to see if its in range of our bounds
    if (node->key < low) {
        // Node's key is too low, replace it with its right subtree because its within our bounds
        Node<Data, Key>* rightSubtree = node->right;

        // deleting the node since its not in our bounds
        delete node;

        // returning the rest of the right subtree to repeat the proces
        return rightSubtree;

    // Checking to see now if our key is greater than our bounds
    } else if (node->key > high) {
        // Node's key is too high, replace it with its left subtree because the left is always the smallest than our bounds
        Node<Data, Key>* leftSubtree = node->left;

        // Deleting node because its greater than our bounds
        delete node;

        // returning the rest of the left subtree to repeat the process
        return leftSubtree;
    } else {
        // Node's key is in range, keep the node
        return node;
    }
}

/**
 * @brief trim function for BST Class
 *
 * Trims the BST to contain only nodes with keys within the specified range
 * 
 * @param low - The minimum value range for the trimmed BST
 * @param high - The maximum value range for the trimmed BST
 *
 * @note Pre-Condition: There exists a BST that has a range of keys.
 * @note Post-Condition: The BST contains only nodes whose keys are within the range [low, high].
 * 
 * @returns none
 */
template <typename Data, typename Key>
void BST<Data, Key>::trim(Key low, Key high) {
    root = trim_helper(root, low, high);
}


/**
 * @brief to_string() function for BST class
 *
 * Returns a string of keys within the BST starting at the root
 * 
 * @param none
 *
 * @note Pre-Condition: There exists a BST
 * @note Post-Condition: none
 * 
 * @returns string of keys within the BST starting at the root using the insertion_order_tree_walk helper function
 */
template <typename Data, typename Key>
string BST<Data, Key>::to_string() const {
    return insertion_order_tree_walk(root);
}

/**
 * @brief empty function for BST class
 *
 * Returns true or false based on whether the given BST is empty or not
 * 
 * @param none
 *
 * @note Pre-Condition: There exists a BST 
 * @note Post-Condition: none
 * 
 * @returns true or false
 */
template <typename Data, typename Key>
bool BST<Data, Key>::empty() const{
    if(root == nullptr){
        return true;
    }
    return false;
}

/**
 * operator= function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
Node<Data, Key>& Node<Data, Key>::operator=(const Node<Data, Key>& Node2) {
    if (this != &Node2) {
        data = Node2->data;
        key = Node2->key;

        // Assuming that left and right are pointers to dynamically allocated memory
        delete left;
        delete right;
        left = Node2 -> left ? new Node<Data, Key>(*Node2->left) : nullptr;
        right = Node2 -> right ? new Node<Data, Key>(*Node2->right) : nullptr;
    }
    return *this;
}

/**
 * @brief helper function for to_string function for BST class
 *
 * Returns a string of keys within the BST starting at the root
 * 
 * @param root - root of BST tree to be walked
 *
 * @note Pre-Condition: The root parameter points to the root of a valid BST. The BST may be empty.
 * @note Post-Condition: none
 * 
 * @returns string of keys within the BST starting at the root using the insertion_order_tree_walk helper function
 */
template <typename Data, typename Key>
string BST<Data, Key>::insertion_order_tree_walk(Node<Data, Key> *root) const {
    stringstream ss;

    // If the root is empty return nothing
    if(root == nullptr){
        return "";
    }

    // Creating a Queue
    queue<Node<Data, Key>*> q;
    q.push(root);


    while(!q.empty()){

        // Getting the node in the front of the queue
        Node<Data, Key>* x = q.front();

        // Then we remove it
        q.pop();

        // Add it to the ss
        ss << x->key << " ";

        // Repeate the proccess from left -> right depending if there empty or not
        if(x->left != nullptr){
            q.push(x->left);
        }
        if(x->right != nullptr){
            q.push(x->right);
        }
    }

    string result = ss.str();

    // Removing the end of the string which would be an extra " "
    result.pop_back(); 
    return result;
}

/**
 * @brief Helper search function for many functions for BST class
 *
 * This function searches for a node with the specified key in the BST starting from the given root node.
 * 
 * @param root - The root of the subtree to search
 * @param key - The key to search for in the BST
 *
 * @note Pre-Condition: The root parameter points to the root of a valid subtree in the BST. The BST may be empty.
 * @note Post-Condition: If a node with the specified key is found, a pointer to that node is returned. 
 *                      If the key is not found in the subtree, nullptr is returned.
 * 
 * @returns A pointer to the node with the specified key if found; otherwise, nullptr.
 */
template <typename Data, typename Key>
Node<Data, Key>* BST<Data, Key>::search(Node<Data, Key>* root, Key key) const {

    // If the tree is empty or the key is at the root, return the root
    if (root == nullptr || root->key == key) {
        return root;
    }

    // If the key is greater than the root's key, search the right subtree
    if (root->key < key) {
        return search(root->right, key);
    }

    // If the key is less than the root's key, search the left subtree
    return search(root->left, key);
}

Node<Data, Key>* searchData(Node<Data, Key>* root, Data data) const {
    if(root == nullptr || root->data == data) {
        return data;
    }
    else {
        Node<Data, Key>* leftSearch = searchData(root->left, data);
        Node<Data, Key>* rightSearch = searchData(root->right, data);
        if(leftSearch != nullptr) {
            return leftSearch;
        }
        else {
            return rightSearch;
        }
    }
}
