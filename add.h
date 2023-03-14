#include <SFML/Graphics.hpp> //ไลบารี่หลักในการทำGui
#include<iostream>//ไว้ test cout ออกมา
#include<time.h>//ไว้ใช้สุ่ม
#include <windows.h> //ไว้ใส่เสียง
#include<chrono> //ไว้ทำดีเลย์
#include<thread> //ไว้ทำดีเลย์
#include<set> //มีไว้skip turn
#pragma comment(lib, "winmm.lib") //ใช้ทำเสียง
using namespace std::this_thread;
using namespace std::chrono;
using namespace std;
using namespace sf;

bool timeToRoll = 0, Finished = 1; //boolenเพื่อเช็คสถานะการทำงาน
bool six = 0;//ใช้เพื่อนับว่าทอยได้ 6 ไหม
bool can = 1;//ใช้เพื่อเช็คว่าหมากยังเดินต่อได้ไหมหรือskip turn
int pick[4] = { 0,0,0,0 };//นับว่ามีหมากอยู่กี่ตัวบนกระดาน
int in_start[4] = { 4,4,4,4 };//นับว่ามีหมากอยู่กี่ตัวบนฐาน
int w = 50;//ขนาดช่องทางเดิน
//nobody[0]ใช้เพื่อเช็คว่าไม่มีตัวไหนในช่องนี้ แต่nobody[1]ถึงnobody[4]คือตัวแปรเพื่อใช้ในการแสดงผลภาพหมากซ้อนกันกี่ตัวๆ 0คือ1ตัวเนื่องจากเริ่มภาพที่พิเซสที่0 ไล่ไปถึง 3ซึ่งคือซ้อนกัน4ตัว
int nobody[5] = { 0,0,1,2,3 }, * picCount = &nobody[0];//picCountเป็นตัวแปรพ็อตเตอร์ที่ชี้ไปnobody เพื่อใช้ในserch
int Round = 0; //นับว่าตาสีอะไร
int red[4][2] = { {450,625},{550,625},{450,725},{550,725} }; //ค่าตำแหน่งของหมากสีตัวที่ 1 2 3 4 ค่าตำแหน่ง x y ของแต่ละตัวเมื่อเริ่มเกม
int green[4][2] = { {450,175},{550,175},{450,275},{550,275} };
int yellow[4][2] = { {900,175},{1000,175},{900,275}, {1000,275} };
int blue[4][2] = { {900,625},{1000,625},{900,725},{1000,725} };
int xc = 0, yc = 0;//รับค่าตำแหน่งตอนกดเมาส์
//win[]มีไว้เก็บค่าว่าหมากเข้าไปแล้วกี่ตัว
int win[4] = { 0,0,0,0 },num[4] = { 0,0,0,0 };//รับค่าว่าหมากเดินเข้าไปในเส้นชัยหรือไม่
int page = 1; //ใช้กำกับว่าขณะนี้เปิดหน้าไหนอยู่ เช่น หน้าเกม หน้าโฮม หน้าชนะ หน้าฮาวทู
int Roll = 1; //แต้มที่ทอยได้
//wait คือรอดีเลย์หรือไม่ muteornotคือสั่งปิดเสียงรึป่าว mutepressedคือปุ่มปิดเปิดเสียงถูกกดมั้ย Gotwinnerคือได้ผู้ชนะรึยัง
bool wait = 0, muteornot = 0, mutepressed = 0, GotWinner = 0;
set<int*> Ggoal, Ygoal, Bgoal, Rgoal;//ใช้เพื่อเก็บค่าว่ามีหมากตัวไหนบ้างอยู่ในเลนเส้นชัย

//ฟังก์ชั่นเล่นเสียง
void playSound(int x = 1) {
    if (x == 0) PlaySound(TEXT("audio/click.wav"), NULL, SND_FILENAME | SND_ASYNC);//เล่นเสียงตึ้ดด1ครั้งว่าปิดเสียงครั้งเดียวจบ 
    if (x == 1) PlaySound(TEXT("audio/Wallpaper.wav"), NULL, SND_LOOP | SND_ASYNC);//เล่นเพลงคลอเกมแบบลูป
    if (x == 2) PlaySound(TEXT("audio/winner.wav"), NULL, SND_FILENAME | SND_ASYNC);//เสียงหน้าชนะเล่นครั้งเดียวจบ
}

//ทอยเต๋า รีเทิร์นเป็นแต้มที่ทอยได้
int roll_dice() {
    int d;
    d = rand() % 6 + 1;
    return d;
}

