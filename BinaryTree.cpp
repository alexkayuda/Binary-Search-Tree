
#include "BinaryTree.h"

template <class T>
BinaryTree<T> :: BinaryTree(){
    root = NULL;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T> :: getRoot() const{
    return root;
}

template <class T>
BinaryTree<T> :: ~BinaryTree(){
    destroyTree(root);
}

template <class T>
void BinaryTree<T> :: destroyTree(){
    destroyTree(root);
}

template <class T>
void BinaryTree<T> :: destroyTree(BinaryTreeNode<T> *&p){
    if(p!=NULL){
        destroyTree(p->left);
        destroyTree(p->right);
        delete(p);
        p=NULL;
    }
}

template<class T>
BinaryTree<T> :: BinaryTree(const BinaryTree<T> & otherTree){
    if(otherTree.root == NULL)
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template<class T>
BinaryTree<T>& BinaryTree<T> :: operator=(const BinaryTree<T>& otherTree){
    if(this != &otherTree){
        if(root != NULL)
            destroyTree(root);
        if(otherTree.root == NULL)
            root = NULL;
        else
            copyTree(otherTree, root);
        return *this;
    }
}


template <class T>
void BinaryTree<T> :: copyTree(BinaryTreeNode<T> *myTreeRootPointer, BinaryTreeNode<T> *&copyTreeRootPointer){
    if(myTreeRootPointer==NULL)
        copyTreeRootPointer = NULL;
    else{
        copyTreeRootPointer = new BinaryTreeNode<T>;
        copyTreeRootPointer-> info = myTreeRootPointer->info;
        copyTree(myTreeRootPointer->left, copyTreeRootPointer->left);
        copyTree(myTreeRootPointer->right, copyTreeRootPointer->right);
    }
}
template <class T>
int BinaryTree<T>:: nodeCount(){
    return nodeCount(root);
}

template<class T>
int BinaryTree<T>:: nodeCount(BinaryTreeNode<T> *p){
    if( p == NULL)
        return 0;
    else
        if( p->left == NULL && p->right== NULL)
            return 1;
        else
            return(1 + (nodeCount(p->left) + nodeCount(p->right)));
}

template <class T>
int BinaryTree<T>:: leavesCount(){
    return leavesCount(root);
}

template <class T>
int BinaryTree<T>:: leavesCount(BinaryTreeNode<T> *p){
    if( p == NULL)
        return 0;
    if( p->left == NULL && p->right == NULL )
        return 1;
    else
        return leavesCount(p->left) + leavesCount(p->right);
}

template <class T>
int BinaryTree<T>:: heightOfTree(){
    return height(root);
}

template<class T>
int BinaryTree<T> :: height(BinaryTreeNode<T> *p){
    if(p != NULL)
        return 1 + max(height(p->left), height(p->right) );
    else
        return 0;
}

template<class T>
int BinaryTree<T>:: max(int value1, int value2){
    return ((value1 > value2) ? value1 : value2);
}

template <class T>
void BinaryTree<T> :: print(T data){
    cout<< data << " ";
}

template <class T>
void BinaryTree<T> :: preorderTraversal(){
    preorder(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T> :: preorder(BinaryTreeNode<T> *p){
    if (p != NULL){
        //cout <<  p->info << " ";
        print(p->info);
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void BinaryTree<T> :: inorderTraversal(){
    inorder(root);
    cout<< endl;
}

template <class T>
void BinaryTree<T> :: inorder(BinaryTreeNode<T> *p){
    if (p != NULL){
        inorder(p->left);
        //cout <<  p->info << " ";
        print(p->info);
        inorder(p->right); 
    }
}

template <class T>
void BinaryTree<T> :: postorderTraversal(){
    postorder(root);
    cout<<endl;
}

template <class T>
void BinaryTree<T> :: postorder(BinaryTreeNode<T> *p){
    if (p != NULL){
        postorder(p->left);
        postorder(p->right);
        //cout <<  p->info << " ";
        print(p->info);
    }
}

template <class T>
bool BinaryTree<T> :: isEmpty(){
    return (root==NULL);
}
