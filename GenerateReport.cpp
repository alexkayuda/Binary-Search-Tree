#include <vector>
#include "GenerateReport.h"

template <class T>
GenerateReport<T>:: GenerateReport(string name1, string name2){
    nameOfTheFileToReadFrom = name1;
    nameOfTheFileToWriteTo = name2;
    readFromFile();
}


template <class T>
void GenerateReport<T>:: readFromFile(){
    fromFile.open(nameOfTheFileToReadFrom);
    if(fromFile.fail()){
        cout<<"Error Opening File"<<endl;
        exit(1);
    }
    else{
        string word;
        while (fromFile >> word){
            for (int i = 0, len = (int)word.size(); i < len; i++)
            {
                if (ispunct(word[i]))
                {
                    if(word[i]=='.' || word[i]=='?' || word[i]=='!')
                        numberOfSentenses++;
                    word.erase(i--, 1);
                }
            }
            transform (word.begin(), word.end(), word.begin(), ::tolower);
            numberOfCharacters+= word.size();
            numberOfWords++;
            
            tree.insertItem(word);
        }
        statisticalSummary();
    }
}


template <class T>
void GenerateReport<T> :: statisticalSummary(){
    statisticalSummary(tree.getRoot(), vOfUnqWords);
    printStatisticalSummary();
}

template <class T>
void GenerateReport<T> :: statisticalSummary(BinaryTreeNode<T> *p, std::vector<T>& v){
    if (p != NULL){
        statisticalSummary(p->left,v);
        numberOfUniqueWords++;
        if(p->info.size() > 3 ){
            numberOfUniqueWordsMoreThanTreeLetters++;
            if((p->occurances > numberOfWords*5/100))
                v.push_back(p->info);
        }
        statisticalSummary(p->right,v);
    }
}




template <class T>
void GenerateReport<T> :: printStatisticalSummary(){
    averageWordLength = numberOfCharacters / numberOfWords;
    averageSentensesLengh = numberOfWords / numberOfSentenses;
    
    toFile.open(nameOfTheFileToWriteTo);
    toFile << "File Name: " << nameOfTheFileToReadFrom;
    toFile << "\n==============================================================================\n";
    toFile << "\n\tStatistical Summary:";
    toFile << "\nTotal Number Of Words: " << numberOfWords;
    toFile << "\nTotal Number Of \"Unique\" Words: " << numberOfUniqueWords;
    toFile << "\nTotal Number Of \"Unique\" Words With More Than Tree Letters: " << numberOfUniqueWordsMoreThanTreeLetters;
    toFile << "\nAverage Word Length: " << averageWordLength << " characters";
    toFile << "\nAverage Sentance Length: " << averageSentensesLengh << " words";
    
    if(vOfUnqWords.size() > 0 || averageSentensesLengh > 10 || averageWordLength > 5)
        printStyleWarnings();
    vOfUnqWords.clear();
    printIndexOfUniqueWords();
}

template <class T>
void GenerateReport<T> :: printStyleWarnings(){
    toFile << "\n\n==============================================================================\n";
    toFile << "\n\tStyle Warnings:";
    
    if(vOfUnqWords.size() > 0){
    toFile << "\nWords used to often: ";
        if(vOfUnqWords.size() > 1){
            for (int i = 0 ; i< vOfUnqWords.size(); i++)
                toFile <<"\n" << (i+1) << ") " << vOfUnqWords.at(i);
        }
        else
            toFile <<"\n"<< vOfUnqWords.at(0);
    }
    
    if(averageSentensesLengh > 10)
        toFile << "\nAverage Sentance Length is Too Long - " << averageSentensesLengh<< " words";
    if(averageWordLength > 5)
        toFile << "\nAverage Word Length is Too Long - " << averageWordLength<< " characters";
}

template <class T>
void GenerateReport<T> :: printIndexOfUniqueWords(){
    toFile << "\n\n==============================================================================\n";
    toFile << "\n\tIndex Of Unique Words:\n";
    char indexChar = 'A';
    
    indexTraverse(tree.getRoot(), indexChar);
}

template <class T>
void GenerateReport<T> :: indexTraverse(BinaryTreeNode<T> *p,char& index){
    if (p != NULL){
        indexTraverse(p->left,index);
        if(p->info.at(0) > index){
            index = p->info.at(0);
            toFile << "\n" << (char)toupper(index) << ":";
        }
        toFile << "\n\t" << p->info;
        indexTraverse(p->right,index);
    }
}
