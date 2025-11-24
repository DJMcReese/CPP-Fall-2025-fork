/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <cassert>

template <typename FirstType, typename SecondType>
class CustomPair
{
    // static_assert(N > 0);

public:
    FirstType first;
    SecondType second;

    void print()
    {
        std::cout << sqrt(first) << std::endl;
    }
};

template <typename T1, typename T2>
CustomPair<T1, T2> make_custom_pair(const T1 &j, const T2 &k)
{
    CustomPair<T1, T2> result{j, k};
    return result;
}

int main()
{
    // CustomPair<std::string, int> P;
    // CustomPair<int, int> P;
    // P.print();
    // std::vector<int> a;
    // std::cout << a << std::endl;

    // IntPair P = make_int_pair(6, 10);

    // std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    // auto [a, b] = P;
    // std::cout << "a: " << a << ", b: " << b << std::endl;

    /* Task: Comment out the above and make the code below work instead. */

    //CustomPair<int, int> = P = make_custom_pair<int, int>(6, 10);
    //make_custom_pair<int, int>(6, 10) = make_custom_pair(6, 10); -> CustomPair<int, int> we can use auto
    auto P = make_custom_pair(6, 10);

    std::cout << "P.first: " << P.first << ", P.second: " << P.second << std::endl;
    auto [a, b] = P;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::string str{"Raspberry"};
    double g{10.6};
    auto Q = make_custom_pair(str, g);

    std::cout << "Q.first: " << Q.first << ", Q.second: " << Q.second << std::endl;
    auto [c, d] = Q;
    std::cout << "c: " << c << ", d: " << d << std::endl;

    std::vector<int> A, B;
    auto PPP = make_custom_pair(A.begin(), B.begin());
    // CustomPair<std::vector<int>::iterator, std::vector<int>::iterator> PPP = make_custom_pair(A.begin(), B.begin());

    return 0;
}