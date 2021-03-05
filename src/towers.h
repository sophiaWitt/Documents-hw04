#pragma once

#include "gwindow.h"
#include "peg.h"

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;

// Name:
//        promptForDisks
// Input:
//        None
// Output:
//        integer that the user inputted
// Side effects:
//        Displays and takes in output to and from the user
// Summary:
//        receives user input for the amount of disks to use
int promptForDisks();

// Name:
//        promptForPegs
// Input:
//        two ints by reference
// Output:
//        None
// Side effects:
//        Displays and takes in output to and from the user
// Summary:
//        sets the inputed ints to the user's input
void promptForPegs(int& startPeg, int& endPeg);

// Name:
//        promptForPause
// Input:
//        None
// Output:
//        integer that the user inputted
// Side effects:
//        Displays and takes in output to and from the user
// Summary:
//        receives user input for the amount of time to pause in between each frame
int promptForPause();

// Name:
//        promptForWindowSize
// Input:
//        two ints by reference
// Output:
//        None
// Side effects:
//        Displays and takes in output to and from the user
// Summary:
//        sets the inputed ints to the user's input
void promptForWindowSize(int& width, int& height);

// Name:
//        draw
// Input:
//        a GWindow and a vector of Peg objects by reference, an int
// Output:
//        None
// Side effects:
//        Displays output to the user in a GWindow
// Summary:
//        draws the three pegs and the disks on each of them
void draw(GWindow& gw, std::vector<Peg>& pegVec, int p);
  
// Name:
//        moveDisk
// Input:
//        a GWindow and vector of Peg objects by reference, three ints for the start peg, destination peg and pause length
// Output:
//        None
// Side effects:
//        alters the Disk object vectors of the Peg objects
// Summary:
//        moves the top disk from one peg to another
void moveDisk(GWindow& gw, std::vector<Peg>& pegVec, int startPeg, int destPeg, int pauseLen);

// Name:
//        towerSolver
// Input:
//        a GWindow and vector of Peg objects by reference, four ints for the start peg, destination peg, the number of moving disks and the pause length
// Output:
//        None
// Side effects:
//        Displays output to the user and changes the Peg objects' vectors of Disk objects
// Summary:
//        solves the Tower of Hanoi game using a recursive solution
void towerSolver(GWindow& gw, std::vector<Peg>& pegVec, int startPeg, int endPeg, int numMovingDisks, int pauseLen);
    

