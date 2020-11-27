//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
//

#include "MyHashTable.h"
#include <cmath>

using namespace std;

MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 7069;
    this->tabla = new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable() {
    delete[] this->tabla;
}

bool MyHashTable::isEmpty() const {
    return this->size == 0;
}

void MyHashTable::rehashing() {
    MyLinkedList *tempTabla = this->tabla;
    this->sizeA = ((this->sizeA * 2) + 1);
    this->size = 0;
    this->tabla = new MyLinkedList[this->sizeA];
    for (int i = 0; i < (this->sizeA - 1) / 2; i++) {
        while (!tempTabla[i].isEmpty()) {
            auto head = tempTabla[i].getAt(0);
            put(head->key, head->reg);
            tempTabla[i].removeFirst();
        }
    }
    delete[] tempTabla;
}

int MyHashTable::getPos(const string &key) const {
    size_t hashT = hash<string>{}(key);
    int hashCode = static_cast<int>(hashT);
    return abs(hashCode) % this->sizeA;
}

void MyHashTable::put(const string &key, RegisterEntry &reg) {
    double loadFactor = size * 1.0 / sizeA;
    if (loadFactor > 0.75) {
        rehashing();
        put(key, reg);
    } else {
        int pos = getPos(key);
        if (!this->tabla[pos].isRepeated(key)) {
            this->tabla[pos].insertFirst(key, reg);
            this->size++;
        } else {
            this->tabla[pos].getAt(key)->addRegister(reg.getDateString(), reg.getDateInt());
        }
    }
}

RegisterEntry MyHashTable::get(const string &key) {
    int pos = getPos(key);
    MyLinkedList *lista = &this->tabla[pos];
    return *lista->getAt(key);
}

void MyHashTable::remove(const string &key) {
    int pos = getPos(key);
    this->tabla[pos].removeAt(key);
}