/**
* Title: Balanced search trees and hashing
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 2
* Homework : 4
* Description : Snack Header Class
*/

#ifndef HW4_SNACK_H
#define HW4_SNACK_H
using namespace std;
#include "string"
#include "iostream"
struct SnackNode;

class Snack {
public:
    SnackNode* node;
    string name;

    Snack();
    Snack(string name);
    void addAcc(string name);
    void deleteAcc(string name);

};

struct SnackNode{
    Snack s;
    SnackNode* accSnacks;
};



#endif //HW4_SNACK_H
