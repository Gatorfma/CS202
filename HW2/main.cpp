/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : Main Class
*/
#include <iostream>
#include "BST.h"
#include <algorithm>
#include "analysis.h"
#include "BSTNode.h"


using namespace std;



void insertNode(BSTNode *&root, int data){
    if (root == NULL) {
        root = new BSTNode(data);
        return;
    }
    if (data < root->data) {
        insertNode(root->leftPtr, data);
    } else {
        insertNode(root->rightPtr, data);
    }
}

void mergeTrees(BSTNode*& root, BSTNode* node) {
    if (node == NULL) {
        return;
    }
    insertNode(root, node->data);
    mergeTrees(root, node->leftPtr);
    mergeTrees(root, node->rightPtr);
}

BST* merge(const BST& tree1, const BST& tree2) {
    BST* merged = new BST();
    mergeTrees(merged->base, tree1.base);
    mergeTrees(merged->base, tree2.base);
    return merged;
}





int main() {
    BST tree;
    tree.insertItem(1);
    tree.insertItem(2);
    tree.insertItem(3);
    tree.insertItem(4);
    tree.insertItem(5);
    tree.insertItem(6);
    tree.insertItem(8);
    tree.insertItem(10);
    tree.insertItem(12);
    tree.insertItem(13);
    tree.insertItem(14);
    tree.insertItem(15);
    tree.deleteItem(8);
    tree.deleteItem(12);
    tree.deleteItem(6);
    tree.deleteItem(5);
    BST tree2;
    tree2.insertItem(14);
    tree2.insertItem(27);
    tree2.insertItem(51);


   BST* tree3 =  merge(tree, tree2);

   int length = 0;
   int* arr = tree3->inorderTraversal(length);
   for (int i = 0; i < length; i++) {
        cout << arr[i] << endl;
   }



    int *seq = new int[4];
    seq[0] = 1;
    seq[1] = 2;
    seq[2] = 3;
    seq[3] = 4;
    seq[4] = 5;
    seq[5] = 6;

    cout << endl;
    tree3->hasSequence(seq, 6);
    cout << endl;
    timeAnalysis();
    return 0;
}