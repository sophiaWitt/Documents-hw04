#include "disk.h"

// ITP 365 Spring 2021
// HW04 – Towers of Hanoi
// Name: Sophia Wittmeier
// Email: wittmeie@usc.edu
// Platform: Mac

Disk::Disk() {
    mX = 0;
    mY = 0;
    mWidth = 0;
    mHeight = 0;
    mColor = "";
    
}

std::string Disk::getRandColor() {
    std::stringstream colorHex;
    // getting three random ints between 1 and 255
    int rr = (std::rand() % 256);
    int gg = (std::rand() % 256);
    int bb = (std::rand() % 256);
    // adding the threee ints to a string to make a color hex
    colorHex << "#" << std::setw(2) << std::hex << rr << std::setw(2) << std::hex << gg << std::setw(2) << std::hex << bb;
    return colorHex.str();
}
    
Disk::Disk(int xCoor, int yCoor, int width, int height) {
    mX = xCoor;
    mY = yCoor;
    mWidth = width;
    mHeight = height;
    mColor = getRandColor();
}

void Disk::setX(int newX) {
    mX = newX;
}
    
void Disk::setY(int newY) {
    mY = newY;
}

int Disk::getY() {
    return mY;
}
    
int Disk::getHeight() {
    return mHeight;
}

void Disk::draw(GWindow& gw) {
    // save the original color to reset it after drawing
    std::string color;
    color = gw.getColor();
    // set color to appropriate member variable and draw the filled rectangle
    gw.setColor(mColor);
    gw.fillRect(mX - mWidth / 2, mY - mHeight, mWidth, mHeight);
    gw.setColor(color);
    
}
