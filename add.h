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


bool timeToRoll = 1, Finished = 1;
bool gstart = 0, ystart = 0, rstart = 0, bstart = 0;
int w = 50;
int nobody = 0;
int Round = 0;
int red[4][2] = { {450,625},{550,625},{450,725},{550,725} };
int green[4][2] = { {450,175},{550,175},{450,275},{550,275} };
int yellow[4][2] = { {900,175},{1000,175},{900,275}, {1000,275} };
int blue[4][2] = { {900,625},{1000,625},{900,725},{1000,725} };

int roll_dice(){
    int d;
    d= rand() %6 +1;
    return d;
}

void getstartM(int x, int y, int& mx, int& my) {
    if (x >= 450 && x <= 600 && y >= 175 && y <= 325) {
        mx = 425;
        my = 400;
        gstart = 1;
    }
    if (x >= 900 && x <= 1050 && y >= 175 && y <= 325) {
        mx = 775;
        my = 150;
        ystart = 1;
    }
    if (x >= 450 && x <= 600 && y >= 625 && y <= 775) {
        mx = 675;
        my = 750;
        rstart = 1;
    }
    if (x >= 900 && x <= 1050 && y >= 625 && y <= 775) {
        mx = 1025;
        my = 500;
        bstart = 1;
    }
}

