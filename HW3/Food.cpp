//
// Created by FURKAN MERT on 31.03.2023.
//

#include "Food.h"

Food::Food(double x, double y, int id, int quality, int time) {
    fid = id;
    fquality = quality;
    fx = x;
    fy = y;
    ftime = time;
}

Food::Food() {}
