#include "bst.h"

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
 * Delete Node function
 *
 *
 *
 *
 */
 template <typename Data, typename Key>
 void Node<Data, Key>::deleteNode(Node<Data, Key>* node){ //Havent tested since we have no insert func
    // If root isn't empty
    if(!node = nullptr){
        // Recursively go into the children of the parent node
        deleteNode(node->left);
        deleteNode(node->right);

        // Delete them
        delete;
    }
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
    deleteNode(root);
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
        root = Node(data, key);
    }else{
        while()
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
    
}

/**
 * trim function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
void BST<Data, Key>::trim(Key key1, Key key2) {
    
}

/**
 * to_string function
 *
 *
 *
 *
 */
template <typename Data, typename Key>
string BST<Data, Key>::to_string() const {
    
}
