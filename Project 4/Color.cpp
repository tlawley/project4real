/**
 * Color.cpp
 *
 * EECS 183, Winter 2017
 * Project 4: CoolPics
 *
 * Thomas Lawley, Sahas Sranjan
 * tlawley, sranjan
 *
 * color class implementation
 */

#include "Color.h"

// TODO: implement first checkRange, then two constructors, setRed, getRed,
//       setGreen, getGreen, setBlue, getBlue, read, write.

Color::Color() {
    Color (0, 0, 0);    
}

Color::Color(int redVal, int greenVal, int blueVal){
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
    return;
}

void Color::setRed(int redVal){
    red = checkRange(redVal);
}

int Color::getRed(){
    return checkRange(red);
}

void Color::setGreen(int greenVal){
    green = checkRange(greenVal);
}

int Color::getGreen(){
    return checkRange(green);
}

void Color::setBlue(int blueVal){
    blue = checkRange(blueVal);
}

int Color::getBlue(){
    return checkRange(blue);
}

void Color::read(istream& ins){
    char space1 = ' ';
    char space2 = ' ';
    ins >> red >> space1 >> green >> space2 >> blue;
    return;
}

void Color::write(ostream &outs){
    outs << checkRange(red) << "  " << checkRange(green) << "  " << checkRange(blue);
}

int Color::checkRange(int val){
    if (val >= 0 && val < 256){
        return val;
    }
    else if (val < 0){
        return 0;
    }
    else{
        return 255;
    }
}

// Your code goes above this line.
// Don't change the implementations below!
  
istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}

