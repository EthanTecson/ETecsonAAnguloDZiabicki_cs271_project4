//-----------------------------------------------//
//              Binary Search Tree               //
//               Constructor File                //
//                                               //
// Ethan Tecson, Andrew Angulo, Daniel Ziabicki  //
//-----------------------------------------------//

#ifndef BST_H
#define BST_H
using namespace std;
#include <iostream>


template <typename Data, typename Key>
class Node {
    private:
        Data data;
        Key key;
        Node<Data, Key>* left;
        Node<Data, Key>* right;
        int key;
        friend class BST<Data, Key>; // Allows BST to access these contents

};

template <typename Data, typename Key>
class BST
{
    private:
        Node<Data, Key>* root;

    public:
        BST();
        ~BST();
        void insert(Data data, Key key);
        Data get(Key key);
        void remove(Key key);
        Data max_data();
        Key max_key();
        Data min_data();
        Key min_key();
        Key successor(Key key);
        void in_order();
        void trim(Key key, Key key);
        void to_string();
};
#endif // BST_H