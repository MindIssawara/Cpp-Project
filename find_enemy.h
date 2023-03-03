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
    //check red eat others?
    for(int i=0;i<4;i++)
    {
        int xg=green[i][0];
        int yg=green[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                green[i][0] = 450;
                green[i][1] = 175;
            }else if(i == 1){
                green[i][0] = 550;
                green[i][1] = 175;
            }else if(i == 2){
                green[i][0] = 450;
                green[i][1] = 275;
            }else if(i == 3){
                green[i][0] = 550;
                green[i][1] = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }

        int xy=yellow[i][0];
        int yy=yellow[i][1];
        
        if(x==xy and y==yy)
        {
            if(i == 0){
                yellow[i][0] = 900;
                yellow[i][1] = 175;
            }else if(i == 1){
                yellow[i][0] = 1000;
                yellow[i][1] = 175;
            }else if(i == 2){
                yellow[i][0] = 900;
                yellow[i][1] = 275;
            }else if(i == 3){
                yellow[i][0] = 1000;
                yellow[i][1] = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }

        int xb=blue[i][0];
        int yb=blue[i][1];
        
        if(x==xb and y==yb)
        {
            if(i == 0){
                blue[i][0] = 900;
                blue[i][1] = 625;
            }else if(i == 1){
                blue[i][0] = 1000;
                blue[i][1] = 625;
            }else if(i == 2){
                blue[i][0] = 900;
                blue[i][1] = 725;
            }else if(i == 3){
                blue[i][0] = 1000;
                blue[i][1] = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
    
}

void find_enemy_yellow(int &x,int &y)
{
    //check yellow eat others?
    for(int i=0;i<4;i++)
    {
        int xg=green[i][0];
        int yg=green[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                green[i][0] = 450;
                green[i][1] = 175;
            }else if(i == 1){
                green[i][0] = 550;
                green[i][1] = 175;
            }else if(i == 2){
                green[i][0] = 450;
                green[i][1] = 275;
            }else if(i == 3){
                green[i][0] = 550;
                green[i][1] = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }

        int xr=red[i][0];
        int yr=red[i][1];
        
        if(x==xr and y==yr)
        {
            if(i == 0){
                red[i][0] = 450;
                red[i][1] = 625;
            }else if(i == 1){
                red[i][0] = 550;
                red[i][1] = 625;
            }else if(i == 2){
                red[i][0] = 450;
                red[i][1] = 725;
            }else if(i == 3){
                red[i][0] = 550;
                red[i][1] = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }

        int xb=blue[i][0];
        int yb=blue[i][1];

        if(x==xb and y==yb)
        {
            if(i == 0){
                blue[i][0] = 900;
                blue[i][1] = 625;
            }else if(i == 1){
                blue[i][0] = 1000;
                blue[i][1] = 625;
            }else if(i == 2){
                blue[i][0] = 900;
                blue[i][1] = 725;
            }else if(i == 3){
                blue[i][0] = 1000;
                blue[i][1] = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
}

void find_enemy_blue(int &x,int &y)
{
    //check blue eat others?
    for(int i=0;i<4;i++)
    {
        int xg=green[i][0];
        int yg=green[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                green[i][0] = 450;
                green[i][1] = 175;
            }else if(i == 1){
                green[i][0] = 550;
                green[i][1] = 175;
            }else if(i == 2){
                green[i][0] = 450;
                green[i][1] = 275;
            }else if(i == 3){
                green[i][0] = 550;
                green[i][1] = 275;
            }
            //ให้ green[i][j] กลับจุดเกิด
        }

        int xy=yellow[i][0];
        int yy=yellow[i][1];
        
        if(x==xy and y==yy)
        {
            if(i == 0){
                yellow[i][0] = 900;
                yellow[i][1] = 175;
            }else if(i == 1){
                yellow[i][0] = 1000;
                yellow[i][1] = 175;
            }else if(i == 2){
                yellow[i][0] = 900;
                yellow[i][1] = 275;
            }else if(i == 3){
                yellow[i][0] = 1000;
                yellow[i][1] = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }

        int xr=red[i][0];
        int yr=red[i][1];
        
        if(x==xr and y==yr)
        {
            if(i == 0){
                red[i][0] = 450;
                red[i][1] = 625;
            }else if(i == 1){
                red[i][0] = 550;
                red[i][1] = 625;
            }else if(i == 2){
                red[i][0] = 450;
                red[i][1] = 725;
            }else if(i == 3){
                red[i][0] = 550;
                red[i][1] = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }
    } 

}

void find_enemy_green(int &x,int &y)
{
    //check green eat others?
    for(int i=0;i<4;i++)
    {
        int xg=red[i][0];
        int yg=red[i][1];
        
        if(x==xg and y==yg)
        {
            if(i == 0){
                red[i][0] = 450;
                red[i][1] = 625;
            }else if(i == 1){
                red[i][0] = 550;
                red[i][1] = 625;
            }else if(i == 2){
                red[i][0] = 450;
                red[i][1] = 725;
            }else if(i == 3){
                red[i][0] = 550;
                red[i][1] = 725;
            }
            //ให้ red[i][j] กลับจุดเกิด
        }

        int xy=yellow[i][0];
        int yy=yellow[i][1];
        
        if(x==xy and y==yy)
        {
            if(i == 0){
                yellow[i][0] = 900;
                yellow[i][1] = 175;
            }else if(i == 1){
                yellow[i][0] = 1000;
                yellow[i][1] = 175;
            }else if(i == 2){
                yellow[i][0] = 900;
                yellow[i][1] = 275;
            }else if(i == 3){
                yellow[i][0] = 1000;
                yellow[i][1] = 275;
            }
            //ให้ yellow[i][j] กลับจุดเกิด
        }

        int xb=blue[i][0];
        int yb=blue[i][1];
        
        if(x==xb and y==yb)
        {
            if(i == 0){
                blue[i][0] = 900;
                blue[i][1] = 625;
            }else if(i == 1){
                blue[i][0] = 1000;
                blue[i][1] = 625;
            }else if(i == 2){
                blue[i][0] = 900;
                blue[i][1] = 725;
            }else if(i == 3){
                blue[i][0] = 1000;
                blue[i][1] = 725;
            }
            //ให้ blue[i][j] กลับจุดเกิด
        }
    } 
    } 
  
  
