/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : BSTNode.h Class
*/

#ifndef HW2_BSTNODE_H
#define HW2_BSTNODE_H
#include <cstdlib>
using namespace std;

class BSTNode {
public:
    BSTNode(const BSTNode& node);
    BSTNode(const int& nodeItem, BSTNode* left = NULL, BSTNode* right = NULL);

    int data;
    BSTNode *rightPtr;
    BSTNode *leftPtr;

    BSTNode();

    friend class BST;
};



#endif //HW2_BSTNODE_H
