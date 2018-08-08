/*
 Date Created:           November 20th, 2017
 
 Last Date Modified:     November 25th, 2017
 
 Programmer:             Alexander Kayuda
 
 Purpose:                The program is part of the second project for Data Structures 2 class.
 
 Description:            This class opens a .txt file using the address that was provided by user as an argument in a constructor and analyzes file using
                         Binary Search Tree data structure. It outputs the results such as: number of words/"unique" words in a text file, average word and
                        sencense lengths; and some style warnings in case sentenses or words are too long. Also, it outputs all "unique" words in alphabetical order.
 */
#include <fstream>
#include "BinarySearchTree.cpp"

#ifndef GenerateReport_h
#define GenerateReport_h

template <class T>
class GenerateReport{
    
private:
    string nameOfTheFileToReadFrom;
    string nameOfTheFileToWriteTo;
    void readFromFile();
    void statisticalSummary();
    void statisticalSummary(BinaryTreeNode<T> *, std::vector<T>&);
    void styleWarnings();
    void indexTraverse(BinaryTreeNode<T> *, char&);
    
    double numberOfSentenses = 0;
    double numberOfCharacters = 0;
    double numberOfWords = 0;
    int averageWordLength = 0;
    int averageSentensesLengh = 0;
    int numberOfUniqueWords = 0;
    int numberOfUniqueWordsMoreThanTreeLetters = 0;
    
public:
    ifstream fromFile;
    ofstream toFile;
    
    BinarySearchTree<T> tree;
    
    GenerateReport(string,string);
    
    std::vector<T> vOfUnqWords;
    
    void printStatisticalSummary();
    void printStyleWarnings();
    void printIndexOfUniqueWords();
    
};
#endif
