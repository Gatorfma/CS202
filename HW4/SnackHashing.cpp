//
// Created by FURKAN MERT on 9.05.2023.
//

#include "SnackHashing.h"

SnackHashing::SnackHashing(int table_size) {
    this->table_size = table_size;
    this->table = new Node*[11];
    for (int i = 0; i < 11; ++i) {
        this->table[i] = nullptr;
    }
}

SnackHashing::~SnackHashing() {
    for (int i = 0; i < 11; ++i) {
        Node* cur = table[i];
        while (cur != nullptr){
            Node* temp = cur;
            cur = cur->next;
            delete temp->snack;
            delete temp;
        }
    }
    delete[] table;
}

int SnackHashing::hash(string key) {
    int sum = 0;
    for (int i = 0; i < key.length(); ++i) {
        sum += (int) key[i];
    }
    return sum % 11;
}

void SnackHashing::insert(Snack *snack) {
    int index = hash(snack->name);
    Node* node = new Node(snack);
    if(table[index] == nullptr){
        table[index] = node;
    }else{
        Node* cur = table[index];
        while (cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = cur;
    }
}

Snack *SnackHashing::search(string key) {
    int index = hash(key);
    Node* cur = table[index];
    while (cur != nullptr){
        if(cur->snack->name == key){
            return cur->snack;
        }
        cur = cur->next;
    }
    return nullptr;
}

void SnackHashing::remove(string key) {
    int index = hash(key);
    Node* cur = table[index];
    Node* prev = nullptr;
    while(cur != nullptr){
        if(cur->snack->name == key){
            if(prev == nullptr){
                table[index] = cur->next;
            }else{
                prev->next = cur->next;
            }
            delete cur->snack;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
