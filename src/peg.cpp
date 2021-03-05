#include "peg.h"

// ITP 365 Spring 2021
// HW04 – Towers of Hanoi
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

Peg::Peg() {
    mX = 0;
    mY = 0;
    mWidth = 0;
    mHeight = 0;
    mColor = "";
}
    
Peg::Peg(int x, int y, int width, int height) {
    mX = x;
    mY = y;
    mWidth = width;
    mHeight = height;
    mColor = "DARK_GRAY";
}

int Peg::getX() {
    return mX;
}

int Peg::getY() {
    return mY;
}

void Peg::draw(GWindow& gw) {
    std::string color = gw.getColor();
    gw.setColor(mColor);
    
    // draw the peg, then draw all the disks on the peg's member variable vector
    gw.fillRect(mX - mWidth / 2, mY - mHeight, mWidth, mHeight);
    for (Disk d : mDisks) {
        d.draw(gw);
    }
    
    gw.setColor(color);
    
}

void Peg::addDisk(Disk& d) {
    // set mCurrHeight to the current height of the peg, where the next disk should be added
    if (mDisks.size() == 0) {
        mCurrHeight = mY;
    }
    else {
        // if the peg is not empty, make mCurrHeight the Y variable of the last disk on the peg minus the disk height
        mCurrHeight = (mDisks[mDisks.size() - 1].getY()) - (mDisks[mDisks.size() - 1].getHeight());
    }
    // set the x and y variables of the disk before adding it to the peg
    d.setX(mX);
    d.setY(mCurrHeight);
    mDisks.push_back(d);
}
  
Disk Peg::removeDisk() {
    // removes the last disk from the peg and returns it
    Disk disk = mDisks[mDisks.size() - 1];
    mDisks.pop_back();

    return disk;
}

