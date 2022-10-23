#include <stdio.h>   
#include <iostream>   
#include <math.h>
#include "classes.h"
bool xCol;



bool getPositive(double a) {
    if (a < 0) {
        return false;
    } else if (a == 0) {
        return false;
    } else {
        return true;
    }
}

double quadratic(double a, double b, double c) {
    // (-b +- sqrt(b^2 - 4ac))/ 2a
    
    double root = sqrt((b * b) - (4 * a * c));
    double top1 = -b + root;
    double top2 = -b - root;
    double ans1 = top1 / (2 * a);
    double ans2 = top2 / (2 * a);
    if ((((!getPositive(SquareLeft::velox) && !getPositive(SquareRight::velox)) || !getPositive(SquareLeft::velox)) && xCol) || ((((!getPositive(SquareLeft::veloy) && !getPositive(SquareRight::veloy)) || !getPositive(SquareLeft::veloy)) && !xCol))) {
        return ans2;
        } else {
        return ans1; 
    }
    
}

void collideWithOtherBlockY() {
    xCol = false;
    if (SquareLeft::veloy == 0) {
        SquareRight::veloy = -SquareRight::veloy;
        return;
    } 

    if (SquareRight::veloy == 0) {
        SquareLeft::veloy = -SquareLeft::veloy;
        return;
    } 

    


    
    double a = (SquareRight::mass / SquareLeft::mass) + 1;
    double b = 2 * (SquareRight::veloy - SquareLeft::veloy);
    double c = (SquareRight::veloy * SquareRight::veloy) - (2 * SquareRight::veloy * SquareLeft:: veloy) - ((SquareRight::mass / SquareLeft::mass) * (SquareRight::veloy * SquareRight::veloy));
    auto ans = quadratic(a, b, c);
    
    SquareLeft::veloy = (SquareRight::veloy + ans - SquareLeft::veloy) / .99;
    SquareRight::veloy = ans;
    Counter::collisions++;
    
}

void collideWithOtherBlockX() {
    xCol = true;
    double a = (SquareRight::mass / SquareLeft::mass) + 1;
    double b = 2 * (SquareRight::velox - SquareLeft::velox);
    double c = (SquareRight::velox * SquareRight::velox) - (2 * SquareRight::velox * SquareLeft:: velox) - ((SquareRight::mass / SquareLeft::mass) * (SquareRight::velox * SquareRight::velox));
    auto ans = quadratic(a, b, c);
    
    SquareLeft::velox = (SquareRight::velox + ans - SquareLeft::velox);
    SquareRight::velox = ans;
    Counter::collisions++;
    if (getPositive(SquareRight::veloy)) {
        SquareRight::veloy -= .1;
    }
    

    
    
    
   
}

void collideWithLeftWall() {
    SquareLeft::velox = -SquareLeft::velox;
}


void collideWithRightWall() {
    SquareRight::velox = -SquareRight::velox;
    Counter::collisions++;
}

double calculateTotalEnergy() {
    
    double totalEnergy = (SquareLeft::mass * (SquareLeft::velox * SquareLeft::velox)) + (SquareRight::mass * (SquareRight::velox * SquareRight::velox));
    return totalEnergy;
}


bool checkCollisionX() {
    if ((SquareLeft::xpos <= (SquareRight::xpos + SquareRight::width)) && (SquareLeft::xpos + SquareLeft::width >= SquareRight::xpos)) {
        return true;
    } else if ((SquareRight::xpos) <= (SquareLeft::xpos + SquareLeft::width) && (SquareRight::xpos + SquareRight::width) >= SquareLeft::xpos) {
        return true;
    } else {
        return false;
    }
}

bool checkCollisionY() {
    if ((SquareLeft::ypos < SquareRight::ypos + SquareRight::height) && ((SquareLeft::ypos + SquareLeft::height) > (SquareRight::ypos))) {
        return true;
    } else {
        return false;
    }
}












