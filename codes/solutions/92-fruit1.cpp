/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <string>
#include <typeinfo>

class Fruit
{
public:
    virtual std::string get_name()
    {
        return "Generic Fruit";
    }
    virtual bool is_delicious()
    {
        return false;
    }
};

class Raspberry : public Fruit
{
public:
    Raspberry(int n_seeds)
    {
        this->n_seeds = n_seeds;
    }

    virtual std::string get_name() override
    {
        return "Raspberry";
    }

    virtual bool is_delicious() override
    {
        return true;
    }

    int get_num_seeds() { return n_seeds; }

    // virtual bool is_delicious(int x) override
    // {
    //     return true;
    // }

private:
    int n_seeds;
};

class Pumpkin : public Fruit
{
public:
    Pumpkin()
    {
    }

    virtual std::string get_name() override
    {
        return "Pumpkin";
    }

    virtual bool is_delicious() override
    {
        return false;
    }
};

class Pineapple : public Fruit
{
public:
    Pineapple()
    {
    }

    virtual std::string get_name() override
    {
        return "Pineapple";
    }

    virtual bool is_delicious() override
    {
        return true;
    }
};

void print_fruit(Fruit &f)
{
    // g.get_num_seeds();

    std::cout << "Fruit: " << f.get_name();
    std::cout << " ";
    if (f.is_delicious())
        std::cout << "(delicious)";
    else
        std::cout << "(not delicious)";
    std::cout << std::endl;
}

//Task: Add classes for Raspberry, Pumpkin and Pineapple.
//      Have the constructor for Raspberry take a single
//      int parameter (storing the number of seeds in the
//      raspberry).

int main()
{
    Fruit F{};
    Raspberry R{6};
    Pumpkin J{};
    Pineapple P{};
    print_fruit(F);
    print_fruit(R);
    print_fruit(J);
    print_fruit(P);
    return 0;
}
