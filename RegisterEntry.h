//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
// Object that contains an IP, the number of times it repeats and its date with some methods to read the information
// form a string and convert it to its respective data type
//

#ifndef INC_52REGISTRYHASH_REGISTERENTRY_H
#define INC_52REGISTRYHASH_REGISTERENTRY_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Definition of struct that contains a pair of attributes of date one as a string and one as an integer in seconds
struct datePair {
    int dateInt;
    string dateString;

    /// @brief Constructor of the struct, assigns the values passed as its attributes.
    ///@param dateInt Integer of the date in seconds;
    ///@param dateString Integer of the date in seconds;
    // Complexity: O(1)
    datePair(int dateInt, string dateString) : dateInt(dateInt), dateString(std::move(dateString)) {};

    /// @brief Operator overload to compare the date using the dateInt.
    // Complexity: O(1)
    bool operator<(const datePair &str) const {
        return (dateInt < str.dateInt);
    }
};

class RegisterEntry {
private:
    // String that contains the whole registry
    string textRegistry;
    // String that contains the IP
    string ipString;
    // Number of times the IP repeats
    int accessCount;
    // Vector of struct datePair that contains the date as a string and as a number in seconds
    vector<datePair> datesVector;

public:
    /// @brief Constructor that receives a string containing a registry entry in format MMM DD HH:MM:SS IP Message,
    /// initializes the attributes textRegistry, ipString accessCount and dates vector with the data of the string
    /// transformed to its corresponding format.
    /// @param textRegistry Reference to the string containing the information of the registries.
    // Complexity: O(1)
    explicit RegisterEntry(const string &textRegistry);

    /// @brief Default constructor
    // Complexity: O(1)
    RegisterEntry();

    /// @brief Method to transform the strings of a date to an integer in seconds.
    /// @param month Reference to the string of the month.
    /// @param day Reference to the string of the day.
    /// @param time Reference to the string of the time of the day.
    /// @return The date in seconds as an integer
    // Complexity: O(1)
    static int dateToInt(string &month, string &day, string &time);

    /// @brief Method to update the register if a register wih the same IP already exists, every time its called
    /// the vector containing the date pair is sorted.
    /// @param dateString Reference to the string of the date.
    /// @param dateInt Integer of the date in seconds.
    /// @param time Reference to the string of the time of the day.
    // Complexity: O(n) depends on the number of dates and therefore on the number of the times that the IP repeats
    void addRegister(const string &dateString, int dateInt);

    // Getters and setters
    // Complexity: O(1)
    const string &getTextRegistry() const;

    void setTextRegistry(const string &textRegistry);

    const string &getIpString() const;

    void setIpString(const string &ipString);

    int getAccessCount() const;

    int getDateInt();

    string getDateString();

    /// @brief Stream output operator to display the registry in format IP Number of accesses and
    /// Date in format MMM DD HH:MM:SS
    // Complexity: O(n) depends on the number of dates and therefore on the number of the times that the IP repeats
    friend ostream &operator<<(ostream &os, const RegisterEntry &entry);
};

#endif //INC_52REGISTRYHASH_REGISTERENTRY_H
