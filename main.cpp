/*
 Date Created:           November 15th, 2017
 
 Last Date Modified:     November 25th, 2017
 
 Programmer:             Alexander Kayuda
 
 Purpose:                The program is part of the second project for Data Structures 2 class.
 
 Description:            This program uses Binary Search Tree data structure to analyze a report (text document provited by user)
                         and issue warnings regarding bad style habits.
 
 Instructions:           Please, provide the absolute path to a .txt file which the contents should be read from as the first argument
                         and the absolute path to location where you want a report to be generated to in the constuctor as the second argument.
 */

#include "GenerateReport.cpp"

int main() {
    
    GenerateReport<string> report("/Users/yourMachineName/Desktop/textFileToAnalyze.txt",
                                  "/Users/yourMachineName/Desktop/Report.txt");
    
    return 0;
}
