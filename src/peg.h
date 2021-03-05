#pragma once

#include "gwindow.h"
#include "disk.h"
#include <vector>
#include <iostream>

// TODO: Your code goes here
class Peg {
    // member variables
private:
    std::vector<Disk> mDisks;
    int mX;
    int mY;
    int mWidth;
    int mHeight;
    std::string mColor;
    int mCurrHeight;
    
public:
    
    // Name:
    //        Peg default constructor
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        Sets the member variables to ______
    // Summary:
    //        Creates a Peg
    Peg();
    
    // Name:
    //        Peg constructor
    // Input:
    //        four int values for the member variables except color
    // Output:
    //        None
    // Side effects:
    //        Sets the member variables to the input variables and sets color
    // Summary:
    //        Creates a Peg
    Peg(int x, int y, int width, int height);
    
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
    int getX();
    int getY();
    
    // Name:
    //        draw
    // Input:
    //        None
    // Output:
    //        None
    // Side effects:
    //        Displays output to the user
    // Summary:
    //        draws a peg and the disks on it
    void draw(GWindow& gw);
    
    // Name:
    //        addDisk
    // Input:
    //        None
    // Output:
    //        bool, wheather the disk was successfully added
    // Side effects:
    //        adds a Disk to the member variable to the end of vector mDisks
    // Summary:
    //        adds a disk to the appropraite peg
    void addDisk(Disk& d);
  
    // Name:
    //        removeDisk
    // Input:
    //        None
    // Output:
    //        returns the Disk that was removed
    // Side effects:
    //        removes a disk from the member variable vector mDisks
    // Summary:
    //        removes a disk from the peg
    Disk removeDisk();
    
};
