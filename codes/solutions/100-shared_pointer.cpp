/**
 * Copyright (C) 2021 Bill Bird
 * This file is part of Bill Bird's CSC 116 teaching materials.
 */

#include <iostream>
#include <memory>

class Fruit
{
public:
    Fruit(std::string the_name) : name{the_name}
    {
        std::cout << "Fruit constructor: " << name << std::endl;
    }
    ~Fruit()
    {
        std::cout << "Fruit destructor: " << name << std::endl;
    }

    std::string get_name() const { return name; }

private:
    std::string name;
};

class SeededFruit : public Fruit
{
public:
    virtual int num_seeds() = 0;
};

std::shared_ptr<Fruit> make_thing()
{
    std::shared_ptr<Fruit> Y = std::make_shared<Fruit>("Raspberry");
    std::shared_ptr<Fruit> Z = std::make_shared<Fruit>("Pineapple");
    // throw ...
    // delete Z;
    return Y;
}

int main()
{
    std::cout << "main (1)" << std::endl;
    /* Task 1: Modify the statement below to use a smart pointer instead of raw
               dynamic allocation. */
    std::shared_ptr<Fruit> A{std::make_shared<Fruit>("Pear")};

    //malloc free
    //new delete
    // delete A;

    std::cout << A->get_name() << std::endl;
    // Fruit &f = *A;

    std::cout << "main (2)" << std::endl;
    // /* Task 2: Try out the following statement (which would cause a memory leak
    //            using normal dynamic allocation). */
    // A = nullptr;
    std::cout << "main (3)" << std::endl;
    // /* Task 3: Comment out Task 2 and try reassigning A to point at a new Fruit
    //            object with the name "Grapefruit" instead. */
    A = std::make_shared<Fruit>("Grapefruit");

    std::cout << "main (4)" << std::endl;
    // /* Task 4a: Create another smart pointer B and set it equal to A.
    std::shared_ptr<Fruit> B{A};
    // A = nullptr;

    // /* Task 4b: Call the make_thing() function above and assign its return value to A. */
    A = make_thing();
    // B = nullptr;

    std::cout << "main (5)" << std::endl;

    std::vector<std::shared_ptr<SeededFruit>> V;
    V.resize(10);

    return 0;
}
