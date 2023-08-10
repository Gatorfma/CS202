//
// Created by FURKAN MERT on 31.03.2023.
//

#ifndef HW3_FOOD_H
#define HW3_FOOD_H
#include <cstdlib>
using namespace std;

class Food {
        public:
        int fid;
        int fquality;
        double fx;
        double fy;
        int ftime;

        Food();
        Food(double x, double y, int id, int quality, int time);

        bool operator<(const Food& f)const{
            return fquality < f.fquality;
        }

        friend class Creature;
};


#endif //HW3_FOOD_H
