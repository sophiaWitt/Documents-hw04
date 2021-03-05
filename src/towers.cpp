#include "towers.h"

// ITP 365 Spring 2021
// HW04 – Towers of Hanoi
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

int promptForDisks() {
    int numDisks = -1;
    
    while ((numDisks < MINDISKS) || (numDisks > MAXDISKS)) {
        std::cout << "How many disks would you like (1-10): ";
        std::cin >> numDisks;
    }
    
    return numDisks;
}

void promptForPegs(int& startPeg, int& endPeg) {
    startPeg = -1;
    endPeg = -1;
    
    while ((startPeg < 0) || (startPeg > NUMPEGS)) {
        std::cout << "Choose a peg to start on (1-3): ";
        std::cin >> startPeg;
    }
    
    
    while ((endPeg < 0) || (endPeg > NUMPEGS)) {
        std::cout << "Choose a peg to end on (1-3): ";
        std::cin >> endPeg;
        if (endPeg == startPeg) {
            std::cout << "End peg cannot be the same as start peg." << std::endl;
            endPeg = -1;
        }
    }
}

int promptForPause(){
    int pauseNum = -1;
    
    while ((pauseNum < 1) || (pauseNum > MAXPAUSELEN)) {
        std::cout << "Choose a pause length (1 - " << MAXPAUSELEN << "): ";
        std::cin >> pauseNum;
    }
    
    return pauseNum;
}

void promptForWindowSize(int& width, int& height) {
    width = -1;
    height = -1;
    
    while (width < MINSCREENWIDTH || width > MAXSCREENWIDTH) {
        std::cout << "Choose a screen width (" << MINSCREENWIDTH << " - " << MAXSCREENWIDTH << "): ";
        std::cin >> width;
    }
    
    while ((height < MINSCREENHEIGHT) || (height > MAXSCREENHEIGHT)) {
        std::cout << "Choose a screen height (" << MINSCREENHEIGHT << " - " << MAXSCREENHEIGHT << "): ";
        std::cin >> height;
    }
}

void draw(GWindow& gw, std::vector<Peg>& pegVec, int p) {
    gw.clear();
    
    for (Peg p : pegVec) {
        p.draw(gw);
    }
    pause(p);
}

void moveDisk(GWindow& gw, std::vector<Peg>& pegVec, int startPeg, int destPeg, int pauseLen) {
    // remove the disk from the starting peg, save it as an object, and add it to the destination peg
    Disk d = pegVec[startPeg].removeDisk();
    pegVec[destPeg].addDisk(d);
    // draw the updated pegs
    draw(gw, pegVec, pauseLen);
}

void towerSolver(GWindow& gw, std::vector<Peg>& pegVec, int startPeg, int endPeg, int numMovingDisks, int pauseLen) {
    // calculate the temporary peg
    int tempPeg = 3 - (startPeg + endPeg);
    
    if (numMovingDisks == 0) {
        return; // BASE CASE
    }
    else{ // RECURSION
        // Transfer N−1 Disks from “start” to “temp”. This leaves Disk 0 alone on “start” (recursion)
        towerSolver(gw, pegVec, startPeg, tempPeg, numMovingDisks - 1, pauseLen); 
        // Move Disk 0 from “start” to “end” (moveDisk)
        moveDisk(gw, pegVec, startPeg, endPeg, pauseLen);
        // Transfer N−1 Disks from “temp” to “end” so they sit on Disk 0 (recursion)
        towerSolver(gw, pegVec, tempPeg, endPeg, numMovingDisks - 1, pauseLen);
    }
}

