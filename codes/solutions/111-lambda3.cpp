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

int main()
{
    std::vector<int> V{6, 10, 17};

    int the_sum{0};

    // <>
    // []
    // ()
    auto sum_items = [&the_sum, &V](int x) {
        the_sum += x;
        std::cout << V.at(0) << std::endl;
        // std::cout << the_sum << std::endl;
    };

    for_each(V, sum_items);

    std::cout << "The sum is " << the_sum << std::endl;

    return 0;
}