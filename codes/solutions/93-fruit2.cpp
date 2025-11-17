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
    std::string get_name() override
    {
        return "Raspberry";
    }
    bool is_delicious() override
    {
        return true;
    }

    Raspberry(int seed_count)
    {
        num_seeds = seed_count;
    }
    int get_num_seeds()
    {
        return num_seeds;
    }

private:
    int num_seeds;
};

void print_fruit(Fruit &f)
{
    std::cout << "Fruit: " << f.get_name();
    std::cout << " ";
    if (f.is_delicious())
        std::cout << "(delicious)";
    else
        std::cout << "(not delicious)";
    std::cout << std::endl;

    //Task: Add some code to check whether the provided
    //      Fruit object is actually a Raspberry using
    //      downcasting.
    try
    {
        Raspberry &r = dynamic_cast<Raspberry &>(f);
        std::cout << "The Raspberry has " << r.get_num_seeds() << " seeds" << std::endl;
        // std::cout << "The Raspberry has " << f.get_num_seeds() << " seeds" << std::endl;
    }
    catch (std::bad_cast &e)
    {
        std::cout << ":(" << std::endl;
    }
}

int main()
{
    Fruit F{};
    Raspberry R{666};

    print_fruit(F);

    //The line below is an implicit up-cast
    //(from Raspberry to Fruit&)
    print_fruit(R);

    //The variable R in this context is a Raspberry
    //object
    std::cout << "Name of R: " << R.get_name() << std::endl;

    //The line below is an explicit up-cast
    Fruit &fr = R;
    //We can think of the variable fr as a Raspberry object
    //which is masquerading as "only" a Fruit.
    std::cout << "Name of fr: " << fr.get_name() << std::endl;

    Raspberry &R1 = static_cast<Raspberry &>(fr);
    std::cout << "seeds: " << R1.get_num_seeds() << std::endl;

    return 0;
}
