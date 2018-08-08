/*
 Date Created:           November 15th, 2017
 
 Last Date Modified:     November 21th, 2017
 
 Programmer:             Alexander Kayuda
 
 Purpose:                This file is a part of the project for my Data Structures Honors class.
 
 Description:            This class inherits all basic function from Binary Tree class and implements additional 3 functions (Search, Insert, and Delete)
 */

#include "BinaryTree.cpp"

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

template <class T>
class BinarySearchTree : public BinaryTree<T>{
    
public:
    void insertItem(T);
    void deleteItem(T);
    bool searchItem(T);
    
private:
    bool searchItem(BinaryTreeNode<T> *, T);
    void insertItem(BinaryTreeNode<T> *&, T);
    void deleteItem(BinaryTreeNode<T> *&, T);
    int deletemin(BinaryTreeNode<T> *&);
    
    T getNodeInfo(BinaryTreeNode<T> *);
    int getNodeOccurances(BinaryTreeNode<T> *);
};
#endif
