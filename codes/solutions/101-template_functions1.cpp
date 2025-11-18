/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <vector>

template <typename your_type>
void print_vector(std::vector<your_type> const &V)
{
    for (const your_type &x : V)
        std::cout << x << ", ";
    std::cout << std::endl;
}

// void print_vector(std::vector<int> const &V)
// {
//     for (auto x : V)
//         std::cout << x << ", ";
//     std::cout << std::endl;
// }
// void print_vector(std::vector<float> const &V)
// {
//     for (auto x : V)
//         std::cout << x << ", ";
//     std::cout << std::endl;
// }

// void print_vector(std::vector<std::string> const &V)
// {
//     for (auto x : V)
//         std::cout << x << " ";
//     std::cout << std::endl;
// }
//copy this and replace your_type with your type
// void print_vector(std::vector<your_type> const &V)
// {
//     for (auto x : V)
//         std::cout << x << " ";
//     std::cout << std::endl;
// }

int main()
{
    // std::vector<int, float> V0{-6, 10, 17};
    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    std::vector<std::string> V3{"Pear", "Raspberry", "Pineapple"};
    std::vector<unsigned int> V4{6, 10, 17};
    std::vector<char> V5{'f'};

    // Task: Write a new version of the functions below which can handle V3

    print_vector(V1);
    print_vector(V2);
    print_vector(V3); // TO DO
    print_vector(V4); // TO DO
    print_vector(V5); // TO DO

    return 0;
}
