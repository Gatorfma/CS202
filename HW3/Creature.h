//
// Created by FURKAN MERT on 31.03.2023.
//

#ifndef HW3_CREATURE_H
#define HW3_CREATURE_H
#include "cmath"

class Creature {
public:
    int cId;
    int chealth;
    double cx;
    double cy;

    Creature();
    Creature(double x, double y, int cId, int health);
    Creature& operator=(const Creature& other){
        this->cId = other.cId;
        this->chealth = other.chealth;
        this->cx = other.cx;
        this->cy = other.cy;
        return *this;
    }

    double getDistance(Creature other);
    void fight(Creature *creatures, int num_of_creatures);
    void loseHealth();
};



#endif //HW3_CREATURE_H
