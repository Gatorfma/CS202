//
// Created by FURKAN MERT on 18.04.2023.
//

#ifndef HW3_HEAP_H
#define HW3_HEAP_H
#include "Food.h"

class Heap {
public:
    Heap();
    bool heapIsEmpty() const;
    void heapInsert(const Food& newItem);
    void heapDelete(Food& rootItem);
    Food getTop();
    void printHeap();

protected:
    void heapRebuild(int root);
private:
    Food items[30];
    int size;
};


#endif //HW3_HEAP_H
