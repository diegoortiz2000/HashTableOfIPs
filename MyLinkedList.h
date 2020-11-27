//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
// Linked list of IPs and a RegisterEntry object that contains information about the IP and its corresponding methods
// with some extra methods and modifications to aid the Hash Table
//

#ifndef INC_52REGISTRYHASH_MYLINKEDLIST_H
#define INC_52REGISTRYHASH_MYLINKEDLIST_H


#include <iostream>
#include <string>
#include <utility>
#include "RegisterEntry.h"

using namespace std;

// Structure of a node
struct MyNodoLL {
    string key;
    RegisterEntry reg;
    MyNodoLL *next;

    /// @brief Constructor of MyNodoLL.
    /// @param key The key is the string of the IP.
    /// @param reg RegisterEntry object to be inserted at the table.
    /// @param next Pointer to the next node.
    // Complexity: O(1)
    MyNodoLL(string key, RegisterEntry reg, MyNodoLL *next) {
        this->key = std::move(key);
        this->reg = std::move(reg);
        this->next = next;
    }

    /// @brief Constructor of MyNodoLL, initializes the next pointer as a nullptr.
    /// @param key The key is the string of the IP.
    /// @param reg RegisterEntry object to be inserted at the table.
    // Complexity: O(1)
    MyNodoLL(string key, RegisterEntry reg) : MyNodoLL(std::move(key), std::move(reg), nullptr) {}
};

class MyLinkedList {
private:
    // Pointer to the head node
    MyNodoLL *head;
    // Pointer to the tail node
    MyNodoLL *tail;
    // Number of elements in the list
    int size;
public:
    /// @brief Constructor of MylinkedList initializes head and tail as nullptr and size as 0.
    // Complexity: O(1)
    MyLinkedList();

    /// @brief Destructor of MylinkedList.
    // Complexity: O(n)
    ~MyLinkedList();

    /// @brief Method to get the number of elements in the Linked list.
    /// @return number of elements in the list.
    // Complexity: O(1)
    int length() const;

    /// @brief Method to check if the Linked List is empty.
    /// @return True if the Hash Linked List is empty.
    // Complexity: O(1)
    bool isEmpty() const;

    /// @brief Method to get the number of elements in the Linked List.
    /// @return number of elements in the list.
    // Complexity: O(1)
    MyNodoLL *getAt(int pos);

    /// @brief Method to get a pointer to the RegisterEntry of a key (IP).
    /// @param key The key is a reference to the string of the IP.
    /// @return a pointer to the RegisterEntry of a key (IP).
    // Complexity: O(1)
    RegisterEntry *getAt(const string &key);

    /// @brief Method to test if a key (IP) is already in the Linked List.
    /// @param key The key is a reference to the string of the IP.
    /// @return True if the key (IP) is already in the Linked List.
    // Complexity: Worst case scenario: O(n), average and best case scenario: O(1)
    bool isRepeated(const string &key);

    /// @brief Method to create a node with the key (IP) and its RegisterEntry and insert it to the first place of the
    /// linked list.
    /// @param key The key is the string of the IP.
    /// @param reg RegisterEntry object of the IP to be inserted.
    // Complexity: O(1)
    void insertFirst(string key, RegisterEntry reg);

    /// @brief Method to remove the first node of the Linked List.
    // Complexity: O(1)
    void removeFirst();

    /// @brief Method to remove the last node of the Linked List.
    // Complexity: O(n)
    void removeLast();

    /// @brief Method to remove the node from Linked List at the received position.
    /// @param pos Position to be deleted
    // Complexity: O(n)
    void removeAt(int pos);

    /// @brief Method to remove the node from Linked List that contains the key(IP) passed.
    /// @param key Key(IP) to be deleted
    // Complexity: O(n)
    void removeAt(const string &key);

    /// @brief Method to remove the node from Linked List that contains the key(IP) passed.
    /// @return An ostream with the information of each node of the list.
    friend ostream &operator<<(ostream &os, const MyLinkedList &ll) {
        MyNodoLL *current = ll.head;
        for (int i = 0; i < ll.size; i++) {
            os << "[" << current->key << ",";
            os << current->reg << "]";
            current = current->next;
        }
        return os;
    }
};

#endif //INC_52REGISTRYHASH_MYLINKEDLIST_H