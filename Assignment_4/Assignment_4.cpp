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

class Point2d 
{
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
        // double operator[](int index) const
        // {

        //     if(index == 0){
        //        return x;
        //     }
        //     else if(index == 1){
        //         return y;
        //     }
        
        //     return -1;

             
        // };

        double& operator[](int index)
        {

            if(index == 0){
               return x;
            }
            if(index == 1){
                return y;
            }
        
            return x;
        };
        

    
        bool operator==(Point2d const &rhs) const {
            return(x == rhs.x && y == rhs.y);
        };



        double norm() const
        {
            return std::sqrt(x*x + y*y);
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


        Point2d get_center() const { return center; };
        void set_center(Point2d pos) { center = pos; };

        double get_perimeter()
        {
            return 0.0;
        };
    
        bool contains(Point2d point) const {
            return false;
        };
        
    private:
        Point2d center; 
};

// Implement also 2 subclasses (add all necessary fields and functions): `Circle` and  `Rectangle`

// To check containment inside a circle, you must check if `||p - c||<r` where `p` is the query point, `c` is the center, and `r` is the radius.

// To check containment inside a rectangle, you need to check whether the query point `p` x and y coordinates are within the rectangle's lower and upper bounds.

class Circle : public GeometricObject {
    public:
        Circle() : radius{1}, center{0,0} {};
        Circle(Point2d pos, double rad) : radius{rad}, center{pos} {};
        
        double get_radius ()  
        {
            return radius;
        };
        void set_radius (double rad)
        {
            radius = rad;
        };
        Point2d get_center ()  
        {
            return center;
        };
        void set_center(Point2d pos) 
        {
            center = pos;
        };

        double get_perimeter() const 
        {
            return 2 * M_PI * radius;
        };

        bool contains(Point2d point) 
        {
            Point2d diff = point - center; //do i need an overload for - operator here?
            return diff.norm() < radius;
        };

    private:
        double radius;
        Point2d center;
};

class Rectangle : public GeometricObject {
    public:
        Rectangle() : lower_left{0,0}, upper_right{1,1} {};
        Rectangle(Point2d lower_pos, Point2d upper_pos) : lower_left{lower_pos}, upper_right{upper_pos} {};
        
        double get_width()
        {
            return upper_right[0] - lower_left[0];
        }
        double get_height()
        {
            return upper_right[1] - lower_left[1];
        }

        void set_lower_left(Point2d pos)
        {
            lower_left = pos;
        }

        void set_upper_right(Point2d pos)
        {
            upper_right = pos;
        }

        double get_perimeter() 
        {
            return 2 * (get_width() + get_height());
        };

        bool contains(Point2d point) 
        {
            return (point[0] >= lower_left[0] && point[0] <= upper_right[0] &&
                    point[1] >= lower_left[1] && point[1] <= upper_right[1]);
        };

    private:
        Point2d lower_left;
        Point2d upper_right;
};

int main () {

    // Point2d tests

    Point2d a(1,1);
    Point2d b(2,2);

    std::cout << "Point2d a: " << a << std::endl;
    std::cout << "Point2d b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "b - a: " << b - a << std::endl;

    // operator[] as getter
    double a0 = a[0];
    double a1 = a[1];

    std::cout << "a [] = " << a0 << ", " << a1 << std::endl;

    // operator[] as setter
    a[0] = 5;
    a[1] = 6;

    std::cout << "After setting a [] = 5,6: " << a << std::endl;

    // norm
    double solve = a.norm();

    std::cout << "Norm of a: " << solve << std::endl;

    // operator==
    Point2d d(5,6);

    if (a == d) {
        std::cout << "a and d are equal" << std::endl;
    } else {
        std::cout << "a and d are NOT equal" << std::endl;
    }

    return 0;
}