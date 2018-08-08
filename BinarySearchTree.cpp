#include "BinarySearchTree.h"

template<class T>
bool BinarySearchTree<T>:: searchItem(T item){
    return searchItem(this->root,item);
}

template<class T>
bool BinarySearchTree<T>:: searchItem(BinaryTreeNode<T> *p, T item){
    if(p==NULL)
        return false;
    else if (p->info == item)
        return true;
    else if(p->info > item)
        return searchItem(p->left, item);
    else
       return searchItem(p->right, item);
}

template<class T>
void BinarySearchTree<T> :: insertItem(T item){
    insertItem(this->root, item);
}

template <class T>
void BinarySearchTree<T> :: insertItem(BinaryTreeNode<T> *&p, T item){
    if(p==NULL){
        p = new BinaryTreeNode<T>;
        p->info = item;
        p->occurances = 1;
        p->right = NULL;
        p->left = NULL;
    }
    else{
        if(p->info == item){
            p->occurances++;
            return;
        }
        else if(p->info > item){
            insertItem(p->left, item);
        }
        else
            return insertItem(p->right, item);
    }
}

template <class T>
void BinarySearchTree<T>:: deleteItem(T item){
    deleteItem(this->root, item);
}

template <class T>
void BinarySearchTree<T> :: deleteItem(BinaryTreeNode<T> *&p, T item){
    BinaryTreeNode<T> *q;
    
    if (p==NULL){
        cout<<"Element not found"<<endl;
    }
    else if ( item < p->info)
        deleteItem(p->left,item);
    else if (item > p->info)
        deleteItem(p->right,item);
    else if ((p->left == NULL) && (p->right == NULL)){
        q=p;
        free(q);
        p=NULL;
    }
    else if (p->left == NULL){
        q=p;
        free(q);
        p=p->right;
    }
    else if (p->right == NULL){
        q=p;
        p=p->left;
        free(q);
    }
    else
        p->info = deletemin(p->right);
}

template <class T>
int BinarySearchTree<T> :: deletemin(BinaryTreeNode<T> *&p){
    int c;
    if (p->left == NULL){
        c=p->info;
        p=p->right;
    }
    else
        c=deletemin(p->left);
    return c;
}


template<class T>
T BinarySearchTree<T>:: getNodeInfo(BinaryTreeNode<T> *p){
    return p->info;
}


template<class T>
int BinarySearchTree<T>:: getNodeOccurances(BinaryTreeNode<T> *p){
    return p->occurances;
}
