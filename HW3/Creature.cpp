//
// Created by FURKAN MERT on 31.03.2023.
//

#include "Creature.h"


using namespace std;
Creature::Creature(double x, double y, int id, int health): cId(id), chealth(health), cx(x), cy(y){}

Creature::Creature(){
    cId = 0;
    chealth = 0;
    cx = 0;
    cy = 0;
}

double Creature::getDistance(Creature other) {
    double dx = other.cx - cx;
    double dy = other.cy - cy;
    return sqrt(dx * dx + dy * dy);
}

void Creature::fight(Creature creatures[], int num_of_creatures) {
    for (int i = 0; i < num_of_creatures; i++) {
        if(creatures[i].cId != cId && getDistance(creatures[i]) < 2 && creatures[i].chealth <= chealth){
            creatures[i].chealth = 0;
        }else if(creatures[i].cId != cId && getDistance(creatures[i]) < 2 && creatures[i].chealth >= chealth){
            chealth = 0;
        }
    }
}

void Creature::loseHealth() {
    if(chealth == 0){
        return;
    }
    chealth--;
}







