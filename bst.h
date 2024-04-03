//-----------------------------------------------//
//              Binary Search Tree               //
//               Constructor File                //
//                                               //
// Ethan Tecson, Andrew Angulo, Daniel Ziabicki  //
//-----------------------------------------------//


#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <typename Data, typename Key>
class BST;


template <typename Data, typename Key>
class Node {
    private:
        Data data;
        Key key;
        Node<Data, Key>* left;
        Node<Data, Key>* right;
        Node<Data, Key>* parent;
        friend class BST<Data, Key>; // Allows BST to access these contents
    public:
        Node();
        Node(Data d, Key k);
        ~Node();
        void deleteNode(Node<Data, Key>* node); //Helper function for deconstructor
        Node<Data, Key>& operator=(const Node<Data, Key>& Node2);
        Key getKey() const;
        Data getData() const;
};

template <typename Data, typename Key>
class BST
{
    private:
        Node<Data, Key>* root;
        Node<Data, Key>* remove_helper(Node<Data, Key>* root, Key key);
    public:
        BST();
        ~BST();
        bool empty() const;
        void insert(Data data, Key key);
        Data get(Key key) const;
        void remove(Key key);
        Data max_data() const;
        Key max_key() const;
        Data min_data() const;
        Key min_key() const;
        Key successor(Key key) const;
        string in_order() const;
        void trim(Key key1, Key key2); 
        string to_string() const;
        string in_order_tree_walk(Node<Data, Key> *x) const;
        string insertion_order_tree_walk(Node<Data, Key> *x) const;
        Node<Data, Key>* search(Node<Data, Key>* root, Key key) const;
        Node<Data, Key>* trim_helper(Node<Data, Key>* node, Key low, Key high);
        Node<Data, Key>* getRoot();
};
#endif // BST_H