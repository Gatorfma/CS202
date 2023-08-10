/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : Analysis.cpp Class
*/
#include <iostream>
#include "analysis.h"
#include "BST.h"
#include <ctime>
#include <algorithm>
using namespace std;

void timeAnalysis() {
        cout << "Part e - Time Analysis of Binary Search Tree - Part 1" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Tree Size " << "\t\t" << "Time Elapsed " << endl;
        cout << "-----------------------------------------------------" << endl;
        int* arr = new int[15000];
        for (int i = 0; i < 15000; ++i) {
            arr[i] = (rand() % 15000);
        }

        BST tree;
        clock_t start = clock();
        for (int i = 0; i <= 15000; ++i) {
            tree.insertItem(arr[i]);
            if((i>=1500 && i % 1500 == 0) || i == 15000){
                clock_t end = clock();
                double time =(double) (end - start) / (CLOCKS_PER_SEC);
                cout << i << "\t\t\t" << time *1000<< " ms" << endl;
            }
        }

        random_shuffle(&arr[0], &arr[14999]);
        cout << endl;
        cout << endl;

        cout << "Part e - Time Analysis of Binary Search Tree - Part 2" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Tree Size " << "\t\t" << "Time Elapsed " << endl;
        cout << "-----------------------------------------------------" << endl;

        start = clock();
        for (int i = 13500; i > 0; i--) {

            tree.deleteItem(arr[i]);
            if((i>=1500 && i % 1500 == 0) || i == 15000){
                clock_t end = clock();
                double time =(double) (end - start) / (CLOCKS_PER_SEC);
                cout << i << "\t\t\t" << time *1000 << " ms" << endl;
            }
        }
}
