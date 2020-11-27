//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
//

#include "MyLinkedList.h"
#include <string>
#include <utility>

using namespace std;

MyLinkedList::MyLinkedList() {
    this->head = this->tail = nullptr;
    this->size = 0;
}

MyLinkedList::~MyLinkedList() {
    MyNodoLL *next;
    while (head != nullptr) {
        next = head->next;
        delete head;
        head = next;
    }
}

int MyLinkedList::length() const {
    return this->size;
}

bool MyLinkedList::isEmpty() const {
    return this->size == 0;
}

RegisterEntry *MyLinkedList::getAt(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            return &current->reg;
        }
        current = current->next;
    }
    throw invalid_argument("No se encontró " + key + " en la lista");
}

bool MyLinkedList::isRepeated(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            return true;
        }
        current = current->next;
    }
    return false;
}

MyNodoLL *MyLinkedList::getAt(int pos) {
    if (pos >= 0) {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
        return current;
    } else {
        throw invalid_argument("No se puede insertar en la posición " + to_string(pos) + " en una lista de tamaño " +
                               to_string(this->size));
    }
}

void MyLinkedList::insertFirst(string key, RegisterEntry reg) {
    this->head = new MyNodoLL(std::move(key), move(reg), this->head);
    if (this->tail == nullptr) {
        this->tail = this->head;
    }
    this->size++;
}

void MyLinkedList::removeFirst() {
    if (this->size > 0) {
        MyNodoLL *tmp = this->head;
        this->head = this->head->next;
        this->size--;
        if (this->size == 0) {
            this->tail = nullptr;
        }
        delete tmp;
    } else {
        throw invalid_argument("No se puede borrar el inicio de una lista vacía");
    }
}

void MyLinkedList::removeLast() {
    if (this->size <= 1) {
        removeFirst();
    } else {
        MyNodoLL *current = this->head;
        for (int i = 0; i < this->size - 2; i++) {
            current = current->next;
        }
        this->tail = current;
        delete current->next;
        this->tail->next = nullptr;
        this->size--;
    }
}

void MyLinkedList::removeAt(int pos) {
    if (pos == 0) {
        removeFirst();
    } else {
        MyNodoLL *current = this->head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        MyNodoLL *tmp = current->next;
        current->next = current->next->next;
        if (pos == this->size - 1) {
            this->tail = current;
        }
        this->size--;
        delete tmp;
    }
}

void MyLinkedList::removeAt(const string &key) {
    MyNodoLL *current = this->head;
    for (int i = 0; i < this->size; i++) {
        if (current->key == key) {
            removeAt(i);
        }
        current = current->next;
    }
}
