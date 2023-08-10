/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : BST.h Class
*/
#ifndef HW2_BST_H
#define HW2_BST_H

#include "BSTNode.h"

using namespace std;

class BST {
public:
    BSTNode* base;
    int numOfNodes;

    BST();
    BST(BSTNode* baseNode);

    void insertItem(int key);
    void insert2(BSTNode* &nodePtr, int& item);

    void deleteItem(int key);
    void deleteItem(BSTNode* &treePtr, int searchKey);
    void deleteNodeItem(BSTNode* &nodePtr);
    void processLeftmost(BSTNode* &nodePtr, int& treeItem);

    /*int* inorderTraversal(int& length);
    void inorderTraversalHelper(BSTNode* node, int* arr, int& index, int &num);*/


    bool hasSequence(int *seq, int length);

    int *inorderTraversal(int &length);

    void inorderTraversalHelper(BSTNode *node, int *arr, int &index);

    int size(BSTNode *node);
};


#endif //HW2_BST_H
