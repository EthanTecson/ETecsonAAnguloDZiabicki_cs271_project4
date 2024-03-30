#include "bst.h"
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

//===================================
// Node Class
//===================================
template <typename Data, typename Key>
Node<Data,Key>::Node(){
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}


template <typename Data, typename Key>
Node<Data,Key>::Node(Data d, Key k){

    data = d;
    key = k;

    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

template <typename Data, typename Key>
Node<Data, Key>::~Node() {
    // Destructor implementation goes here
    // For example, you can delete any dynamically allocated memory
    // or perform any necessary cleanup.
}


/**
 * Delete Node function
 *
 *
 *
 *
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
 * BST constructor
 *
 *
 *
 *
 */
template <typename Data, typename Key>
BST<Data, Key>::BST() {
    root = nullptr;
}



/**
 * BST deconstructor
 *
 *
 *
 *
 */
template <typename Data, typename Key>
BST<Data, Key>::~BST() {
    if (root != nullptr) {
        root->deleteNode(root);
    }
}


/**
 * insert function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
void BST<Data, Key>::insert(Data data, Key key) {
    if(root == nullptr){
        root = new Node<Data, Key>(data, key);
    }else{
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
        if(key < parent->key){
            parent->left = new Node<Data, Key>(data, key);
        }else{
            parent->right = new Node<Data, Key>(data, key);
        }
    }
}



/**
 * get function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
Data BST<Data, Key>::get(Key key) const {
    Node<Data, Key> *temp = root;
    while(temp != nullptr && temp->key != key){
        if(key < temp){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return temp->data;
}

/**
 * remove function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
void BST<Data, Key>::remove(Key key) {

}

/**
 * max_data function
 *
 *
 *
 *
 */
template <typename Data, typename Key> 
Data BST<Data, Key>::max_data() const {
    return max_key()->data;
}
/**
 * max_key function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
Key BST<Data, Key>::max_key() const {
    Node<Data, Key> *temp = root;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    return temp->key;
}

/**
 * min_data function
 *
 *
 *
 *
 */
template <typename Data, typename Key> 
Data BST<Data, Key>::min_data() const {
    return min_key() -> data;
}

/**
 * min_key function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
Key BST<Data, Key>::min_key() const {
    Node<Data, Key> *temp = root;
    while(temp->left != nullptr){
        temp = temp->left;
    }
    return temp->key;
}

/**
 * successor function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
Key BST<Data, Key>::successor(Key key) const {
    //find the node with the given key
    Node<Data, Key> *temp = root;
    while(temp != nullptr && temp->key != key){
        if(temp->key < key){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    //if there is no node with that key, return default key
    if(temp == nullptr){
        return Key();
    }else{
        //if there is a right child, find the min key in that right subtree
        if(temp->right != nullptr){
            temp = temp->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            return temp->key;
        //otherwise, 
        }else{
            Node<Data, Key> parent = temp->parent;
            while(parent != nullptr && temp == parent->right){
                temp = parent;
                parent = temp->parent;
            }
            return parent->key;
        }
    }
}

/**
 * in_order function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
string BST<Data, Key>::in_order() const {
    return in_order_tree_walk(root);
}

/**
 * trim function
 *
 *
 *
 *
 */
// template <typename Data, typename Key>
// void BST<Data, Key>::trim(Key key1, Key key2) {
    
// }

/**
 * to_string function
 *
 *
 *
 *
 */

template <typename Data, typename Key>
string BST<Data, Key>::to_string() const {
    return insertion_order_tree_walk(root);
}

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
 * empty function
 *
 *
 *
 *
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
 * to_string function
 *
 *
 *
 *
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
