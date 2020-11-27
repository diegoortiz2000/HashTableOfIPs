//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
// Program to read a file containing IPs and information related to a server connection, then store the data
// in a Hash table and make queries about a certain IP
//

#include <iostream>
#include <vector>
#include <fstream>
#include "MyHashTable.h"
#include "RegisterEntry.h"

using namespace std;

int main() {
    // Name of the file that contains the registries
    std::string regFile = "bitacora2.txt";
    // Table initialization
    MyHashTable hashTableOfIps;

    // Open text file and add the IP and registerEntry to the hash table
    try {
        std::ifstream is;
        is.open(regFile);
        if (!is) throw std::ios::failure("Cannot find file");
        std::string str;
        // Get each line of the file and initialize the registerEntry object with the information of each line
        while (std::getline(is, str)) {
            // Object initialization
            RegisterEntry currentReg(str);
            // Add Ip and registerEntry to the hash table
            hashTableOfIps.put(currentReg.getIpString(), currentReg);
        }
    } catch (const std::exception &error) {
        std::cerr << error.what() << std::endl;
    }

    // Cycle to do queries until the user wants to stop
    bool continueSearch = true;
    while (continueSearch) {
        string query;
        string input;
        bool correctInput = false;

        cout << "Escribe la IP que quieres consultar: " << endl;
        cin >> query;
        // Display the information of the IP if the query coincides with the hash table
        cout << hashTableOfIps.get(query) << endl;

        // Cycle to ask user if it wants to continue until it receives a valid input
        while (!correctInput) {
            cout << "¿Deseas buscar otra IP Y/N?: " << endl;
            cin >> input;
            if (input == "Y" || input == "y") {
                correctInput = true;
                continueSearch = true;
            } else if (input == "N" || input == "n") {
                correctInput = true;
                continueSearch = false;
            } else {
                correctInput = false;
            }
        }
    }

    return 0;
}
