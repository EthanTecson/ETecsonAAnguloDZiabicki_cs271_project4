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

template <typename Data, typename Key> //Forward Declaration so we can include it in Node Class as a friend <3
class BST;

template <typename Data, typename Key>
class Node {
    private:
        Data data;
        Key key;
        Node<Data, Key>* left;
        Node<Data, Key>* right;
        Node<Data, Key>* parent;
        Node(Data d, Key k) : data(d), key(k), left(nullptr), right(nullptr), parent(nullptr) {} //Create a new Node with the parent and 2 children
        void deleteNode(Node<Data, Key>* node);
        friend class BST<Data, Key>; //They now have become best buds
};

template <typename Data, typename Key>
class BST {
private:
    Node<Data, Key>* root;

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
};


#endif // BST_H
