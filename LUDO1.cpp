#include <SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<chrono>
#include<thread>
#include"function_random.h"
#include "add.h"
using namespace std;
using namespace sf;
using namespace std::this_thread;
using namespace std::chrono;



int main()
{
    int Roll = 1;
    Texture bg,d,fd;
    Texture g, r, y, b;
    srand(time(0));
    RenderWindow window(VideoMode(1500, 900), "LUDO!");
    window.setKeyRepeatEnabled(false);
    fd.loadFromFile("image/frame_dice.png");
    d.loadFromFile("image/dice.png");
    g.loadFromFile("image/g.png");
    r.loadFromFile("image/r.png");
    b.loadFromFile("image/b.png");
    y.loadFromFile("image/y.png");
    bg.loadFromFile("image/background.png");
    Sprite background(bg),dice(d),frame(fd);
    Sprite r1(r), r2(r), r3(r), r4(r), b1(b), b2(b), b3(b), b4(b), g1(g), g2(g), g3(g), g4(g), y1(y), y2(y), y3(y), y4(y);
    int xc=0,yc=0;
    
    while (window.isOpen())
    {
        
        Vector2i pos = Mouse::getPosition(window);
        Event event;     
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        if (Mouse::isButtonPressed(Mouse::Button::Left) && timeToRoll) {
            if (pos.x >= 125 && pos.x <= 283 && pos.y <= 850 && pos.y >= 692) {
                cout << "click";
                Roll = roll_dice();
                Round++;
                if (Round == 5) Round = 1;
            }
            timeToRoll = 0;
        }
        window.clear(Color::White);
       
        if (event.key.code == Keyboard::Up) {
            
            timeToRoll = 1;
        }//unused for now

        if (Roll == 6) {
            if (event.key.code == Mouse::Left) {
                xc = pos.x;
                yc = pos.y;
                Finished = 0; //position not true
                getstart(xc, yc , Round);
            }
        }
             
        window.draw(background);
        r1.setPosition(red[0][0], red[0][1]);
        r2.setPosition(red[1][0], red[1][1]);
        r3.setPosition(red[2][0], red[2][1]);
        r4.setPosition(red[3][0], red[3][1]);
        b1.setPosition(blue[0][0], blue[0][1]);
        b2.setPosition(blue[1][0], blue[1][1]);
        b3.setPosition(blue[2][0], blue[2][1]);
        b4.setPosition(blue[3][0], blue[3][1]);
        g1.setPosition(green[0][0], green[0][1]);
        g2.setPosition(green[1][0], green[1][1]);
        g3.setPosition(green[2][0], green[2][1]);
        g4.setPosition(green[3][0], green[3][1]);
        y1.setPosition(yellow[0][0], yellow[0][1]);
        y2.setPosition(yellow[1][0], yellow[1][1]);
        y3.setPosition(yellow[2][0], yellow[2][1]);
        y4.setPosition(yellow[3][0], yellow[3][1]);
        window.draw(r1);
        window.draw(r2);
        window.draw(r3);
        window.draw(r4);
        window.draw(b1);
        window.draw(b2);
        window.draw(b3);
        window.draw(b4);
        window.draw(g1);
        window.draw(g2);
        window.draw(g3);
        window.draw(g4);
        window.draw(y1);
        window.draw(y2);
        window.draw(y3);
        window.draw(y4);
        frame.setTextureRect(IntRect(Round * 204, 0, 204, 216));
        frame.setPosition(103,645 );
        window.draw(frame);
        dice.setTextureRect(IntRect((Roll-1) * 158, 0, 158, 158));
        dice.setPosition(125, 692);
        window.draw(dice);
        window.display();
        sleep_for(nanoseconds(100000000));//delay
       
    }

    return 0;
}

