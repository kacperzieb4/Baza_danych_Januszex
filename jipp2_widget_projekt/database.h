#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include "person.h"

class Database {
private:
    std::vector<Person> people;
    std::string generateUsername(const std::string& firstName, const std::string& lastName) {
        std::string baseUsername = firstName.substr(0, 1) + lastName.substr(0, 1);
        int id = 1;
        std::string newUsername;
        bool unique;
        do {
            newUsername = baseUsername + std::to_string(id++);
            unique = true;
            for (const auto& person : people) {
                if (person.username == newUsername) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        return newUsername;
    }
public:
    void addPerson(const Person& p) {
        Person person = p;
        person.username = generateUsername(person.firstName, person.lastName);
        people.push_back(person);
    }
    void deletePerson(const std::string& username) {
        people.erase(std::remove_if(people.begin(), people.end(), [&username](const Person& p) {
            return p.username == username;
            }), people.end());
    }
    std::vector<Person> getPeople() const {
        return people;
    }
    void sortPeople(int criterion) {
        switch (criterion) {
        case 1:
            std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
                return a.lastName < b.lastName;
                });
            break;
        case 2:
            std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
                if (a.year != b.year) return a.year < b.year;
                if (a.month != b.month) return a.month < b.month;
                return a.day < b.day;
                });
            break;
        }
    }
    void saveToFile() const {
        std::ofstream file("database.txt", std::ios::out | std::ios::binary);
        file << "\xEF\xBB\xBF";
        for (const auto& person : people) {
            file << person.firstName << " " << person.lastName << " "
                << person.day << " " << person.month << " " << person.year << " "
                << person.street << " " << person.houseNumber << " " << person.city << " "
                << person.postalCode << " "
                << person.username << "\n";
        }
        file.close();
    }
    void loadFromFile() {
        std::ifstream file("database.txt", std::ios::in | std::ios::binary);
        char bom[3];
        file.read(bom, 3);
        if (!(bom[0] == '\xEF' && bom[1] == '\xBB' && bom[2] == '\xBF')) {
            file.seekg(0);
        }
        Person p;
        while (file >> p.firstName >> p.lastName >> p.day >> p.month >> p.year
            >> p.street >> p.houseNumber >> p.city >> p.postalCode
            >> p.username) {
            p.username = generateUsername(p.firstName, p.lastName);
            people.push_back(p);
        }
        file.close();
    }
};

#endif // DATABASE_H
