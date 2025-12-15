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

auto print = [](int x) {std::cout << x << " "; };

int main()
{
    std::vector<int> V{6, 10, 17};



    for_each(V, [](int x){std::cout << x << " ";});
    std::cout << std::endl;

    return 0;
}