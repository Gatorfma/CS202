/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : BSTNode.cpp Class
*/

#include "BSTNode.h"
using namespace std;

BSTNode::BSTNode() : data(0), leftPtr(NULL), rightPtr(NULL) {
}

// constructor
BSTNode::BSTNode(const int& nodeItem, BSTNode* leftPtr, BSTNode* rightPtr) : data(nodeItem), leftPtr(leftPtr), rightPtr(rightPtr) {
}

// copy constructor
BSTNode::BSTNode(const BSTNode& node) : data(node.data), leftPtr(node.leftPtr), rightPtr(node.rightPtr) {
}
