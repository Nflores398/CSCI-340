/* 
Noah Flores  
z1861588 
CSCI 340-1 

I certify that this is my own work and where appropriate an extension  
of the starter code provided for the assignment. 
*/
/***************************************************************
This program inserts a vector into a tree and then finds and
deletes all the leafs untill the tree is empty. The program
also prints out inorder and keeps take of the size of the tree.
***************************************************************/

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include "binarytree.h"

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    BinarySearchTree()
    {
        this->root = nullptr;
    }; // default constructor
    void Insert(const T &x)
    {
        _Insert(this->root, x);
    }; // inserts node in tree
    bool Search(const T &x) const
    {
        return _Search(this->root, x);
    } // searches leaf with value x
    bool Remove(const T &x);
    // removes leaf with value x

private:
    bool _Search(Node<T> *tree, const T &x) const;
    void _Remove(Node<T> *&tree, const T &x);
    bool _Leaf(Node<T> *tree) const;
    void _Insert(Node<T> *&tree, const T &x);
};
/***************************************************************
Function: Remove

Use: Calls a search of X in the tree and if true it calls
_Remove to delete it, If not found in search it returns

Parameter: const T

returns: bool
***************************************************************/
template <typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    //checks if the element is in the tree
    if (Search(x) == true)
    {
        //If found and is a leaf it is removed
        _Remove(this->root, x);
        return true;
    }
    else
    {
        return false;
    }
} // removes leaf with value x
/***************************************************************
Function: _Search

Use: Uses to check if the x is in the tree. If found the prgram
will check if the value is a leaf in the tree.

Parameter: Node<T> and const T

returns: bool
***************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Search(Node<T> *tree, const T &x) const
{
    //Checks if value is null
    if (tree == NULL)
    {
        return false;
    }
    //If the x is found in the tree
    if (tree->data == x)
    {
        //It checks if the node is a leaf
        //if so it is returned as true
        return _Leaf(tree);
    }
    else if (x < tree->data)
    {
        return _Search(tree->left, x);
    }
    else
    {
        return _Search(tree->right, x);
    }
} // private version of search
  /***************************************************************
Function: _Remove

Use: Deletes Leafs of the tree after they were found in the tree

Parameter: Node<T> and const T

returns: nothing
***************************************************************/
template <typename T>
void BinarySearchTree<T>::_Remove(Node<T> *&tree, const T &x)
{
    //Checks if value is NULL
    if (tree == NULL)
    {
        return;
    }
    //If value is found its deleted from the tree
    if (tree->data == x)
    {
        delete tree;
        tree = nullptr;
    }
    else if (x < tree->data)
    {
        _Remove(tree->left, x);
    }
    //Else store in right side.
    else
    {
        _Remove(tree->right, x);
    }
} // private version of remove
  /***************************************************************
Function: _Leaf

Use: Checks if current node is a leaf. If so returns true.
Otherwise false.

Parameter: Node<T>

returns: bool
***************************************************************/
template <typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *tree) const
{
    //Checks if value is NULL
    if (tree == NULL)
    {
        return false;
    }
    //Returns if true if node is a leaf and has no child
    if (tree->left == nullptr && tree->right == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }

} // checks if node is leaf

/***************************************************************
Function: _Insert

Use: Inserts elements into the tree.

Parameter: Node<T> and const T

returns: nothing
***************************************************************/
template <typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&tree, const T &x)
{
    //creates root if no root
    if (!tree)
    {
        tree = new Node<T>(x);
        return;
    }
    //Prevents doubles from being stored into the tree.
    if (tree->data == x)
    {
        return;
    }
    if (x < tree->data)
    {
        _Insert(tree->left, x);
    }
    else
    {
        _Insert(tree->right, x);
    }

} // private version of Insert()

#endif // End of BINARYSEARCHTREE_H_
