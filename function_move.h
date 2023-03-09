// global variable need 
// - x,y เส้นชัย
// - ระยะเดิน
const int w =50;

// red ==1 / yellow ==2 / blue ==3 / green ==4

//prototype
int move_red(int &,int &,int);
int move_yellow(int &,int &,int);

int move_blue(int &,int &,int);
int move_green(int &,int &,int);
//ฟังชั่นจะpass by refค่าx,yปัจจุบันของหมากสีใครสีมันและค่าลูกเต๋าที่ทอยได้แล้วก็เอามาเดิน ถ้าปรากฏว่าถึงเส้นชัยจะreturnค่าint = 1 แต่ถ้ายังไม่ถึงเส้นชัยจะreturnค่าเป็น0


//function
int move_red(int& x, int& y, int d) {
    if (x == 725 && y >= 500 && y <= 750) {
        if (d <= (y-500) / w) {
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
            if (d <= (y-500) / w) {
                y -= w;
            }
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_yellow(int& x, int& y, int d) {
    if (x == 725 && y >= 150 && y <= 400) {
            if (d <= (400 - y) / w) {
                y += (d*w);
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
            if (d <= (400 - y) / w) {
                y += w;
            }
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_blue(int& x, int& y, int dice)
{
    if (x <= 1075 && x > 775 && y == 450) {
        if (dice <= (x-775) / w) {
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
            if (dice <= (x - 775) / w) x -= w;
        }
    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}

int move_green(int& x, int& y, int dice) {
    if (x >= 375 && x < 675 && y == 450) {
        if (dice <= (675-x) / w) {
            x += (dice * w);
        }
        if (x == 775 && y == 450) {
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
            if (dice <= (675 - x) / w) x+=w;

        }

    }
    Finished = 1;
    timeToRoll = 1;
    return 0;
}
