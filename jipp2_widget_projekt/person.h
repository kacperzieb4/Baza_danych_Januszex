#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ctime>

class Person {
public:
    std::string firstName;
    std::string lastName;
    int day;
    int month;
    int year;
    std::string street;
    std::string houseNumber;
    std::string city;
    std::string postalCode;
    std::string username;

    int calculateAge() const {
        time_t now = time(0);
        tm ltm = {};
        localtime_s(&ltm, &now);
        int currentYear = 1900 + ltm.tm_year;
        int currentMonth = 1 + ltm.tm_mon;
        int currentDay = ltm.tm_mday;

        int age = currentYear - year;
        if (month > currentMonth || (month == currentMonth && day > currentDay)) {
            age--;
        }
        return age;
    }
};

#endif // PERSON_H
