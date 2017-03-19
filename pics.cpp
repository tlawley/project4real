/**
 * pics.cpp
 *
 * EECS 183, Winter 2017
 * Project 4: CoolPics
 *
 * Thomas Lawley
 * tlawley
 *
 * main for project 4
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Line.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Graphics.h"

/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints an opening message.
 */
void printOpener();
/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a closing message.
 */
void printCloser();
/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints a menu.
 */
void printMenu();

/**
 * Requires: ins is in good state.
 * Modifies: cin, ins.
 * Effects:  Closes ins if it is open. Keeps reading filename from the user
 *           (and appends .txt) until the file is successfully opened.
 *           Returns the name of the file that was opened.
 */
string openFile(ifstream& ins){
    if (ins.is_open()){
        ins.clear();
        ins.close();
    }
string file;
cin >> file;
    file = file + ".txt";
    ins.open(file);
    while (ins.fail()){
        cout << "Error in opening " << file << ".";
        ins.clear();
        cout << " Enter another file name: ";
        cin >> file;
        file = file + ".txt";
        ins.open(file);
    }
    return file;
}


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns str with all of its alphabetical characters lowercased.
 */
string tolower(string str);

/**
 * Requires: Nothing.
 * Modifies: cin, drawer.
 * Effects:
 *     Opens a file
 *     Start with a blank canvas (drawer)
 *     Start reading from file.  For each line....
 *        Read the 1st character to determine shape
 *        Read the shape:  L reads a line, C reads a circle, T read a triangle
 *            R reads a rectangle.
 *            For any other character, clears drawer and prints
 *            "Error in input file: " << [character already read]
 *            << [all chars remaining on the line] << endl;
 *        Draw shape on canvas
 *     Close file
 *     Print "[Loaded filename]"
 */
void loadFile(Graphics& drawer);

/**
 * Requires: Nothing.
 * Modifies: cout, drawer.
 * Effects:
 *     Read filename from user
 *     concatenate filename with .bmp
 *     Write image to file.
 *     Print "[Wrote filename]"
 */
void writeFile(const Graphics& drawer);

int main()
{
    Graphics drawer;
    string command;
    printOpener();
    printMenu();

    // read first command from user
    cin >> command;
    cout << endl;
    command = tolower(command);

    // read user's input until he or she quits
    while (command != "quit")
    {
        if (command == "load")
        {
            loadFile(drawer);
        }
        else if (command == "write")
        {
            writeFile(drawer);
        }
        else
        {
            cout << "Invalid command" << endl << endl;
        }

        printMenu();

        // read next command
        cin >> command;
        cout << endl;
        command = tolower(command);
    }

    printCloser();
}

void writeFile(const Graphics& drawer)
{
    // TODO: implement
    // This will make use of Graphics::writeFile()
}

void loadFile(Graphics& drawer){
        ifstream ins;
        string file;
        char shape;
        string errorLine;
        
        fileName = openFile(ins);
        while (!ins.eof()) {
            ins >> shapeType;
            Circle newCircle;
            Line newLine;
            Rectangle newRect;
            Triangle newTri;
            
            switch (shapeType) {
                    
                    
                case 'C':
                    //read and draw a circle
                    ins >> newCircle;
                    newCircle.draw(drawer);
                    break;
                    
                case 'L':
                    // read and draw a line
                    ins >> newLine;
                    newLine.draw(drawer);
                    break;
                    
                case 'R':
                    // read and draw a rectangle
                    ins >> newRect;
                    newRect.draw(drawer);
                    break;
                    
                case 'T':
                    // read and draw a triangle
                    ins >> newTri;
                    newTri.draw(drawer);
                    break;
                    
                default:
                    getline(ins, errorLine);
                    drawer.clear();
                    cout << "Error in input file: " << shapeType << errorLine << endl;
            }
            
            // close ins, print "wrote" statement
            ins.close();
        }
        cout << "[Loaded " << fileName << "]" << endl;
    }    // TODO: implement
}

string tolower(string str)
{
    // convert each character tolower in string
    for (int i = 0; i<str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    
    return str;
}


// Don't change the implementations below!

void printMenu()
{
    cout << "Command:            Description:" << endl
         << "--------            ------------" << endl
         << "load filename       Loads data from a txt file" << endl
         << "write filename      Creates a bmp image from data" << endl
         << "quit                Quits the program" << endl << endl;
}


void printOpener()
{
    cout << "=================================================" << endl
         << "               Welcome to CoolPics" << endl
         << "=================================================" << endl << endl;
}

void printCloser()
{
    cout << "=================================================" << endl
         << "            Thanks for using CoolPics!" << endl
         << "=================================================" << endl;
}

string openFile(ifstream& ins)
{
    string fileName;

    // close stream if open
    if (ins.is_open())
    {
        ins.clear();
        ins.close();
    }

    // get filename
    cin >> fileName;
    fileName = fileName + ".txt";
    ins.open(fileName);

    // keep retrying if failed to open
    while (ins.fail())
    {
        cout << "Error in opening " << fileName
             << ". Enter another file name: ";
        ins.clear();
        cin >> fileName;
        fileName = fileName + ".txt";
        ins.open(fileName);
    }

    return fileName;
}
