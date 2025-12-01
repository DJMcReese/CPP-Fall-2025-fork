/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>
#include <functional>

void for_each(std::vector<int> const &V, std::function<void(int)> element_function)
{
    for (auto x : V)
        element_function(x);
}

/* Given a vector of ints and an element, return true if the provided
   element appears in the vector and false otherwise. */
bool search(std::vector<int> const &V, int element)
{
    //Task write this function without any loops
    bool found = false;

    auto is_correct_element = [element, &found](int value) {
        bool is_correct = value == element;
        if (is_correct)
            found = true;
    };

    for_each(V, is_correct_element);

    return found;
}

int main()
{
    std::vector<int> V{6, 10, 17};

    std::cout << "Does V contain 6? ";
    if (search(V, 6))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;

    std::cout << "Does V contain 10? ";
    if (search(V, 10))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;

    std::cout << "Does V contain 187? ";
    if (search(V, 187))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;
    return 0;
}