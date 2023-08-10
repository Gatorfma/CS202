/*
* Title: Algorithm Efficiency and Sorting
* Author:Furkan Mert Aksakal
* ID: 22003191
* Section: 2
* Assignment: 01
* Description: Main file
*/

#include <iostream>

#include <string>
#include "sorting.h"
#include <ctime>

using namespace std;

void createRandomArrays(int*& arr1, int*& arr2, int*& arr3,int*& arr4, int*& arr5,  const int size) {
    for (int i = 0; i < size; i++) {
        int random = rand()%100000;
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
        arr5[i] = random;
    }
}

void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3,int*& arr4, int*& arr5, const int size){
    for (int i = 0; i < size; ++i) {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
        arr5[i] = i;
    }
}

void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3,int*& arr4, int*& arr5, const int size){
    for (int i = 0; i < size; ++i) {
        arr1[size-1-i] = i;
        arr2[size-1-i] = i;
        arr3[size-1-i] = i;
        arr4[size-1-i] = i;
        arr5[size-1-i] = i;
    }

}

void performanceAnalysis(int &compCount, int &moveCount) {
    double duration;
    compCount = 0;
    moveCount = 0;
    sorting sort;
    const int size1 = 1000;
    const int size2 = 5000;
    const int size3 = 10000;
    const int size4 = 20000;

    //Arrays for BubbleSort
    int* ar1 = new int[size1];
    int* ar2 = new int[size2];
    int* ar3 = new int[size3];
    int* ar4 = new int[size4];

    //Arrays for MergeSort
    int* arrtemp1 = new int[size1];
    int* arrtemp2 = new int[size2];
    int* arrtemp3 = new int[size3];
    int* arrtemp4 = new int[size4];

    //Arrays for QuickSort
    int* array1 = new int[size1];
    int* array2 = new int[size2];
    int* array3 = new int[size3];
    int* array4 = new int[size4];

    //Arrays for InsertionSort
    int* tempar1 = new int[size1];
    int* tempar2 = new int[size2];
    int* tempar3 = new int[size3];
    int* tempar4 = new int[size4];

    //Arrays for HybridSort
    int* temp1 = new int[size1];
    int* temp2 = new int[size2];
    int* temp3 = new int[size3];
    int* temp4 = new int[size4];

    //Creating Random Arrays
    createRandomArrays(ar1, arrtemp1, array1,tempar1, temp1, size1);
    createRandomArrays(ar2, arrtemp2, array2,tempar2, temp2, size2);
    createRandomArrays(ar3, arrtemp3, array3,tempar3, temp3, size3);
    createRandomArrays(ar4, arrtemp4, array4,tempar4, temp4, size4);


    cout<< "\t\t\tPart 2-b-1: Performance Analysis of random integers array" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 1000" << endl;
    clock_t start = clock();
    sort.bubbleSort(ar1, size1, compCount, moveCount);
    clock_t end = clock();
    double time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time * 1000<< " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time *1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 5000" << endl;
    start = clock();
    sort.bubbleSort(ar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 10000" << endl;
    start = clock();
    sort.bubbleSort(ar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 20000" << endl;
    start = clock();
    sort.bubbleSort(ar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    //Creating Ascending Arrays
    createAscendingArrays(ar1, arrtemp1, array1,tempar1, temp1, size1);
    createAscendingArrays(ar2, arrtemp2, array2,tempar2, temp2, size2);
    createAscendingArrays(ar3, arrtemp3, array3,tempar3, temp3, size3);
    createAscendingArrays(ar4, arrtemp4, array4,tempar4, temp4, size4);


    cout << endl;
    cout << endl;
    cout<< "\t\t\tPart 2-b-2: Performance Analysis of ascending integers array" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 1000" << endl;
    start = clock();
    sort.bubbleSort(ar1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time * 1000<< " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time *1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 5000" << endl;
    start = clock();
    sort.bubbleSort(ar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 10000" << endl;
    start = clock();
    sort.bubbleSort(ar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 20000" << endl;
    start = clock();
    sort.bubbleSort(ar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;



    //Creating Descending Arrays
    createDescendingArrays(ar1,arrtemp1, array1, tempar1, temp1, size1);
    createDescendingArrays(ar2, arrtemp2, array2,tempar2, temp2, size2);
    createDescendingArrays(ar3, arrtemp3, array3,tempar3, temp3, size3);
    createDescendingArrays(ar4, arrtemp4, array4,tempar4, temp4, size4);

    cout << endl;
    cout << endl;
    cout<< "\t\t\tPart 2-b-2: Performance Analysis of descending integers array" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 1000" << endl;
    start = clock();
    sort.bubbleSort(ar1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time * 1000<< " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time *1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp1, size1, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 5000" << endl;
    start = clock();
    sort.bubbleSort(ar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp2, size2, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 10000" << endl;
    start = clock();
    sort.bubbleSort(ar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp3, size3, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\tElapsed Time\t" << "compCount\t" << "moveCount" << endl;
    cout << "Array size: 20000" << endl;
    start = clock();
    sort.bubbleSort(ar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Bubble Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;


    start = clock();
    sort.quickSort(array4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Quick Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.mergeSort(arrtemp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Merge Sort" << "\t\t" << time*1000  << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.insertionSort(tempar4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Insertion Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

    start = clock();
    sort.hybridSort(temp4, size4, compCount, moveCount);
    end = clock();
    time =(double) (end - start) / (CLOCKS_PER_SEC);
    cout << "Hybrid Sort" << "\t\t" << time*1000 << " ms\t\t" << compCount << "\t\t" << moveCount << endl;
    moveCount = 0;
    compCount = 0;

}
int main(){
        int compCount = 0;
        int moveCount = 0;
        performanceAnalysis(compCount, moveCount);
};