void getstart(int xc, int yc, int P) {
    if (xc >= 450 && xc <= 500 && yc >= 175 && yc <= 225 && P == 1 && !Finished) {
        getstartM(xc, yc, green[0][0], green[0][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 550 && xc <= 600 && yc >= 175 && yc <= 225 && P == 1 && !Finished) {
        getstartM(xc, yc, green[1][0], green[1][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 450 && xc <= 500 && yc >= 275 && yc <= 325 && P == 1 && !Finished) {
        getstartM(xc, yc, green[2][0], green[2][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 550 && xc <= 600 && yc >= 275 && yc <= 325 && P == 1 && !Finished) {
        getstartM(xc, yc, green[3][0], green[3][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 900 && xc <= 950 && yc >= 175 && yc <= 225 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[0][0], yellow[0][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 1000 && xc <= 1050 && yc >= 175 && yc <= 225 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[1][0], yellow[1][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 900 && xc <= 950 && yc >= 275 && yc <= 325 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[2][0], yellow[2][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 1000 && xc <= 1050 && yc >= 275 && yc <= 325 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[3][0], yellow[3][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 900 && xc <= 950 && yc >= 625 && yc <= 675 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[0][0], blue[0][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 1000 && xc <= 1050 && yc >= 625 && yc <= 675 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[1][0], blue[1][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 900 && xc <= 950 && yc >= 725 && yc <= 775 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[2][0], blue[2][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 1000 && xc <= 1050 && yc >= 725 && yc <= 775 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[3][0], blue[3][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 450 && xc <= 500 && yc >= 625 && yc <= 675 && P == 4 && !Finished) {
        getstartM(xc, yc, red[0][0], red[0][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 550 && xc <= 600 && yc >= 625 && yc <= 675 && P == 4 && !Finished) {
        getstartM(xc, yc, red[1][0], red[1][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 450 && xc <= 500 && yc >= 725 && yc <= 775 && P == 4 && !Finished) {
        getstartM(xc, yc, red[2][0], red[2][1]);
        timeToRoll = 1;
        Finished = 1;
    }
    if (xc >= 550 && xc <= 600 && yc >= 725 && yc <= 775 && P == 4 && !Finished) {
        getstartM(xc, yc, red[3][0], red[3][1]);
        timeToRoll = 1;
        Finished = 1;
    }
}

void return_position(int& x, int& y) {
    x = x - ((x+25) % 50);
    y = y - (y % 50);
}

int* serchx(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (red[i][0] == x && red[i][1] == y) return &red[i][0];
        if (blue[i][0] == x && blue[i][1] == y) return &blue[i][0];
        if (yellow[i][0] == x && yellow[i][1] == y) return &yellow[i][0];
        if (green[i][0] == x && green[i][1] == y) return &green[i][0];
    }return &nobody;
}
int* serchy(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (red[i][0] == x && red[i][1] == y) return &red[i][1];
        if (blue[i][0] == x && blue[i][1] == y) return &blue[i][1];
        if (yellow[i][0] == x && yellow[i][1] == y) return &yellow[i][1];
        if (green[i][0] == x && green[i][1] == y) return &green[i][1];
    }return &nobody;
    
}

int move_red(int& x, int& y, int d) {
    for (int i = 0; i < d; i++) {
        if (x == 675 && y >= 600 && y <= 800) y -= w;
        else if (x == 675 && y == 550) {
            x = 625;
            y = 500;
        }
        else if (y == 500 && x >= 425 && x <= 625) x -= w;
        else if (x == 375 && y >= 450 && y <= 500) y -= w;
        else if (y == 400 && x >= 375 && x <= 575) x += w;
        else if (x == 625 && y == 400) {
            x = 675;
            y = 350;
        }
        else if (x == 675 && y >= 150 && y <= 350) y -= w;
        else if (y == 100 && x >= 675 && x <= 725) x += w;
        else if (x == 775 && y >= 100 && y <= 300) y += w;
        else if (x == 775 && y == 350) {
            x = 825;
            y = 400;
        }
        else if (y == 400 && x >= 825 && x <= 1025) x += w;
        else if (x == 1075 && y >= 400 && y <= 450) y += w;
        else if (y == 500 && x >= 875 && x <= 1075) x -= w;
        else if (x == 825 && y == 500) {
            x = 775;
            y = 550;
        }
        else if (x == 775 && y >= 550 && y <= 750) y += w;
        else if (y == 800 && x == 775) x -= w;
        else if (x == 725 && y >= 550 && y <= 750) {
            if (d != (y - 500) / w) break;
            else {
                x = 725;
                y = 500;
                Finished = 1;
                timeToRoll = 1;
                return 1;
            }
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_yellow(int& x, int& y, int d) {
    for (int i = 0; i < d; i++) {
        if (x == 775 && y >= 100 && y <= 300) y += w;
        else if (x == 775 && y == 350) {
            x = 825;
            y = 400;
        }
        else if (y == 400 && x >= 825 && x <= 1025) x += w;
        else if (x == 1075 && y >= 400 && y <= 450) y += w;
        else if (y == 500 && x >= 875 && x <= 1075) x -= w;
        else if (x == 825 && y == 500) {
            x = 775;
            y = 550;
        }
        else if (x == 775 && y >= 550 && y <= 750) y += w;
        else if (y == 800 && x >= 725 && x <= 775) x -= w;
        else if (x == 675 && y >= 600 && y <= 800) y -= w;
        else if (x == 675 && y == 550) {
            x = 625;
            y = 500;
        }
        else if (y == 500 && x >= 425 && x <= 625) x -= w;
        else if (x == 375 && y >= 450 && y <= 500) y -= w;
        else if (y == 400 && x >= 375 && x <= 575) x += w;
        else if (x == 625 && y == 400) {
            x = 675;
            y = 350;
        }
        else if (x == 675 && y >= 150 && y <= 350) y -= w;
        else if (y == 100 && x == 675) x += w;
        else if (x == 725 && y >= 150 && y <= 350)
        {
            if (d != (400 - y) / w) break;
            else {
                x = 725;
                y = 400;
                Finished = 1;
                timeToRoll = 1;
                return 1;
            }
        }

    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_blue(int& x, int& y, int dice)
{
    for (int i = 0; i < dice; i++)
    {
        if (x <= 1025 && x > 825 && y == 500)
        {
            x = x - w;
        }
        else if (x == 825 && y == 500)
        {
            x = 775;
            y = 550;
        }
        else if (y >= 550 && y < 800 && x == 775)
        {
            y = y + w;
        }
        else if (x <= 775 && x > 675 && y == 800)
        {
            x = x - w;
        }
        else if (y <= 800 && y > 550 && x == 675)
        {
            y = y - w;
        }
        else if (x == 675 && y == 550)
        {
            x = 625;
            y = 500;
        }
        else if (x <= 625 && x > 375 && y == 500)
        {
            x = x - w;
        }
        else if (y <= 500 && y > 400 && x == 375)
        {
            y = y - w;
        }
        else if (x >= 375 && x < 625 && y == 400)
        {
            x = x + w;
        }
        else if (x == 625 && y == 400)
        {
            x = 675;
            y = 350;
        }
        else if (y <= 350 && y > 100 && x == 675)
        {
            y = y - w;
        }
        else if (x >= 675 && x < 775 && y == 100)
        {
            x = x + w;
        }
        else if (y >= 100 && y < 350 && x == 775)
        {
            y = y + w;
        }
        else if (x == 775 && y == 350)
        {
            x = 825;
            y = 400;
        }
        else if (x >= 825 && x < 1075 && y == 400)
        {
            x = x + w;
        }
        else if (y >= 400 && y < 450 && x == 1075)
        {
            y = y + w;
        }
        else if (x <= 1075 && x > 775 && y == 450)
        {
            if (dice == (x - 775) / w) break;
            else {
                x = 775;
                y = 450;
                Finished = 1;
                timeToRoll = 1;
                return 1;
            }
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_green(int& x, int& y, int dice) {
    for (int i = 0; i < dice; i++)
    {
        //formatทางตรงแกน x ทิศขวา --> if(x >= ต้น && x < ปลาย && y == คงที่)
        if (x >= 425 && x < 625 && y == 400)
        {
            x = x + w;
        }
        //จุดกระโดด 1
        else if (x == 625 && y == 400)
        {
            x = 675;
            y = 350;
        }
        //formatทางตรงแกน y ทิศขึ้น --> if(y <= ต้น && y > ปลาย && x == คงที่)
        else if (y <= 350 && y > 100 && x == 675)
        {
            y = y - w;
        }
        else if (x >= 675 && x < 775 && y == 100)
        {
            x = x + w;
        }
        //formatทางตรงแกน y ทิศลง --> if(y >= ต้น && y < ปลาย && x == คงที่)
        else if (y >= 100 && y < 350 && x == 775)
        {
            y = y + w;
        }
        //จุดกระโดด 2
        else if (x == 775 && y == 350)
        {
            x = 825;
            y = 400;
        }
        else if (x >= 825 && x < 1075 && y == 400)
        {
            x = x + w;
        }
        else if (y >= 400 && y < 500 && x == 1075)
        {
            y = y + w;
        }
        //formatทางตรงแกน x ทิศซ้าย --> if(x <= ต้น && x > ปลาย && y == คงที่)
        else if (x <= 1075 && x > 825 && y == 500)
        {
            x = x - w;
        }
        //จุดกระโดด 3
        else if (x == 825 && y == 500)
        {
            x = 775;
            y = 550;
        }
        else if (y >= 550 && y < 800 && x == 775)
        {
            y = y + w;
        }
        else if (x <= 775 && x > 675 && y == 800)
        {
            x = x - w;
        }
        else if (y <= 800 && y > 550 && x == 675)
        {
            y = y - w;
        }
        //จุดกระโดด 4
        else if (x == 675 && y == 550)
        {
            x = 625;
            y = 500;
        }
        else if (x <= 625 && x > 375 && y == 500)
        {
            x = x - w;
        }
        else if (y <= 500 && y > 450 && x == 375)
        {
            y = y - w;
        }
        //เลนที่กำลังจะถึงเส้นชัย
        else if (x >= 375 && x < 675 && y == 450)
        {
            if (dice != (675 - x) / w) break;
            else {
                x = 675;
                y = 450;
                Finished = 1;
                timeToRoll = 1;
                return 1;
            }

        }

    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}
