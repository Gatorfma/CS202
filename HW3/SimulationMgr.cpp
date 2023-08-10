//
// Created by FURKAN MERT on 3.04.2023.
//
#include "Creature.h"
#include "Food.h"
#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <string>
#include "iomanip"

using namespace std;

void sortArray(Creature arr[], int numOfCreatures) {
    for (int i = 0; i <  numOfCreatures - 1; i++) {
        for (int j = i + 1; j < numOfCreatures; j++) {
            if(arr[j].cId < arr[i].cId){
                Creature temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printLocations(Creature arr[], int numOfCreatures){
    for (int i = 0; i < numOfCreatures; i++)
    {
        Creature temp = arr[i];
        cout << "Creature " << i+1 << ": " << fixed << setprecision(2) <<"\t" << temp.cx <<fixed << setprecision(2) << "\t" << temp.cy <<  endl;
    }
}

bool isAlive(Creature arr[], int numCreatures){
    for (int i = 0; i < numCreatures; ++i) {
        if(arr[i].chealth > 0){
            return true;
        }
    }
    return false;
}

void addFood(PriorityQueue& current, PriorityQueue& extra, int time){
    int size = 0;
    Food temp[30];
    Food tempF;
    while(!extra.pqIsEmpty()){
        extra.pqDelete(tempF);
        if(tempF.ftime == time){
            current.pqInsert(tempF);
        }
        else{
            temp[size]=tempF;
            size++;
        }
    }
    while(size > 0){
        extra.pqInsert(temp[size-1]);
        size--;
    }
}

double getDistance(Creature c, Food f){
    double dx = c.cx - f.fx;
    double dy = c.cy - f.fy;
    return sqrt(dx * dx + dy * dy);
}
void consumeFood(Creature& c, PriorityQueue& currentFood, int num) {
    if (getDistance(c, currentFood.top()) <= 1) {
        Food f;
        c.chealth += currentFood.top().fquality;
        currentFood.pqDelete(f);
    }
}
void moveTowards(Creature &c, PriorityQueue& cur, int num) {
    if(c.chealth<=0)
        return;

    double speed = 1.0;
    if (c.chealth > 10) {
        speed = 10.0 / c.chealth;
    }

    double dx = cur.top().fx - c.cx;
    double dy = cur.top().fy - c.cy;
    double dist = sqrt(dx * dx + dy * dy);

    if (dist != 0) {
        c.cx += ((cur.top().fx - c.cx) / dist) * speed;
        c.cy += ((cur.top().fy - c.cy) / dist) * speed;
    }

}


int main(int argc, char* argv[]){
    string data(argv[1]);
    fstream file(data);

    string line;
    getline(file, line);

    int numCreatures = stoi(line);

    PriorityQueue currentFood;
    PriorityQueue extraFood;

    if (numCreatures > 30)
    {
        cout << "Too many creatures!!!"<<endl;
        return 0;
    }

    Creature creatures[30];

    for (int i = 0; i < numCreatures; i++)
    {
        getline(file, line);
        int id;
        double x;
        double y;
        int health;

        size_t initial = 0;
        size_t comma = line.find(",");
        string st = line.substr(initial, comma - initial);
        id = stoi(st);

        initial = comma + 1;
        comma = line.find(",", initial);
        st = line.substr(initial, comma - initial);
        x = stod(st);

        initial = comma + 1;
        comma = line.find(",", initial);
        st = line.substr(initial, comma - initial);
        y = stod(st);

        initial = comma + 1;
        st = line.substr(initial);
        health = stoi(st);

        Creature c = Creature(x, y, id, health);
        creatures[i] = c;
    }
    while (getline(file, line)) {
        int id;
        double x;
        double y;
        int quality;
        int t;

        size_t initial = 0;
        size_t comma = line.find(",");
        string st = line.substr(initial, comma - initial);
        id = stoi(st);

        initial = comma + 1;
        comma = line.find(",", initial);
        st = line.substr(initial, comma - initial);
        x = stod(st);

        initial = comma + 1;
        comma = line.find(",", initial);
        st = line.substr(initial, comma - initial);
        y = stod(st);

        initial = comma + 1;
        comma = line.find(",", initial);
        st = line.substr(initial, comma - initial);
        quality = stoi(st);

        initial = comma + 1;
        st = line.substr(initial);
        t = stoi(st);

        Food f = Food(x, y, id, quality, t);

        if (t>0)
            extraFood.pqInsert(f);
        else
            currentFood.pqInsert(f);

    }
    sortArray(creatures, numCreatures);
    cout << endl;
    int time = 0;
    while(isAlive(creatures, numCreatures)){
        printLocations(creatures, numCreatures);
        if(!extraFood.pqIsEmpty())
            addFood(currentFood, extraFood, time);

        for (int i = 0; i < numCreatures; ++i) {
            creatures[i].fight(creatures, numCreatures);
        }

        if(!currentFood.pqIsEmpty()){
            for (int i = 0; i < numCreatures; ++i) {
                moveTowards(creatures[i], currentFood, numCreatures);
            }
        }
        if(!currentFood.pqIsEmpty()){
            for (int i = 0; i < numCreatures; ++i) {
                consumeFood(creatures[i], currentFood, numCreatures);
            }
        }

        for(int i= 0; i < numCreatures ; i++){
            creatures[i].loseHealth();
        }
        time++;
    }



    file.close();
    return 0;
}
