#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int roll_dice()
{
    int d;
    d= rand() %6 +1;
    return d;
}