//getstartMove เป็นฟังก์ชั่นที่ถูกเรียกใช้ในgetstart มีไว้เพื่อเรียกหมากออกมาอยู่บนรางเดินจุดเริ่มต้น ซึ่งแต่ละสีเริ่มที่จุดต่างกัน
void getstartM(int x, int y, int& mx, int& my) {
    //เช็คว่าเป็นสีอะไร ด้วยค่า position ที่คลิกมา
    if (x >= 450 && x <= 600 && y >= 175 && y <= 325) {
        mx = 425; //จุดเริ่มต้นสีเขียว
        my = 400;
        in_start[0] -= 1;//หมากจากฐานลดลง
        pick[0] += 1;//ตัวบนกระดานเพิ่มขึ้น
        // green
    }
    if (x >= 900 && x <= 1050 && y >= 175 && y <= 325) {
        mx = 775;//จุดเริ่มต้นสีเหลือง
        my = 150;
        in_start[1] -= 1;
        pick[1] += 1;
        //yellow
    }
    if (x >= 900 && x <= 1050 && y >= 625 && y <= 775) {
        mx = 1025;//จุดเริ่มต้นสีฟ้า
        my = 500;
        in_start[2] -= 1;
        pick[2] += 1;
        //blue
    }
    if (x >= 450 && x <= 600 && y >= 625 && y <= 775) {
        mx = 675;//จุดเริ่มต้นสีแดง
        my = 750;
        in_start[3] -= 1;
        pick[3] += 1;
        //red
    }
}

