// # Iterator, Collections and Maps

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cctype>
#include <set>

// ## Exercise 1 (Set)
// Implement a function punctuation, which creates a set of all punctuation characters used in a vector of input strings. Once all the input has been processed, print each punctuation character separated by spaces. [Here](https://en.cppreference.com/w/cpp/header/cctype), you can find functions to check if a character is a punctuation.

// ### Example of input
// ```
// {"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"}
// ```

// ### Example of output
// ```
// ! ' , .
// ```

int exer_1(std::vector<std::string> input_vector)
{
    std::set<char> punctuation;
    for(auto str : input_vector)
    {
        for(char c : str)
        {
            if(std::ispunct(c))
            {
                punctuation.insert(c);
            }
        }
    }
    for(auto punc : punctuation)
    {
        std::cout << punc << " ";
    }
    std::cout << std::endl;
    return 0;
}
// ## Exercise 2 (Iterators)

// Write a program that prompts the user for a string. Print the string in reverse order using iterators.

// ### Example of output

// ```
//   Enter string:
//   > of that im sure

// Reverse is string: erus mi taht fo
// ```
void exer_2()
{
    std::cout << "Enter string: ";
    std::string input_string;
    std::cin.ignore(); // To clear the newline character from the input buffer
    std::getline(std::cin, input_string);
    std::cout << "Reverse is string: ";
    for( auto it = input_string.rbegin()-1; it != input_string.rend(); it++)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

}

// ## Exercise 3 (Set)

// Write a program that receives a vector integer, removes all duplicates using a set, and prints the cleaned data set.


// ### Example of output

// ```
//   Numbers:
//   1 1 1 2 6 5 1 1 6

// Clean:
// 1 2 5 6
// ```


// ## Exericse 4 (Word Frequencies using Maps)

// Write a program which reads a string and prints the word frequency for each word using a map.


// ### Example of output

// ```
// Input
// > sally sells seashells by the seashore
// she sells seashells on the seashell shore
// the seashells she sells are seashore shells

// Word Frequencies:
// sally 1
// sells 3
// seashells 3
// by 1
// the 3
// seashore 2
// she 2
// on 1
// seashell 1
// shore 1
// are 1
// shells 1
// ```
int main() {
    //std::cout << "Which exersice do you want to run? (0, 1, 2, 3, 4): "; 
    int exercise{100};
    while(exercise != 0)
    {
        std::cout << "Which exercise do you want to run? (0, 1, 2, 3, 4): "; 
        std::cin >> exercise;
        std::cout << "You chose exercise " << exercise << std::endl;

        if(exercise == 1) 
        {

            std::cout << "Exercise 1 begining..." << std::endl;
            exer_1(std::vector<std::string>{"Sea", "Shore,", "sea", "shell's.", "SHORE.", "line!"});
            std::cout << "Exercise 1 completed" << std::endl;
        }
        else if (exercise == 2) 
        {
            std::cout << "Exercise 2 begining..." << std::endl;
            exer_2();
            std::cout << "Exercise 2 completed" << std::endl;
        }
        else if (exercise == 3) 
        {
            std::cout << "Exercise 3 begining..." << std::endl;
            //exer_3();
            std::cout << "Exercise 3 completed" << std::endl;
        } 
        else if (exercise == 4) 
        {
            //To be implemented
        } 
        else 
        {
            std::cout << "Invalid exercise number" << std::endl;
        }
    }
}
