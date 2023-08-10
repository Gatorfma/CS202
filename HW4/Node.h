//
// Created by FURKAN MERT on 9.05.2023.
//

#ifndef HW4_NODE_H
#define HW4_NODE_H
#include "Snack.h"

class Node {
public:
    Snack* snack;
    Node* next;

    Node(Snack* snack);
};


#endif //HW4_NODE_H
