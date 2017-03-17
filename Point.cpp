/**
 * Point.cpp
 *
 * EECS 183, Winter 2017
 * Project 4: CoolPics
 *
 * Thomas Lawley Sahas Sranjan
 * tlawley sranjan
 *
 * Project 4 cool pics
 */

#include "Point.h"

// for the declaration of DIMENSION
#include "utility.h"

// for the declaration of DIMENSION
#include "utility.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
    
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
    
    return;
}

int Point::getX() {
    return checkRange(x);
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
    
    return;
}

int Point::getY() {
    return checkRange(y);
}

void Point::read(istream& ins) {
    char first;
    char comma;
    char last;
    ins >> first >> x >> comma >> y >> last;
    
    return;
}

void Point::write(ostream& outs) {
    outs << "(" << checkRange(x) << ", " << checkRange(y) << ")";
    return;
}

int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else if (val >= (.5)*DIMENSION) {
        return DIMENSION - 1;
    }
    else if (val < (.5)*DIMENSION) {
        return 0;
    }
    return 0;
}


// Your code goes above this line.
// Don't change the implementations below!


istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}

