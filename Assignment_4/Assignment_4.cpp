#include <iostream>
#include <cmath>
#include <string>
#include <sstream>  
#include <vector>

// ## Exercise 1 (10 points)

// Implement the `Point2d` class that contains:

// - The `x` and `y` coordinates
// - The minus operator
// - The plus operator
// - The operator `[]` as a getter and setter
// - A function `norm()` that returns `sqrt(x*x - y*y)`
// - allows to be printed by `cout`
// - `==` operator

class Point2d {
    public:
        Point2d() : x{0}, y{0} {}
        Point2d(double x_cord, double y_cord) : x{x_cord}, y{y_cord} {} 

        Point2d& operator-(const Point2d& rhs) 
        {
            x = x-rhs.x;
            y = y - rhs.y;
            return *this;

        };
        Point2d& operator+(const Point2d& rhs)
        {
            x = x +rhs.x;
            y = y + rhs.y;
            return *this;
        };
        // double operator[](Point2d&){
        //     return *this;
        // };
        // Point2d& operator==(){
        //     return *this;
        // };



        double norm() 
        {
            return sqrt(x*x - y*y);
        }

        friend std::ostream& operator<< (std::ostream& stream , const Point2d& point) {
            stream << "(" << point.x << "," << point.y << ")" << std::endl;
            return stream;
        }

    private:
        double x;
        double y;
};

// Implement the `GeometricObject` class, it should provide:

// - The a `Point2d` for the position of the center
// - An empty constructor that initializes the position at 0,0
// - A constructor that takes a `Point2d` as position
// - The getters and setters for all fields
// - A function `get_perimeter()` that returns the perimeter
// - A function `contains(p)` that checks if a `Point2d` is inside
// - allows to be printed by `cout`
// - `==` operator

class GeometricObject {
    public:
        GeometricObject() : center(0,0) {}
        GeometricObject(Point2d pos) : center(pos) {}
        Point2d get_center() const { return center; }
        void set_center(Point2d pos) { center = pos; }

        // double get_perimeter(){};
    
    private:
        Point2d center; 
};

// Implement also 2 subclasses (add all necessary fields and functions): `Circle` and  `Rectangle`

// To check containment inside a circle, you must check if `||p - c||<r` where `p` is the query point, `c` is the center, and `r` is the radius.

// To check containment inside a rectangle, you need to check whether the query point `p` x and y coordinates are within the rectangle's lower and upper bounds.

int main () {

    Point2d a(1,1);
    Point2d b(2,2);

    Point2d c = a+b;

    std::cout << "Point c created by adding a and b: " << std::endl;

    std::cout << c;

    double a0 = a[0];
    double a1 = a[1];

    std::cout << "a [] = " << a0 << ", " << a1 << std::endl;

    return 0;
}