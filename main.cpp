#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "gwindow.h"
#include "disk.h"
#include "peg.h"
#include "towers.h"

// ITP 365 Spring 2021
// HW04 – Towers of Hanoi
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

int main(int argc, const char* argv[])
{
    // declaring and instantiating variables with user input
    std::srand(std::time(0));
    std::vector<Peg> pegVec;
    int startPeg;
    int endPeg;
    int sWidth;
    int sHeight;
    int numDisks = promptForDisks();
    promptForPegs(startPeg, endPeg);
    startPeg -= 1;
    endPeg -= 1;
    int p = promptForPause();
    promptForWindowSize(sWidth, sHeight);
    GWindow gw(sWidth, sHeight);

    // creating pegs based on window size & adding pegs to vector
    int pY = sHeight - 10; // 900
    int pX = sWidth / 3; // 166
    int pHeight = sHeight - 50;
    for (int j = 0; j < 3; j++) {
        Peg p = Peg(((pX / 2) + (j * pX)), pY, 10, pHeight);
        pegVec.push_back(p);
    }

    // adding the disks to the vector of the starting peg
    int dHeight = (pHeight - 10) /10;
    int dWidth = pX - 20;
    for (int i = 0; i < numDisks; i++) {
        Disk dis = Disk(pegVec[startPeg].getX(), (pegVec[startPeg].getY() - (i * dHeight)), dWidth, dHeight);
        pegVec[startPeg].addDisk(dis);
        dWidth -= dWidth / 5;
    }
    // drawing the starting peg with its disks
    draw(gw, pegVec, p);
    // solving
    towerSolver(gw, pegVec, startPeg, endPeg, numDisks, p);

	return 0;
}
