/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <vector>
#include <functional>

void print_int(int z)
{
    std::cout << "print_int: " << z << std::endl;
}
int sum_vector(std::vector<int> &V)
{
    int sum{0};
    for (auto x : V)
        sum += x;
    return sum;
}
int mul_vector(std::vector<int> &V)
{
    int product{1};
    for (auto x : V)
        product *= x;
    return product;
}

//Task3 : Write a function get_operation which takes
//        a string and returns one of the above functions:
//         - The return value is the sum_vector function
//           if the provided string is "sum"
//         - The return value is the mul_vector function
//           if the provided string is "multiply"
std::function<int(std::vector<int> &)>
get_operation(const std::string &operation)
{
    if (operation == "sum")
    {
        return sum_vector;
    }
    else if (operation == "multiply")
    {
        return mul_vector;
    }
    else
    {
        throw std::invalid_argument{operation + " is invalid"};
    }
}

int main()
{

    std::vector<int> V{6, 10, 17};

    for (auto x : V)
    {
        print_int(x);
    }

    // Task 1: Create a variable SF which refers to the
    //         sum_vector function, such that the call below
    //         works correctly.
    std::function<int(std::vector<int> &)> SF{sum_vector};

    // int sum_vector(std::vector<int> &V)
    int sum = SF(V); //equivalent to sum_vector(V)
    std::cout << "Sum = " << sum << std::endl;

    // // Task 2: Create a variable p which refers to the print_int
    // //         function, such that the following loop prints the
    // //         elements of V.

    // void print_int(int z)
    std::function<void(int)> p{print_int};

    for (auto x : V)
    {
        p(x);
    }
    std::cout << std::endl;

    // Task 3: See above.
    auto op = get_operation("multiply");
    std::cout << "Op: " << op(V);
    std::cout << std::endl;

    return 0;
}
