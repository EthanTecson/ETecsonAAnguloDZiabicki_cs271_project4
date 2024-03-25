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
        void deleteNode(Node<Data, Key>* node); //Helper function for deconstructor
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
        void trim(Key key, Key key);
        string to_string() const;
};
#endif // BST_H