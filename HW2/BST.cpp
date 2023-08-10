/**
* Title: Binary Search Trees
* Author : Furkan Mert Aksakal
* ID: 22003191
* Section : 02
* Homework : 2
* Description : BST.cpp Class
*/
#include "BST.h"
#include <iostream>
BST::BST() {
    base = NULL;
    numOfNodes = 0;
}
BST::BST(BSTNode *baseNode) {
    base = baseNode;
    numOfNodes = 1;
}

void BST::insertItem(int key) {
    insert2(base, key);
    //cout << "Item " << key << " inserted" << endl;
    numOfNodes++;
}
void BST::insert2(BSTNode *&nodePtr, int &item) {
    if (nodePtr == NULL) {
        nodePtr = new BSTNode(item, NULL, NULL);
        if (nodePtr == NULL)
            cout << ("TreeException: insert failed") << endl;
    }
        // Else search for the insertion position
    else if (item < nodePtr->data)
        insert2(nodePtr->leftPtr, item);
    else
        insert2(nodePtr->rightPtr, item);
}


void BST::deleteItem(int key) {
    deleteItem(base, key);
    numOfNodes--;
}
void BST::deleteNodeItem(BSTNode *&nodePtr) {
    BSTNode* delPtr;
    int repItem;

    if(nodePtr->leftPtr == NULL && nodePtr->rightPtr == NULL){
        delete nodePtr;
        nodePtr = NULL;
    }
    else if(nodePtr->leftPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = NULL;
        delete delPtr;
    }
    else if(nodePtr->rightPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->leftPtr;
        delPtr->leftPtr = NULL;
        delete delPtr;
    }
    else{
        processLeftmost(nodePtr->rightPtr, repItem);
        nodePtr->data = repItem;
    }
}
void BST::processLeftmost(BSTNode *&nodePtr, int& treeItem) {
    if(nodePtr->leftPtr == NULL){
        treeItem = nodePtr->data;
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = NULL;
        delete delPtr;
    } else{
        processLeftmost(nodePtr->leftPtr, treeItem);
    }
}
void BST::deleteItem(BSTNode *&treePtr, int searchKey){
    if(treePtr == NULL){
        cout << "Delete Failed! " << endl;
        return;
    }
    else if(searchKey == treePtr->data){
        deleteNodeItem(treePtr);
    }
    else if(searchKey < treePtr->data){
        deleteItem(treePtr->leftPtr, searchKey);
    }
    else{
        deleteItem(treePtr->rightPtr, searchKey);
    }

}

int* BST::inorderTraversal(int& length) {
    BSTNode* root = this->base;
    int* arr = new int[size(root)];
    int index = 0;
    inorderTraversalHelper(root, arr, index);
    length = index;
    return arr;
}

void BST::inorderTraversalHelper(BSTNode* node, int* arr, int& index) {
    if (node == nullptr) {
        return;
    }
    inorderTraversalHelper(node->leftPtr, arr, index);
    arr[index++] = node->data;
    inorderTraversalHelper(node->rightPtr, arr, index);
}

int BST::size(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + size(node->leftPtr) + size(node->rightPtr);
}

bool BST::hasSequence(int *seq, int length) {
    BSTNode* cur = this->base;
    int i = 0;

    while(cur != nullptr && i < length){
        if(cur->data == seq[i]){
            cout << cur->data << " ";
            i++;
            if(i == length){
                return true;
            }
            cur = cur->rightPtr;
        }
        if (cur->data < seq[i]){
            cur = cur->rightPtr;
        }
        else{
            cur = cur->leftPtr;
        }
    }
    return false;
}

