#include <stdio.h>
#include "dentro_ret.h"

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y) {
    int xmin = (x0 < x1) ? (x0) : (x1);  
    int xmax = (x0 > x1) ? (x0) : (x1);  
    int ymin = (y0 < y1) ? (y0) : (y1);   
    int ymax = (y0 > y1) ? (y0) : (y1);   
    if((x > xmin && x < xmax) && (y > ymin && y < ymax)) return 1;
    else return 0;
}