/*
 Date Created:           November 15th, 2017
 
 Last Date Modified:     November 17th, 2017
 
 Programmer:             Alexander Kayuda
 
 Purpose:                This file is a part of the project for my Data Structures Honors class.
                         This class can be the base class for any advanced stree structures such as Binary Search Trees/AVL Trees and many others.
 
 Description:            This class has basic functions that can be used by any other advanced tree stuctures.
 */

#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef BinaryTree_h
#define BinaryTree_h

template <class T>
struct BinaryTreeNode{
    T info;
    int occurances;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};

template <class T>
class  BinaryTree{
    private:
        void copyTree(BinaryTreeNode<T> *, BinaryTreeNode<T> *&);
        void destroyTree(BinaryTreeNode<T> *&);
    
        int nodeCount(BinaryTreeNode<T> *);
        int height(BinaryTreeNode<T> *);
        int leavesCount(BinaryTreeNode<T> *);
    
        void preorder(BinaryTreeNode<T> *);
        void inorder(BinaryTreeNode<T> *);
        void postorder(BinaryTreeNode<T> *);
    
    protected:
        BinaryTreeNode<T> *root;
    
    public:
        BinaryTree();
        BinaryTree(const BinaryTree&);
        BinaryTree& operator= (const BinaryTree&);
        ~BinaryTree();
        void destroyTree();
        BinaryTreeNode<T>* getRoot() const;
    
        int nodeCount();
        int leavesCount();
        int heightOfTree();
        int max(int,int);
    
        bool isEmpty();
    
        void print(T);
        void preorderTraversal();
        void inorderTraversal();
        void postorderTraversal();
};
#endif
