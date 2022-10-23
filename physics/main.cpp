#include <stdio.h>   
#include <iostream>   
#include <math.h>
#include <SFML/Graphics.hpp>
#include "functions.h"
#include <chrono>
#include <thread>
#include <ctime>









int main() {
    srand((unsigned) time(0));
    SquareLeft::velox = rand() % 5;
    SquareRight::velox= rand() % 10;
    SquareLeft::veloy = -(rand() % 3);
    SquareRight::veloy = -(rand() % 3);
    bool validForCollision = true;
    double gravityLeft = .01;
    double gravityRight = .01;
    double friction = .001;
    sf::RenderWindow window(sf::VideoMode(2560, 1440), "Engine");
    window.setFramerateLimit(300);
    

    sf::RectangleShape leftRect;
    sf::RectangleShape rightRect;
    sf::RectangleShape floor;


    sf::Vector2f floorPosition(0, 1000);
    sf::Vector2f leftPosition(round(SquareLeft::xpos), round(SquareLeft::ypos));
    sf::Vector2f rightPosition(round(SquareRight::xpos), round(SquareRight::ypos));

    leftRect.setPosition(leftPosition);
    rightRect.setPosition(rightPosition);
    floor.setPosition(floorPosition);

    leftRect.setSize(sf::Vector2f(SquareLeft::height, SquareLeft::width));
    rightRect.setSize(sf::Vector2f(SquareRight::height, SquareRight::width));
    floor.setSize(sf::Vector2f(2560, 1));

    sf::Text text;

// select the font

sf::Font some;
some.loadFromFile("/Users/jonas/Downloads/computer-modern/cmunbto");
text.setFont(some);
// set the string to display
text.setString("std::to_string(SquareLeft::velox)");

// set the character size
text.setCharacterSize(240); // in pixels, not points!

// set the color
text.setFillColor(sf::Color::White);

// set the text style
int interation = 0;

text.setPosition(100, 100);

    while (window.isOpen()) {
        sf::Event event;
       
       
        SquareLeft::xpos += SquareLeft::velox;
        SquareRight::xpos += SquareRight::velox;
        SquareLeft::ypos += SquareLeft::veloy;
        SquareRight::ypos += SquareRight::veloy;
        SquareLeft::veloy += gravityLeft;
        SquareRight::veloy += gravityRight;
         if (SquareLeft::velox < 0) {
            SquareLeft::velox += friction;
         } else {
            SquareLeft::velox -= friction;
         }

         if (SquareRight::velox < 0) {
            SquareRight::velox += friction;
         } else {
            SquareRight::velox -= friction;
         }
        
        
       
       
       
        // if (checkCollisionX() != checkCollisionY()) {
        //     // validForCollision = true;
        // }
        

        if ((checkCollisionX()) && (((SquareLeft::ypos <= SquareRight::ypos + SquareRight::height + 5) && (SquareLeft::ypos >= SquareRight::ypos + SquareRight::height) ) || ((SquareLeft::ypos + SquareLeft::height + 5) >= (SquareRight::ypos) && (SquareLeft::ypos + SquareLeft::height) <= (SquareRight::ypos)))) { //&& validForCollision) {
            if ((SquareLeft::veloy < -7) || (SquareRight::veloy < -7)) {
                SquareRight::velox = 10;
                SquareRight::veloy = -1;
        
             } else {

                    collideWithOtherBlockY();
                    printf("Left:%f\n", SquareLeft::veloy);    
                    printf("Right:%f\n", SquareRight::veloy);    
                        // validForCollision = false;    
            }
        }

        if (checkCollisionX() && checkCollisionY()) { //&& validForCollision) {
            
            collideWithOtherBlockX();
            
            // validForCollision = false;
        }

        if ((SquareLeft::veloy > 50) || (SquareRight::veloy > 50)) {
            validForCollision = false;
        } else {
            validForCollision = true;
        }


        if (SquareLeft::xpos < 0) {
            SquareLeft::velox = -SquareLeft::velox;
        }

        if ((SquareLeft::xpos + SquareLeft::width) > 2560) {
            SquareLeft::velox = -SquareLeft::velox;
        }

        if ((SquareRight::xpos + SquareRight::width) > 2560) {
            SquareRight::velox = -SquareRight::velox;
            Counter::collisions++;
        }

        if (SquareRight::xpos < 0) {
            SquareRight::velox = -SquareRight::velox;
        }

        if ((SquareLeft::ypos + SquareLeft::height) >= 1000) {
            SquareLeft::ypos = 999 - SquareLeft::height;
            SquareLeft::veloy = -SquareLeft::veloy + (gravityLeft * 25);
            
            if (abs(SquareLeft::veloy) < .3) {
                SquareLeft::veloy = 0;
                gravityLeft = 0;
                SquareLeft::ypos = 999 - SquareLeft::height;
            }
        }

        if ((SquareRight::ypos + SquareRight::height) >= 1000) {
            SquareRight::ypos = 999 - SquareRight::height;
            SquareRight::veloy = -SquareRight::veloy + (gravityRight * 25);
            if (abs(SquareRight::veloy) < .3) {
                SquareRight::veloy = 0;
                gravityRight = 0;
                SquareRight::ypos = 999 - SquareRight::height;
            }
        }
        leftRect.setPosition(leftPosition);
        rightRect.setPosition(rightPosition);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();


        }

        leftPosition.x = round(SquareLeft::xpos);
        rightPosition.x = round(SquareRight::xpos);
        leftPosition.y = round(SquareLeft::ypos);
        rightPosition.y = round(SquareRight::ypos);
        
        window.clear(sf::Color::Black);
        printf("%f\n", SquareRight::velox);

        window.draw(leftRect);
        window.draw(rightRect);
        window.draw(floor);
        window.draw(text);
    
    

        window.display();
    }
    return 0;
}
