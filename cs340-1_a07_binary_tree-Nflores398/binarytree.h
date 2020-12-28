/* 
Noah Flores  
z1861588 
CSCI 340-1 

I certify that this is my own work and where appropriate an extension  
of the starter code provided for the assignment. 
*/
/***************************************************************
This Programs creates two binary trees that prints out them inorder
THe code will randomly generate the numbers to fill the tree and
will randomly select the side to store the numbers in the tree.
***************************************************************/

#ifndef H_BINARYTREE
#define H_BINARYTREE
#include <iostream>
#include "node.h"
using namespace std;

template <typename T>
class BinaryTree
{
    typedef enum
    {
        left_side,
        right_side
    } SIDE;

    SIDE rnd()
    {
        return rand() % 2 ? right_side : left_side;
    } // End of rnd()

public:
    BinaryTree()
    {
        root = nullptr;
    }; // default constructor
    unsigned getSize()
    {
        return _getSize(root);
    }; // returns size of tree
    unsigned getHeight()
    {
        return _getHeight(root);
    }; // returns height of tree
    virtual void Insert(const T &x)
    {
        _Insert(root, x);
    }; // inserts node in tree
    void Inorder(void (*x)(const T &))
    {
        _Inorder(root, x);

    }; // inorder traversal of tree
protected:
    Node<T> *root; // root of tree

private:
/***************************************************************
Function: _getSize

Use: Get the amount of nodes that are stored in the tree.

Parameter: Node<T>

returns: unsigned
***************************************************************/
    unsigned _getSize(Node<T> *x) const
    { //Escapes if no more nodes
        if (x == nullptr)
        {
            return 0;
        }
        else
        {
            return (_getSize(x->left) + 1 + _getSize(x->right));
        }
    }; // private version of getSize()

/***************************************************************
Function: _getHeight

Use: Gets the height of the tree by checking the left and right
side of the tree.

Parameter: Node<T>

returns: unsigned
***************************************************************/
    unsigned _getHeight(Node<T> *x) const
    { //escapes if no more nodes
        if (x == nullptr)
        {
            return 0;
        }
        size_t leftHeight = _getHeight(x->left);
        size_t rightHeight = _getHeight(x->right);

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
    // private version of getHeight()

/***************************************************************
Function: _Insert

Use: Inserts numbers into tree and picks a random side to store
the number on.

Parameter: Node<T> and const T

returns: nothing
***************************************************************/
    void _Insert(Node<T> *&tree, const T &x)
    {
        //creates root if no root
        if (!tree)
        {
            tree = new Node<T>(x);
            return;
        }
        //If rnd = left side
        if (rnd() == left_side)
        {
            _Insert(tree->left, x);
        }
        //Else store in right side.
        else
        {
            _Insert(tree->right, x);
        }

    } // private version of Insert()

/***************************************************************
Function: _Inorder

Use: Prints the nodes of the tree Inorder and calls the print function
to print each node. Repeats till all elements are prinited.

Parameter: Node<T> and void print

returns: nothing
***************************************************************/
    void _Inorder(Node<T> *tree, void (*x)(const T &))
    {
        if (tree)
        {
            _Inorder(tree->left, x);
            //Prints the current node
            x(tree->data);
            _Inorder(tree->right, x);
        }

    } // private version of Inorder()
};

#endif // End of H_BINARYTREE
