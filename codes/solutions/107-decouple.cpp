/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>

/* Task: condense the "all" and "any" functions into
a generic all_of and any_of function which take a condition as argument*/

template <typename T>
bool all_of(std::vector<T> const &V, std::function<bool(const T &)> condition)
{
    for (const T &x : V)
        // if (x % 2 != 0) //If the element is not even, return false.
        if (!condition(x))
            return false;
    return true;
}

template <typename T>
bool any_of(std::vector<T> const &V, std::function<bool(const T &)> condition)
{
    for (auto x : V)
        // if (x % 2 != 0) //If the element is not even, return false.
        if (condition(x))
            return true;
    return false;
}

// /* all_even: Return true if every element of the provided
//          vector is an even number. */
// bool all_even(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x % 2 != 0) //If the element is not even, return false.
//             return false;
//     return true;
// }

// /* all_positive: Return true if every element of the provided
//          vector is a positive number. */
// bool all_positive(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x <= 0) //If the element is zero or negative, return false.
//             return false;
//     return true;
// }

// /* all_zero: Return true if every element of the provided
//          vector is zero. */
// bool all_zero(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x != 0) //If the element is not zero, return false.
//             return false;
//     return true;
// }

// /* any_even: Return true if any element of the provided
//          vector is an even number. */
// bool any_even(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x % 2 == 0) //If the element is even, return true.
//             return true;
//     return false;
// }

// /* any_positive: Return true if any element of the provided
//          vector is a positive number. */
// bool any_positive(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x > 0) //If the element is positive, return true.
//             return true;
//     return false;
// }

// /* any_zero: Return true if any element of the provided
//          vector is zero. */
// bool any_zero(std::vector<int> const &V)
// {
//     for (auto x : V)
//         if (x == 0) //If the element is zero, return true.
//             return true;
//     return false;
// }

bool is_even(const int &x)
{
    return x % 2 == 0;
}

bool is_positive(const int &x)
{
    return x > 0;
}

bool is_zero(int x)
{
    return x == 0;
}

bool is_string_long(const std::string &s)
{
    return s.size() > 5;
}

bool is_string_lower(const std::string &s)
{
    for (auto c : s)
        if (!std::islower(c))
            return false;

    return true;
}

void print_results(std::vector<int> const &V)
{
    // std::cout << "all_even = " << all_even(V);
    std::cout << "all_even = " << all_of<int>(V, is_even);

    // std::cout << ", all_positive = " << all_positive(V);
    std::cout << ", all_positive = " << all_of<int>(V, is_positive);

    // std::cout << ", all_zero = " << all_zero(V);
    std::cout << ", all_zero = " << all_of<int>(V, is_zero);

    // std::cout << ", any_even = " << any_even(V);
    std::cout << ", any_even = " << any_of<int>(V, is_even);

    // std::cout << ", any_positive = " << any_positive(V);
    std::cout << ", any_positive = " << any_of<int>(V, is_positive);

    // std::cout << ", any_zero = " << any_zero(V);
    std::cout << ", any_zero = " << any_of<int>(V, is_zero);
    std::cout << std::endl;
}

int main()
{

    std::vector<int> V0{0, 0, 0, 0};
    std::vector<int> V1{0, 2, 4, 6, 8, 10};
    std::vector<int> V2{-2, -4, 0, 6, 10};
    std::vector<int> V3{6, 10, 17, 187};

    std::cout << "V0: ";
    print_results(V0);

    std::cout << "V1: ";
    print_results(V1);

    std::cout << "V2: ";
    print_results(V2);

    std::cout << "V3: ";
    print_results(V3);

    std::vector<std::string> Vs1{"Raspberry", "Pear", "Pineapple"};

    bool all_long = all_of<std::string>(Vs1, is_string_long);
    std::cout << "all long? " << all_long << std::endl;

    bool any_long = any_of<std::string>(Vs1, is_string_long);
    std::cout << "any long? " << any_long << std::endl;

    std::vector<std::string> Vs2{"pear", "peach", "lemon"};

    bool is_lower_case = all_of<std::string>(Vs2, is_string_lower);
    std::cout << "all lowee? " << is_lower_case << std::endl;

    return 0;
}