//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
// Implementation of a hash table with a string that contains an ip as a key and a registerEntry object that contains
// the information of the corresponding IP, this table makes use of a linked lists to store this values
// The table detects when an ip already exists in the list and updates the data of the object correspondingly.
// Collision handled by separate chaining
//

#ifndef INC_52REGISTRYHASH_MYHASHTABLE_H
#define INC_52REGISTRYHASH_MYHASHTABLE_H

#include <string>
#include "MyLinkedList.h"
#include "RegisterEntry.h"

class MyHashTable {
private:
    int size;//El número de elementos que tiene almacenado
    int sizeA; //El tamaño del arreglo
    MyLinkedList *tabla;

    /// @brief Method to rehash the table if the load factor surpasses 0.75.
    // Complexity: O(n)
    void rehashing();

    /// @brief Method to calculate the position of a key in the table.
    /// @param key Key to get the position.
    // Complexity: O(1)
    int getPos(const string &key) const;

public:
    /// @brief Constructor with a default array size of 7069.
    // Complexity: O(1)
    MyHashTable();

    /// @brief  Destructor.
    // Complexity: O(n)
    ~MyHashTable();

    /// @brief Method to check if the hash table is empty.
    /// @return True if the Hash Table is empty.
    // Complexity: O(1)
    bool isEmpty() const;

    /// @brief Method to add a RegisterEntry object to the table if the ip already exits, it calls teh method
    /// addRegister of the Registry entry object to add a new date and to update the number ot times it repeats.
    /// @param reg RegisterEntry object to be inserted at the table.
    /// @param key The key is the string of the IP.
    // Complexity: Worst case scenario O(n) if the load factor is greater than 0.75 else best and average scenario O(1)
    void put(const string &key, RegisterEntry &reg);

    /// @brief Method to get the RegisterEntry of a IP.
    /// @param key IP to get the value.
    /// @return RegisterEntry object of the passed IP.
    // Complexity: O(1)
    RegisterEntry get(const string &key);

    /// @brief Method to remove an IP and its RegisterEntry object.
    /// @param key IP to be removed.
    // Complexity: Worst case scenario O(n) Average and best case O(1) because its optimized
    void remove(const string &key);
};


#endif //INC_52REGISTRYHASH_MYHASHTABLE_H
