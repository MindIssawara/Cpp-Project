#include "add.h"
using namespace std;

//prototype
void find_enemy_red(int &,int &);
void find_enemy_yellow(int &,int &);
void find_enemy_blue(int &,int &);
void find_enemy_green(int &,int &);

//function
void find_enemy_red(int &x,int &y) //function ตรวจสอบว่ามีศัตรูอญู่ ณ ตำแหน่งนั้นมั้ย โดยมีการรับค่า (xปัจจุบัน,yปัจจุบัน)
{
    //check red eat green?
    for(int i=0;i<4;i++) //หาตำเเหน่งของgreenทั้งหมดว่าตอนนี้อยู่ตรงไหน(x,y)
    {
        int xr=*&green[i][0];
        int yr=*&green[i][1];
        
        if(x==xr and y==yr)
        {
            if(i == 0){
                x = 450;
                y = 175;
            }else if(i == 1){
                x = 550;
                y = 175;
            }else if(i == 2){
                x = 450;
                y = 275;
            }else if(i == 3){
                x = 550;
                y = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }
    } 
    //check red eat yellow?
    for(int i=0;i<4;i++) //หาตำเเหน่งของyellowทั้งหมดว่าตอนนี้อยู่ตรงไหน(x,y)
    {
        int xr=*&yellow[i][0];
        int yr=*&yellow[i][1];
        
        if(x==xr and y==yr)
        {
            if(i == 0){
                x = 900;
                y = 175;
            }else if(i == 1){
                x = 1000;
                y = 175;
            }else if(i == 2){
                x = 900;
                y = 275;
            }else if(i == 3){
                x = 1000;
                y = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check red eat blue?
    for(int i=0;i<4;i++) //หาตำเเหน่งของ blueทั้งหมดว่าตอนนี้อยู่ตรงไหน(x,y)
    {
        int xr=*&blue[i][0];
        int yr=*&blue[i][1];
        
        if(x==xr and y==yr)
        {
            if(i == 0){
                x = 900;
                y = 625;
            }else if(i == 1){
                x = 1000;
                y = 625;
            }else if(i == 2){
                x = 900;
                y = 725;
            }else if(i == 3){
                x = 1000;
                y = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_yellow(int &x,int &y)
{
    //check yellow eat green?
    for(int i=0;i<4;i++)
    {
        int xy=*&green[i][0];
        int yy=*&green[i][1];
        
        if(x==xy and y==yy)
        {
            if(i == 0){
                x = 450;
                y = 175;
            }else if(i == 1){
                x = 550;
                y = 175;
            }else if(i == 2){
                x = 450;
                y = 275;
            }else if(i == 3){
                x = 550;
                y = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }
    } 
    //check yellow eat red?
    for(int i=0;i<4;i++)
    {
        int xy=*&red[i][0];
        int yy=*&red[i][1];
        
        if(x==xy and y==yy)
        {
            if(i == 0){
                x = 450;
                y = 625;
            }else if(i == 1){
                x = 550;
                y = 625;
            }else if(i == 2){
                x = 450;
                y = 725;
            }else if(i == 3){
                x = 550;
                y = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }
    }
    //check yellow eat blue?
    for(int i=0;i<4;i++)
    {
        int xy=*&blue[i][0];
        int yy=*&blue[i][1];

        if(x==xy and y==yy)
        {
            if(i == 0){
                x = 900;
                y = 625;
            }else if(i == 1){
                x = 1000;
                y = 625;
            }else if(i == 2){
                x = 900;
                y = 725;
            }else if(i == 3){
                x = 1000;
                y = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_blue(int &x,int &y)
{
    //check blue eat green?
    for(int i=0;i<4;i++)
    {
        int xb=*&green[i][0];
        int yb=*&green[i][1];
        
        if(x==xb and y==yb)
        {
            if(i == 0){
                x = 450;
                y = 175;
            }else if(i == 1){
                x = 550;
                y = 175;
            }else if(i == 2){
                x = 450;
                y = 275;
            }else if(i == 3){
                x = 550;
                y = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }
    } 
    //check blue eat yellow?
    for(int i=0;i<4;i++)
    {
        int xb=*&yellow[i][0];
        int yb=*&yellow[i][1];
        
        if(x==xb and y==yb)
        {
            if(i == 0){
                x = 900;
                y = 175;
            }else if(i == 1){
                x = 1000;
                y = 175;
            }else if(i == 2){
                x = 900;
                y = 275;
            }else if(i == 3){
                x = 1000;
                y = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check blue eat red?
    for(int i=0;i<4;i++)
    {
        int xb=*&red[i][0];
        int yb=*&red[i][1];
        
        if(x==xb and y==yb)
        {
            if(i == 0){
                x = 450;
                y = 625;
            }else if(i == 1){
                x = 550;
                y = 625;
            }else if(i == 2){
                x = 450;
                y = 725;
            }else if(i == 3){
                x = 550;
                y = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_green(int &x,int &y)
{
    //check green eat red?
    for(int i=0;i<4;i++)
    {
        int xg=*&red[i][0];
        int yg=*&red[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                x = 450;
                y = 625;
            }else if(i == 1){
                x = 550;
                y = 625;
            }else if(i == 2){
                x = 450;
                y = 725;
            }else if(i == 3){
                x = 550;
                y = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }
    } 
    //check green eat yellow?
    for(int i=0;i<4;i++)
    {
        int xg=*&yellow[i][0];
        int yg=*&yellow[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                x = 900;
                y = 175;
            }else if(i == 1){
                x = 1000;
                y = 175;
            }else if(i == 2){
                x = 900;
                y = 275;
            }else if(i == 3){
                x = 1000;
                y = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }
    }
    //check green eat blue?
    for(int i=0;i<4;i++)
    {
        int xg=*&blue[i][0];
        int yg=*&blue[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                x = 900;
                y = 625;
            }else if(i == 1){
                x = 1000;
                y = 625;
            }else if(i == 2){
                x = 900;
                y = 725;
            }else if(i == 3){
                x = 1000;
                y = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}
