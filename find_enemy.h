//prototype
void find_enemy_red(int &,int &);
void find_enemy_yellow(int &,int &);
void find_enemy_blue(int &,int &);
void find_enemy_green(int &,int &);
//function
void find_enemy_red(int &x,int &y) //function ตรวจสอบว่ามีศัตรูอญู่ ณ ตำแหน่งนั้นมั้ย โดยมีการรับค่า (xปัจจุบัน,yปัจจุบัน)
{
    //check red eat green?
    for(int i=0;i<4;i++) //หาตำเเหน่งของgreenทั้งหมดว่าตอนนี้อยู่ตรงไหน
    {
        int yr,j=0;
        int xr=*&green[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&green[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ green[i][j] กลับจุดเกิด "ตรงนี้ยังคิดไม่ออก"
        }
    } 
    //check red eat yellow?
    for(int i=0;i<4;i++) //หาตำเเหน่งของyellowทั้งหมดว่าตอนนี้อยู่ตรงไหน(x,y)
    {
        int yr,j=0;
        int xr=*&yellow[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&yellow[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check red eat blue?
    for(int i=0;i<4;i++) //หาตำเเหน่งของ blueทั้งหมดว่าตอนนี้อยู่ตรงไหน(x,y)
    {
        int yr,j=0;
        int xr=*&blue[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&blue[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_yellow(int &x,int &y)
{
    //check yellow eat green?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&green[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&green[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ green[i][j] กลับจุดเกิด
        }
    } 
    //check yellow eat red?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&red[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&red[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ red[i][j] กลับจุดเกิด
        }
    }
    //check yellow eat blue?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&blue[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&blue[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_blue(int &x,int &y)
{
    //check blue eat green?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&green[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&green[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ green[i][j] กลับจุดเกิด
        }
    } 
    //check blue eat yellow?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&yellow[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&yellow[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check blue eat red?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&red[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&red[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ red[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_green(int &x,int &y)
{
    //check green eat red?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&red[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&red[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ red[i][j] กลับจุดเกิด "ตรงนี้ยังคิดไม่ออก"
        }
    } 
    //check green eat yellow?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&yellow[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&yellow[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check green eat blue?
    for(int i=0;i<4;i++)
    {
        int yr,j=0;
        int xr=*&blue[i][j];
        for(int j=1;j<2;j++)
        {
            yr=*&blue[i][j];

        }
        if(x==xr and y==yr)
        {
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}
