/*
* Title: Algorithm Analysis and Sorting
* Author:Furkan Mert Aksakal
* ID: 22003191
* Section: 2
* Homework: 01
* Description: Cpp file
*/

#include "sorting.h"

void sorting::mergeSort(int *arr, const int size, int &compCount, int &moveCount) {
    int first = 0;
    int last = size - 1;
    merge2(arr, first, last, compCount, moveCount);
}
void sorting::merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArr[last+1];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2) ; ++index) {
        compCount++;
        if (arr[first1] < arr[first2]) {
            tempArr[index] = arr[first1];
            ++first1;
            moveCount++;
        }
        else {
            tempArr[index] = arr[first2];
            ++first2;
            moveCount++;
        }
    }
    for (; first1 <= last1; ++first1, ++index) {
        tempArr[index] = arr[first1];
        moveCount++;
    }
    for (; first2 <= last2; ++first2, ++index) {
        tempArr[index] = arr[first2];
        moveCount++;
    }
    for (index = first; index <= last; ++index) {
        arr[index] = tempArr[index];
        moveCount++;
    }
}
void sorting::merge2(int *arr, int first, int last, int &compCount, int &moveCount) {
    if(first < last){
        compCount++;
        int mid = (first + last)/2;

        merge2(arr, first, mid, compCount, moveCount);

        merge2(arr, mid+1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
    }
}

void sorting::bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted ; ++pass) {
        sorted = true;
        for (int index = 0; index < size - pass; ++index) {
            int nextIndex = index +1;
            compCount++;
            if(arr[index] > arr[nextIndex]) {
                swap(arr[index], arr[nextIndex]);
                moveCount = moveCount + 3;
                sorted = false;
            }
        }
    }
}


void sorting::quickSort(int *arr, const int size, int &compCount, int &moveCount) {
    quick2(arr,0,size-1,compCount,moveCount);
}
void sorting::quick2(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if(first<last){
        partition(arr, first,last, pivotIndex, compCount, moveCount);
        quick2(arr, first, pivotIndex-1,compCount,moveCount);
        quick2(arr, pivotIndex+1, last,compCount,moveCount);
    }
}
void sorting::swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void sorting::partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    int pivot = arr[first];
    int lastS1 = first;
    int firstUnknown = first + 1;

    for (; firstUnknown <= last ; ++firstUnknown) {
        if(arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount += 3;
        }
        compCount++;
    }
    swap(arr[first] , arr[lastS1]);
    pivotIndex = lastS1;
    moveCount += 3;
}

void sorting::insertionSort(int *arr, const int size, int &compCount, int &moveCount) {
    for (int unsorted = 1; unsorted < size; ++unsorted) {
        compCount++;
        int nextItem = arr[unsorted];
        int loc = unsorted;
        moveCount = moveCount +2;
        for ( ;(loc > 0) && (arr[loc-1] > nextItem); --loc) {
            compCount++;
            arr[loc] = arr[loc - 1];
        }
        arr[loc] = nextItem;
        moveCount++;
    }
}

void sorting::hybridSort(int *arr, const int size, int &compCount, int &moveCount) {
    hybrid2(arr, 0, size - 1, compCount, moveCount);
}
void sorting::hybrid2(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    if(first<last){
        bool sort = false;
        hPartition(arr, first,last, pivotIndex, compCount, moveCount, sort);
        if(sort){
            return;
        }
        hybrid2(arr, first, pivotIndex-1,compCount,moveCount);
        hybrid2(arr, pivotIndex+1, last,compCount,moveCount);
    }
}
void sorting::hPartition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount, bool& sort) {
    int size = last - first;
    if(size < 20){
        hBubble(arr, first, last, compCount, moveCount);
        sort = true;
    }
    else{
        partition(arr, first, last, pivotIndex, compCount, moveCount);
    }

}
void sorting::hBubble(int *arr, int first, int last, int &compCount, int &moveCount) {
    int size = last - first +1;
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted ; ++pass) {
        sorted = true;
        for (int index = 0; index < size - pass; ++index) {
            int nextIndex = index +1;
            compCount++;
            if(arr[index + first] > arr[nextIndex + first]) {
                swap(arr[index + first], arr[nextIndex + first]);
                moveCount += 3;
                sorted = false;
            }
        }
    }
}