//โค้ดเมื่อเลือกหมากจากฐานไปจุดเริ่มต้นบนราง
void getstart(int& xc, int& yc, int P) {
    //หมากเขียวตัวที่ 1 โดย xc yc คือค่า x y ตำแหน่งที่เมาส์คลิกลงไปบนหน้าต่างแสดงผล ในifคือช่วงค่าที่เป็นพื้นที่ของหมากเขียวตัวที่1 ส่วนFinishedคือเช็คว่ากระทำในขั้นตอนนี้เสร็จรึยัง
    if (xc >= 450 && xc <= 500 && yc >= 175 && yc <= 225 && P == 1 && !Finished) {
        getstartM(xc, yc, green[0][0], green[0][1]);//เรียกใช้moveไปจุดเริ่มต้นบนราง
        xc = green[0][0], yc = green[0][1];//นำค่าไปใช้ต่อในchase_back
        timeToRoll = 1; //เปลี่ยนสถานะการทอยเต๋าว่าทอยได้
        Finished = 1; //กระทำขั้นนี้เสร็จแล้ว
    }
    //หมากเขียวตัวที่ 2
    if (xc >= 550 && xc <= 600 && yc >= 175 && yc <= 225 && P == 1 && !Finished) {
        getstartM(xc, yc, green[1][0], green[1][1]);
        xc = green[1][0], yc = green[1][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเขียวตัวที่ 3
    if (xc >= 450 && xc <= 500 && yc >= 275 && yc <= 325 && P == 1 && !Finished) {
        getstartM(xc, yc, green[2][0], green[2][1]);
        xc = green[2][0], yc = green[2][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเขียวตัวที่ 4
    if (xc >= 550 && xc <= 600 && yc >= 275 && yc <= 325 && P == 1 && !Finished) {
        getstartM(xc, yc, green[3][0], green[3][1]);
        xc = green[3][0], yc = green[3][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเหลืองตัวที่ 1
    if (xc >= 900 && xc <= 950 && yc >= 175 && yc <= 225 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[0][0], yellow[0][1]);
        xc = yellow[0][0], yc = yellow[0][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเหลืองตัวที่ 2
    if (xc >= 1000 && xc <= 1050 && yc >= 175 && yc <= 225 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[1][0], yellow[1][1]);
        xc = yellow[1][0], yc = yellow[1][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเหลืองตัวที่ 3
    if (xc >= 900 && xc <= 950 && yc >= 275 && yc <= 325 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[2][0], yellow[2][1]);
        xc = yellow[2][0], yc = yellow[2][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากเหลืองตัวที่ 4
    if (xc >= 1000 && xc <= 1050 && yc >= 275 && yc <= 325 && P == 2 && !Finished) {
        getstartM(xc, yc, yellow[3][0], yellow[3][1]);
        xc = yellow[3][0], yc = yellow[3][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากฟ้าตัวที่ 1
    if (xc >= 900 && xc <= 950 && yc >= 625 && yc <= 675 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[0][0], blue[0][1]);
        xc = blue[0][0], yc = blue[0][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากฟ้าตัวที่ 2
    if (xc >= 1000 && xc <= 1050 && yc >= 625 && yc <= 675 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[1][0], blue[1][1]);
        xc = blue[1][0], yc = blue[1][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากฟ้าตัวที่ 3
    if (xc >= 900 && xc <= 950 && yc >= 725 && yc <= 775 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[2][0], blue[2][1]);
        xc = blue[2][0], yc = blue[2][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากฟ้าตัวที่ 4
    if (xc >= 1000 && xc <= 1050 && yc >= 725 && yc <= 775 && P == 3 && !Finished) {
        getstartM(xc, yc, blue[3][0], blue[3][1]);
        xc = blue[3][0], yc = blue[3][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากแดงตัวที่ 1
    if (xc >= 450 && xc <= 500 && yc >= 625 && yc <= 675 && P == 4 && !Finished) {
        getstartM(xc, yc, red[0][0], red[0][1]);
        xc = red[0][0], yc = red[0][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากแดงตัวที่ 2
    if (xc >= 550 && xc <= 600 && yc >= 625 && yc <= 675 && P == 4 && !Finished) {
        getstartM(xc, yc, red[1][0], red[1][1]);
        xc = red[1][0], yc = red[1][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากแดงตัวที่ 3
    if (xc >= 450 && xc <= 500 && yc >= 725 && yc <= 775 && P == 4 && !Finished) {
        getstartM(xc, yc, red[2][0], red[2][1]);
        xc = red[2][0], yc = red[2][1];
        timeToRoll = 1;
        Finished = 1;
    }
    //หมากแดงตัวที่ 4
    if (xc >= 550 && xc <= 600 && yc >= 725 && yc <= 775 && P == 4 && !Finished) {
        getstartM(xc, yc, red[3][0], red[3][1]);
        xc = red[3][0], yc = red[3][1];
        timeToRoll = 1;
        Finished = 1;
    }
}

//เป็นฟังก์ชั่นที่รีเทิร์นว่าที่ที่เราคลิกไปคือตำแหน่งจริงๆของหมากตรงไหน เนื่องจากค่าตำแหน่งต่างๆที่หมากอยู่จะเป็นมุมบนซ้าย จึงต้องใช้ฟังก์ชั่นนี้เพื่อหาตำแหน่งจริงๆของหมากที่คลิก
//ใช้ & เพื่อเปลี่ยนค่า x y ที่คลิกไปที่มุมซ้ายบนของช่องที่คลิกลงไป ช่องขนาด50*50
void return_position(int& x, int& y) {
    x = x - ((x + 25) % 50); //%50เนื่องจากช่องมีขนาด50*50 +25เกิดจากบริเวณที่เริ่มดู x%50=25
    y = y - (y % 50); //ช่อง50*50
}

//เป็นฟังก์ชั่นพ็อตเตอร์เพราะต้องการค่าrefของตำแหน่งที่เก็บไว้ในarrayเพื่อใช้ในการเปลี่ยนค่าตำแหน่งให้ตำแหน่งหมากขยับ
//*serchxใช้ในการหาพวก(สี)เดียวกันด้วยในการวาดภาพซ้อนกัน
int* searchx(int x, int y, int Round = 0, bool pic = false) {
    int count = 0; //นับสีเดียวกัน ณ ตำแหน่งใดๆว่ามรกี่ตัว
    for (int i = 0; i < 4; i++) {
        //Round==0 คือ move ปกติ ส่วน 1,2,3,4 คือรอบเพื่อใช้ในการไล่หมากสีอื่นที่หมากเดินไปทับกลับ
        //picคืออันนี้คือหาตำแหน่งเพื่อวาดรูป
        if (!pic) {
            if (red[i][0] == x && red[i][1] == y && Round != 4) return &red[i][0];
            if (blue[i][0] == x && blue[i][1] == y && Round != 3) return &blue[i][0];
            if (yellow[i][0] == x && yellow[i][1] == y && Round != 2) return &yellow[i][0];
            if (green[i][0] == x && green[i][1] == y && Round != 1) return &green[i][0];
        }
        else {
            //นับหมากสีเดียวกัน
            if (red[i][0] == x && red[i][1] == y && Round == 4) count++;
            if (blue[i][0] == x && blue[i][1] == y && Round == 3) count++;
            if (yellow[i][0] == x && yellow[i][1] == y && Round == 2) count++;
            if (green[i][0] == x && green[i][1] == y && Round == 1) count++;
        }
    }
    return &nobody[count]; //ส่ง&ของช่องที่เก็บแต่ละค่าในarray เนื่องจากเป็นฟังก์ชั่นพ็อตเตอร์
}
//คล้ายๆsearchx แต่ไม่ใช้ในการหาทีมเดียวกัน
int* searchy(int x, int y, int Round = 0) {
    for (int i = 0; i < 4; i++) {
        if (red[i][0] == x && red[i][1] == y && Round != 4) return &red[i][1];
        if (blue[i][0] == x && blue[i][1] == y && Round != 3) return &blue[i][1];
        if (yellow[i][0] == x && yellow[i][1] == y && Round != 2) return &yellow[i][1];
        if (green[i][0] == x && green[i][1] == y && Round != 1) return &green[i][1];
    }
    return &nobody[0];
}


void chase_back(int* px, int* py) {//รับค่าเป็นaddressของหมากที่ต้องการจะไล่กลับฐาน
    if (px == &green[0][0] && py == &green[0][1]) {//หมากสีเขียวตัวที่ 1
        *px = 450;//เปลี่ยนค่าตำแหน่งของหมากเป็นจุดที่ฐาน
        *py = 175;
        pick[0] -= 1;//หมากบนกระดานลดลง
        in_start[0] += 1;//หมากที่จุดเริ่มเพิ่มขึ้น
    }
    if (px == &green[1][0] && py == &green[1][1]) {//หมากสีเขียวตัวที่ 2
        *px = 550;
        *py = 175;
        pick[0] -= 1;
        in_start[0] += 1;
    }
    if (px == &green[2][0] && py == &green[2][1]) {//หมากสีเขียวตัวที่ 3
        *px = 450;
        *py = 275;
        pick[0] -= 1;
        in_start[0] += 1;
    }
    if (px == &green[3][0] && py == &green[3][1]) {//หมากสีเขียวตัวที่ 4
        *px = 550;
        *py = 275;
        pick[0] -= 1;
        in_start[0] += 1;
    }
    if (px == &yellow[0][0] && py == &yellow[0][1]) {//หมากสีเหลืองตัวที่ 1
        *px = 900;
        *py = 175;
        pick[1] -= 1;
        in_start[1] += 1;
    }
    if (px == &yellow[1][0] && py == &yellow[1][1]) {//หมากสีเหลืองตัวที่ 2
        *px = 1000;
        *py = 175;
        pick[1] -= 1;
        in_start[1] += 1;
    }
    if (px == &yellow[2][0] && py == &yellow[2][1]) {//หมากสีเหลืองตัวที่ 3
        *px = 900;
        *py = 275;
        pick[1] -= 1;
        in_start[1] += 1;
    }
    if (px == &yellow[3][0] && py == &yellow[3][1]) {//หมากสีเหลืองตัวที่ 4
        *px = 1000;
        *py = 275;
        pick[1] -= 1;
        in_start[1] += 1;
    }
    if (px == &blue[0][0] && py == &blue[0][1]) {//หมากสีฟ้ตัวที่ 1
        *px = 900;
        *py = 625;
        pick[2] -= 1;
        in_start[2] += 1;
    }
    if (px == &blue[1][0] && py == &blue[1][1]) {//หมากสีฟ้าตัวที่ 2
        *px = 1000;
        *py = 625;
        pick[2] -= 1;
        in_start[2] += 1;
    }
    if (px == &blue[2][0] && py == &blue[2][1]) {//หมากสีฟ้าตัวที่ 3
        *px = 900;
        *py = 725;
        pick[2] -= 1;
        in_start[2] += 1;
    }
    if (px == &blue[3][0] && py == &blue[3][1]) {//หมากสีฟ้าตัวที่ 4
        *px = 1000;
        *py = 725;
        pick[2] -= 1;
        in_start[2] += 1;
    }
    if (px == &red[0][0] && py == &red[0][1]) {//หมากสีแดงตัวที่ 1
        *px = 450;
        *py = 625;
        pick[3] -= 1;
        in_start[3] += 1;
    }
    if (px == &red[1][0] && py == &red[1][1]) {//หมากสีแดงตัวที่ 2
        *px = 550;
        *py = 625;
        pick[3] -= 1;
        in_start[3] += 1;
    }
    if (px == &red[2][0] && py == &red[2][1]) {//หมากสีแดงตัวที่ 3
        *px = 450;
        *py = 725;
        pick[3] -= 1;
        in_start[3] += 1;
    }
    if (px == &red[3][0] && py == &red[3][1]) {//หมากสีแดงตัวที่ 4
        *px = 550;
        *py = 725;
        pick[3] -= 1;
        in_start[3] += 1;
    }
}

int move_red(int& x, int& y, int d) {
    if (x == 725 && y > 500 && y <= 800) {
        if (d <= (y - 500) / w) {
            y -= (d * w);
        }
        if (x == 725 && y == 500) {
            Finished = 1;
            timeToRoll = 1;
            return 1;
        }

    }
    else for (int i = 0; i < d; i++) {
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
        else if (y == 800 && x == 725) y -= w;
        else if (x == 725 && y >= 500 && y <= 750) {
            y -= w;

        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_yellow(int& x, int& y, int d) {
    if (x == 725 && y >= 100 && y < 400) {
        if (d <= (400 - y) / w) {
            y += (d * w);
        }
        if (x == 725 && y == 400) {
            Finished = 1;
            timeToRoll = 1;
            return 1;
        }

    }
    else for (int i = 0; i < d; i++) {
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
        else if (y == 100 && x == 725) y += w;
        else if (x == 725 && y >= 150 && y <= 400) {
            y += w;

        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_blue(int& x, int& y, int dice)
{
    if (x <= 1075 && x > 775 && y == 450) {
        if (dice <= (x - 775) / w) {
            x -= (dice * w);
        }
        if (x == 775 && y == 450) {
            Finished = 1;
            timeToRoll = 1;
            return 1;
        }

    }
    else for (int i = 0; i < dice; i++)
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
            x -= w;
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_green(int& x, int& y, int dice) {
    if (x >= 375 && x < 675 && y == 450) {
        if (dice <= (675 - x) / w) {
            x += (dice * w);
        }
        if (x == 675 && y == 450) {
            Finished = 1;
            timeToRoll = 1;
            return 1;
        }

    }
    else for (int i = 0; i < dice; i++)
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
            x += w;

        }

    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

//การทำรีเซตรับค่ามาถ้า 0 คือหน้าเกม ถ้า1คือหน้าโฮม
void ResetAll(int Reset = 0) {
    //เซ็ตทุกอย่างไว้ค่าเริ่มต้น
    timeToRoll = 0;
    Finished = 1;
    six = 0; can = 1;
    pick[0] = 0; pick[1] = 0; pick[2] = 0; pick[3] = 0;
    in_start[0] = 4; in_start[1] = 4; in_start[2] = 4; in_start[3] = 4;
    picCount = &nobody[0];
    Round = 0;
    red[0][0] = 450; red[0][1] = 625;
    red[1][0] = 550; red[1][1] = 625;
    red[2][0] = 450; red[2][1] = 725;
    red[3][0] = 550; red[3][1] = 725;
    green[0][0] = 450; green[0][1] = 175;
    green[1][0] = 550; green[1][1] = 175;
    green[2][0] = 450; green[2][1] = 275;
    green[3][0] = 550; green[3][1] = 275;
    yellow[0][0] = 900; yellow[0][1] = 175;
    yellow[1][0] = 1000; yellow[1][1] = 175;
    yellow[2][0] = 900; yellow[2][1] = 275;
    yellow[3][0] = 1000; yellow[3][1] = 275;
    blue[0][0] = 900;  blue[0][1] = 625;
    blue[1][0] = 1000;  blue[1][1] = 625;
    blue[2][0] = 900;  blue[2][1] = 725;
    blue[3][0] = 1000;  blue[3][1] = 725;
    xc = 0; yc = 0;
    win[0] = 0; win[1] = 0; win[2] = 0; win[3] = 0;
    num[0] = 0; num[1] = 0; num[2] = 0; num[3] = 0;
    Ggoal.clear(); Ygoal.clear(); Bgoal.clear(); Rgoal.clear();
    page = Reset; //เปลี่ยนสถานะหน้าด้วยค่าที่รับมา
    Roll = 1;
    //เฉพาะเมื่อไปหน้าโฮม
    if (Reset == 1) {
        wait = 0;
        muteornot = 0;
        mutepressed = 0;
        GotWinner = 0;
        playSound(1);
    }
}
