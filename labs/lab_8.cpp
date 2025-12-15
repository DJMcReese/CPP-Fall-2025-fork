// # Iterator, Operators, Classes
#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <stdexcept>


// ## Exercise 1 (Class)

// Implement the class StopWatch. The class should contain:

// - An constructor that initialises the start time with the current time
// - Function `start` that resets the start time
// - Function `stop` that sets the end time
// - Function `get_time` that returns the elapsed time in *seconds*.

class Stopwatch
{
public:
    Stopwatch() = default;

    void start()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop()
    {
        end_time = std::chrono::high_resolution_clock::now();
    }

    double elapsed()
    {
        return std::chrono::duration<double>(end_time - start_time).count();
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time;
};

// ## Exercise 2 (Class)

// Implement the class `QuadraticEquation` (`ax^2 + bx + c = 0`). The class should contain:

// - A constructor that takes the 3 coefficients, if the equation has no solutution throw an invalid argument exception
// - The getters and setters for all fields, if the equation has no solutution throw an invalid argument exception
// - Function `get_discriminant` that computes the discriminant `b^2 - 4ac`
// - Function `has_real_solution` that checks if the discriminant is positive
// - Function `is_quadratic` that checks if a is different from zero
// - Function `has_duplicated_solution` that checks if the discriminant is zero
// - Two functions `get_solution1` and `get_solution2` that returns the two solutions (`(-b+sqrt(discriminant))/(2a)` and `(-b-sqrt(discriminant))/(2a)`)

class QuadraticEquation
{
public:
    QuadraticEquation(double a_coeff, double b_coeff, double c_coeff)
        : a{a_coeff}, b{b_coeff}, c{c_coeff}
    {
        
        if (!is_quadratic())
        {
            throw std::invalid_argument{"The equation is not quadratic (a cannot be zero)."};
        }
        if (!has_real_solution())
        {
            throw std::invalid_argument{"The equation has no real solution."};
        }
    }

    double get_a() const
    {
        return a;
    }

    double get_b() const
    {
        return b;
    }

    double get_c() const
    {
        return c;
    } 

    void set_a(double a_coeff)
    {
        if (a_coeff == 0.0) throw std::invalid_argument{"a cannot be zero"};
        a = a_coeff;
        if (!has_real_solution()) throw std::invalid_argument{"Setting coefficients produces no real solution"};
    }

    void set_b(double b_coeff)
    {
        b = b_coeff;
        if (!has_real_solution()) throw std::invalid_argument{"Setting coefficients produces no real solution"};
    }
    void set_c(double c_coeff)
    {
        c = c_coeff;
        if (!has_real_solution()) throw std::invalid_argument{"Setting coefficients produces no real solution"};
    }
    
    double get_discriminant() const
    {
        return b * b - 4 * a * c;
    }   

    bool has_real_solution() const
    {
        return get_discriminant() >= 0;
    }

    bool is_quadratic() const
    {
        return a != 0;
    }

    bool has_duplicated_solution() const
    {
        return get_discriminant() == 0;
    }

    double get_solution1() const
    {
        if (!is_quadratic())
        {
            throw std::invalid_argument{"The equation is not quadratic (a cannot be zero)."};
        }
        if (!has_real_solution())
        {
            throw std::invalid_argument{"The equation has no real solution."};
        }
        return (-b + std::sqrt(get_discriminant())) / (2 * a);
    }

    double get_solution2() const               
    {
        if (!is_quadratic())
        {
            throw std::invalid_argument{"The equation is not quadratic (a cannot be zero)."};
        }
        if (!has_real_solution())
        {
            throw std::invalid_argument{"The equation has no real solution."};
        }
        return (-b - std::sqrt(get_discriminant())) / (2 * a);
    }
     
    ~QuadraticEquation()
    {
        std::cout << "QuadraticEquation destructor called." << std::endl;
    }

private:
    double a;
    double b;
    double c;
};



// ## Exercise 3 (Class, Operators, Iterators)

// Implement the `IntVector` class as a vector of int. It should:

// - contain `size()` return the size of the vector
// - use `(int)` and `[int]` to acces the element at a given index
// - contain `push(int)` adds an integer at the end
// - be printable with `cout<<``
// - contain `begin()` and `end()` that return `IntVectIt`

// Implement the iterator class `IntVectIt`, it should contain:

// - `++` to increment the iterator
// - `*` to access the element
// - `==` to compare it with another iterator



// ## Exericse 4 (Class, Operators)

// Write the class `Point`, which represents an (x,y) point in the plane.
// Provide operators to sum two points, multiply them (element whise), multiply with scalar, and compare them.

int main() {
    //std::cout << "Which exersice do you want to run? (0, 1, 2, 3, 4): "; 
    int exercise{100};
    while(exercise != 0)
    {
        std::cout << "Which exercise do you want to run? (0, 1, 2, 3, 4): "; 
        std::cin >> exercise;
        std::cout << "You chose exercise " << exercise << std::endl;

        if(exercise == 1) 
        {
            std::string endterm;
            std::cout << "Exercise 1 begining..." << std::endl;
            Stopwatch S;
            S.start();
            while( endterm != "stop") {
                std::cout << "Type stop to stop the watch: ";
                std::cin >> endterm;
            }
            if(endterm == "stop") {
                S.stop();
                std::cout << "Elapsed time: " << S.elapsed() << " seconds." << std::endl;
            }
            std::cout << "Exercise 1 completed" << std::endl;

        }
        else if (exercise == 2) 
        {
            std::cout << "Exercise 2 begining..." << std::endl;
            double a, b, c;
            std::cout << "Enter coefficients a: ";
            std::cin >> a;
            std::cout << "Enter coefficients b: ";
            std::cin >> b;
            std::cout << "Enter coefficients c: ";
            std::cin >> c;
            try {
                QuadraticEquation qe{a, b, c};
                if(qe.has_duplicated_solution()) {
                    std::cout << "The equation has one duplicated solution: " << qe.get_solution1() << std::endl;
                } else {
                    std::cout << "The equation has two solutions: " << qe.get_solution1() << " and " << qe.get_solution2() << std::endl;
                }
            } catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << "Exercise 2 completed" << std::endl;
        }
        else if (exercise == 3) 
        {
            std::cout << "Exercise 3 begining..." << std::endl;
            //exer_3();
            std::cout << "Exercise 3 completed" << std::endl;
        } 
        else if (exercise == 4) 
        {
            //To be implemented
        } 
        else 
        {
            std::cout << "Invalid exercise number" << std::endl;
        }
    }
}