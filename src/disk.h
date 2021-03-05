#pragma once

#include "gwindow.h"
#include <random>
#include <sstream>
#include <iomanip>

// ITP 365 Spring 2021
// HW04 – Towers of Hanoi
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

class Disk {
    
    // member variables
private:
    int mX; // bottom center of the disk
    int mY; // size in pixels
    int mWidth; 
    int mHeight;
    std::string mColor;
    
public:
    // Name:
    //        Disk default constructor
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        Sets the member variables to ______
    // Summary:
    //        Creates a Disk
    Disk();
    
    std::string getRandColor();
    
    // Name:
    //        Disk default constructor
    // Input:
    //        int xCoor, int yCoor, int width, int height, std::string color
    // Output:
    //        None
    // Side effects:
    //        Sets the member variables to the inputs
    // Summary:
    //        Creates a Disk
    Disk(int xCoor, int yCoor, int width, int height);
    
    // Name:
    //        Setters
    // Input:
    //        int variables to set as the new member variable
    // Output:
    //        None
    // Side effects:
    //        Changes the member variable
    // Summary:
    //        Sets the appropriate member variable to desired value
    void setX(int newX);
    void setY(int newY);
    
    // Name:
    //        Getters
    // Input:
    //        None
    // Output:
    //        The appropriate member variable
    // Side effects:
    //        None
    // Summary:
    //        Returns the member variable
    int getY();
    int getHeight();
    
    // Name:
    //        draw
    // Input:
    //        GWindow gw, graphical interface window
    // Output:
    //        boolean on weather it was successful or not
    // Side effects:
    //        shows the user a rectangle
    // Summary:
    //        draws a rectangle
    void draw(GWindow& gw);
    
};




