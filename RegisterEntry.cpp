//
// Created by Diego Alberto Ortiz Mariscal A01552000, Diego Mojarro A01638460,
// Luis Armando Salazar A01114901 on 11/26/20.
//

#include "RegisterEntry.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

RegisterEntry::RegisterEntry(const string &textRegistry) {

    string month;
    string dateString;
    string day;
    string time;
    string ip;

    // Cycle to split a string by space
    int stringPosition = 0;
    string message;
    istringstream ss(textRegistry);
    do {
        string word;
        ss >> word;
        if (stringPosition == 0) {
            month = word;
            dateString = dateString + month;
        } else {
            if (stringPosition == 1) {
                day = word;
                dateString = dateString + " " + day;
            } else {
                if (stringPosition == 2) {
                    time = word;
                    dateString = dateString + " " + time;
                } else {
                    if (stringPosition == 3) {
                        setIpString(word);
                    }
                }
            }
        }
        stringPosition++;
    } while (ss);

    this->datesVector.emplace_back(dateToInt(month, day, time), dateString);
    this->accessCount = 1;
}

RegisterEntry::RegisterEntry() = default;

int RegisterEntry::dateToInt(string &month, string &day, string &time) {
    int monthInt;
    int dayInt = stoi(day);
    int hourInt;
    int minuteInt;
    int secondsInt;

    static const std::map<std::string, int> monthsTable{
            {
                    {"Jan", 0},
                    {"Feb", 1},
                    {"Mar", 2},
                    {"Apr", 3},
                    {"May", 4},
                    {"Jun", 5},
                    {"Jul", 6},
                    {"Aug", 7},
                    {"Sep", 8},
                    {"Oct", 9},
                    {"Nov", 10},
                    {"Dec", 11}
            }
    };
    monthInt = monthsTable.find(month)->second;

    // Cycle to split Time in Hours minutes and seconds
    std::stringstream ss(time);
    string part;
    int stringPosition = 0;
    // Split by .
    while (getline(ss, part, ':')) {
        if (stringPosition == 0) {
            hourInt = stoi(part);
        } else {
            if (stringPosition == 1) {
                minuteInt = stoi(part);
            } else {
                if (stringPosition == 2) {
                    secondsInt = stoi(part);
                }
            }
        }
        stringPosition++;
    }

    int tempDateInt = (monthInt * 31 * 24 * 60 * 60 + (dayInt * 24 * 60 * 60) + (hourInt * 60 * 60) + (minuteInt * 60) +
                       secondsInt);
    return tempDateInt;
}

const string &RegisterEntry::getTextRegistry() const {
    return textRegistry;
}

void RegisterEntry::setTextRegistry(const string &textRegistry) {
    RegisterEntry::textRegistry = textRegistry;
}

const string &RegisterEntry::getIpString() const {
    return ipString;
}

void RegisterEntry::setIpString(const string &ipString) {
    RegisterEntry::ipString = ipString;
}

int RegisterEntry::getAccessCount() const {
    return accessCount;
}

void RegisterEntry::addRegister(const string &dateString, int dateInt) {
    this->datesVector.emplace_back(dateInt, dateString);
    sort(this->datesVector.begin(), this->datesVector.end());
    this->accessCount++;
}

int RegisterEntry::getDateInt() {
    return this->datesVector[0].dateInt;
}

string RegisterEntry::getDateString() {
    return this->datesVector[0].dateString;
}

ostream &operator<<(ostream &os, const RegisterEntry &entry) {
    string listOfDates;
    for (auto it = begin(entry.datesVector); it != end(entry.datesVector); ++it) {
        listOfDates += it->dateString + ", ";
    }
    os << " IP: " << entry.ipString << " Numero de accesos: "
       << entry.accessCount << " Fechas: " << listOfDates;
    return os;
}
