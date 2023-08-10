/*
* Title: Algorithm Analysis and Sorting
* Author:Furkan Mert Aksakal
* ID: 22003191
* Section: 2
* Homework: 01
* Description: Header file
*/


#ifndef HW1_SORTING_H
#define HW1_SORTING_H


class sorting {
public:
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);

    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
    void merge2(int *arr, int first, int last,int &compCount, int &moveCount );

    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void quick2(int *arr, int first, int last, int &compCount, int &moveCount);
    void swap(int &a, int &b);
    void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);

    void insertionSort(int *arr, const int size, int &compCount, int &moveCount);

    void hybridSort(int* arr, const int size, int& compCount, int& moveCount);
    void hybrid2(int* arr, int first, int last, int& compCount, int& moveCount);
    void hPartition(int* arr, int first, int last, int& pivotIndex, int& compCount, int& moveCount, bool& sort);
    void hBubble(int* arr, int first, int last, int& compCount, int& moveCount);

};
#endif //HW1_SORTING_H
