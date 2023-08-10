//
// Created by FURKAN MERT on 18.04.2023.
//
#include "iostream"
#include "Heap.h"
using namespace std;


Heap::Heap() : size(0) {
}

bool Heap::heapIsEmpty() const {
    return (size == 0);
}

void Heap::heapInsert(const Food &newItem) {
    if(size >= 30){
        return;
    } else {
        items[size] = newItem;
        int place = size;
        int parent = (place - 1) / 2;
        while ((place > 0) && (items[place].fquality > items[parent].fquality) || (items[place].fquality == items[parent].fquality && items[place].fid < items[parent].fid)) {
            Food temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++size;
    }
}

void Heap::heapDelete(Food &rootItem) {
    if (heapIsEmpty()) {
        cout << "HeapException: Heap empty" << endl;
        return;
    }
    else {
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }

}

void Heap::heapRebuild(int root) {
    int child = 2 * root + 1;
    if ( child < size ) {
        int rightChild = child + 1;
        if ( (rightChild < size) && (items[rightChild].fquality >items[child].fquality)) {
            child = rightChild;
        }
        if ( items[root].fquality < items[child].fquality ) {
            Food temp = items[root];
            items[root] = items[child];
            items[child] = temp;


            heapRebuild(child);
        }
    }
}

Food Heap::getTop() {
    if(size > 0){
        return items[0];
    }
}

void Heap::printHeap() {
    for (int i = 0; i < size; ++i) {
        cout << items[i].fid << "\t" << items[i].fx << "\t" << items[i].fy << "\t" << items[i].fquality << "\t" << items[i].ftime << endl;
    }
}
