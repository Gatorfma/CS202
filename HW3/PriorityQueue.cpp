//
// Created by FURKAN MERT on 18.04.2023.
//
#include "iostream"
#include "PriorityQueue.h"

using namespace std;

bool PriorityQueue::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const Food &newItem) {
    h.heapInsert(newItem);
}

void PriorityQueue::pqDelete(Food &priorityItem) {
    h.heapDelete(priorityItem);
}

Food PriorityQueue::top() {
    return h.getTop();
}

void PriorityQueue::printPQ() {
    h.printHeap();
}
