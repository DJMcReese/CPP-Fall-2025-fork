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

    auto print = [](int x) { std::cout << x << " "; };

    for_each(V, print);
    std::cout << std::endl;

    std::for_each(V.rbegin(), V.rend(), print);
    std::cout << std::endl;

    return 0;
}