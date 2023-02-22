#include <SFML/Graphics.hpp>
#include<iostream>
#include<time.h>
#include<cstdlib>
#include<chrono>
#include<thread>
using namespace std;
using namespace sf;
using namespace std::this_thread;
using namespace std::chrono;

int w = 50;
bool timeToRoll = 1,Finished=1;
int Round = 0;
int red[4][2] = { {450,625},{550,625},{450,725},{550,725} };
int green[4][2] = { {450,175},{550,175},{450,275},{550,275} };
int yellow[4][2] = { {900,175},{1000,175},{900,275}, {1000,275} };
int blue[4][2] = { {900,625},{1000,625},{900,725},{1000,725} };

void getstartM(int x, int y, int& mx, int& my) {
    if (x >= 450 && x <= 600 && y >= 175 && y <= 325) {
        mx = 425;
        my = 400;
    }
    if (x >= 900 && x <= 1050 && y >= 175 && y <= 325) {
        mx = 775;
        my = 150;
    }
    if (x >= 450 && x <= 600 && y >= 625 && y <= 775) {
        mx = 675;
        my = 750;
    }
    if (x >= 900 && x <= 1050 && y >= 625 && y <= 775) {
        mx = 1025;
        my = 500;
    }
}

void getstart(int xc, int yc ,int P) {
	if (xc >= 450 && xc <= 500 && yc >= 175 && yc <= 225 && P==1 && !Finished){
		getstartM(xc ,yc, green[0][0], green[0][1]);
		timeToRoll = 1;
		Finished = 1;
	}
    if (xc >= 550 && xc <= 600 && yc >= 175 && yc <= 225 && P==1 && !Finished){
		getstartM(xc, yc, green[1][0], green[1][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 450 && xc <= 500 && yc >= 275 && yc <= 325 && P==1 && !Finished){
		getstartM(xc, yc, green[2][0], green[2][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 550 && xc <= 600 && yc >= 275 && yc <= 325 && P==1 && !Finished){
		getstartM(xc, yc, green[3][0], green[3][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 900 && xc <= 950 && yc >= 175 && yc <= 225 && P==2 && !Finished){
		getstartM(xc, yc, yellow[0][0], yellow[0][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 1000 && xc <= 1050 && yc >= 175 && yc <= 225 && P==2 && !Finished){
		getstartM(xc, yc, yellow[1][0], yellow[1][1]);
		timeToRoll = 1;
		Finished = 1;
	} 
    if (xc >= 900 && xc <= 950 && yc >= 275 && yc <= 325 && P==2 && !Finished){
		getstartM(xc, yc, yellow[2][0], yellow[2][1]);
		timeToRoll = 1;
		Finished = 1;
	}  
    if (xc >= 1000 && xc <= 1050 && yc >= 275 && yc <= 325 && P==2 && !Finished) {
		getstartM(xc, yc, yellow[3][0], yellow[3][1]);
		timeToRoll = 1;
		Finished = 1;
	}
    if (xc >= 900 && xc <= 950 && yc >= 625 && yc <= 675 && P==3 && !Finished){
		getstartM(xc, yc, blue[0][0], blue[0][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 1000 && xc <= 1050 && yc >= 625 && yc <= 675 && P==3 && !Finished){
		getstartM(xc, yc, blue[1][0], blue[1][1]);
		timeToRoll = 1;
		Finished = 1;
	} 
    if (xc >= 900 && xc <= 950 && yc >= 725 && yc <= 775 && P==3 && !Finished){
		getstartM(xc, yc, blue[2][0], blue[2][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 1000 && xc <= 1050 && yc >= 725 && yc <= 775 && P==3 && !Finished){
		getstartM(xc, yc, blue[3][0], blue[3][1]);
		timeToRoll = 1;
		Finished = 1;
	}  
    if (xc >= 450 && xc <= 500 && yc >= 625 && yc <= 675 && P==4 && !Finished){
		getstartM(xc, yc, red[0][0], red[0][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 550 && xc <= 600 && yc >= 625 && yc <= 675 && P==4 && !Finished){
		getstartM(xc, yc, red[1][0], red[1][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 450 && xc <= 500 && yc >= 725 && yc <= 775 && P==4 && !Finished){
		getstartM(xc, yc, red[2][0], red[2][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
    if (xc >= 550 && xc <= 600 && yc >= 725 && yc <= 775 && P==4 && !Finished){
		getstartM(xc, yc, red[3][0], red[3][1]);
		timeToRoll = 1;
		Finished = 1;
	}   
}
