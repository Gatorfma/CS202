//
// Created by FURKAN MERT on 18.04.2023.
//

#include "Heap.h"

class PriorityQueue {
public:
    bool pqIsEmpty() const;
    void pqInsert(const Food& newItem);
    void pqDelete(Food& priorityItem);
    Food top();
    void printPQ();
private:
    Heap h;
};
