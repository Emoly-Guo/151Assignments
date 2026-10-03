/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign3.cpp
 * 
 * Input: 
 * Output: 
 * 
 * Author: Emily Guo - 301670039
 * *****************************************************************/

#include <iostream>
#include <string>

using namespace std;

// separate each word and add them to a array thats the
// size of the number of words inputed
// use a if/while loop to print out the words backward
// using length-1

int main(){
    
    string sentence;
    string firstWord;
    string secondWord;
    string thirdWord;
    string fourthWord;

    cout << "Please enter a sentence: ";
    cin >> sentence;

    size_t space = sentence.find("*");
    firstWord = sentence.substr(0, space);
    secondWord = sentence.substr(space + 1, sentence.find("*", space + 1));
    

    cout << secondWord << "*" << firstWord << endl;     

    return 0;
}