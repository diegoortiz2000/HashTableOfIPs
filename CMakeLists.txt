cmake_minimum_required(VERSION 3.17)
project(52RegistryHash)

set(CMAKE_CXX_STANDARD 14)

add_executable(52RegistryHash HashTable.cpp MyHashTable.cpp MyHashTable.h MyLinkedList.cpp MyLinkedList.h RegisterEntry.cpp RegisterEntry.h)