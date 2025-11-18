/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void print_vector(std::vector<T> const &V)
{
    for (auto x : V)
        std::cout << x << " ";
    std::cout << std::endl;
}

template <typename OutType, typename InType>
std::vector<OutType> convert_vector(std::vector<InType> const &input)
{
    std::vector<OutType> result{};
    for (int x : input)
        result.push_back(x);
    return result;
}
// std::vector<int> convert_vector(std::vector<float> const &input)
// {
//     std::vector<int> result{};
//     for (float x : input)
//         result.push_back(x);
//     return result;
// }
// Can't do this
// std::vector<unsigned int> convert_vector(std::vector<float> const &input)
// {
//     std::vector<unsigned int> result{};
//     for (float x : input)
//         result.push_back(x);
//     return result;
// }

int main()
{

    std::vector<int> V1{-6, 10, 17};
    std::vector<float> V2{10.6, 11.6, 10.17};
    // std::vector<int> V3{6, 10, 17};

    //Task: Create a vector IV2 containing the integer
    //      version of each element of V2.

    std::vector<int> IV2{};
    IV2 = convert_vector<int, float>(V2);
    print_vector(IV2);

    std::vector<float> FV1{};
    FV1 = convert_vector<float, int>(V1);
    print_vector(FV1);

    //Task: Create vector UIV2 containing the unsigned
    //      int version of each element of V2
    std::vector<unsigned int> UIV2{};
    UIV2 = convert_vector<unsigned int, float>(V2);

    /*
    std::vector<unsigned int> UIV2 {};
    // TO DO
    print_vector(UIV2);
    */

    return 0;
}
