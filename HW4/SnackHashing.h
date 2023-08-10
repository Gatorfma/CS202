//
// Created by FURKAN MERT on 9.05.2023.
//

#ifndef HW4_SNACKHASHING_H
#define HW4_SNACKHASHING_H


#include "Node.h"

class SnackHashing {
    int table_size = 11;
    Node** table;

    SnackHashing(int table_size);
    ~SnackHashing();
    int hash(string key);
    void insert(Snack* snack);
    Snack* search(string key);
    void remove(string key);
};


#endif //HW4_SNACKHASHING_H
