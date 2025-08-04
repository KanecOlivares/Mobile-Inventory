//
//
//

#ifndef MOBILEINVENTORY_DATE_H
#define MOBILEINVENTORY_DATE_H
#include <string>

class Date {
    int month, day, year;

public:
    Date(std::string given_date){
        parse_date(given_date);
    }

    bool operator>(const Date& other){
        /*
         * Current_Date > Other_Date
         * is current date in the future compared to other date
         */
        if (year > other.year)
            return true;
        else if (month > other.month)
            return true;
        else if (day > other.day)
            return true;

        return false; // current date is a future date
    }

    bool operator<(const Date& other){
        /*
         * Current_Date < Other_Date
         * Is current_date earlier than other_date?
         */
        if (year < other.year)
            return true;
        else if (month < other.month)
            return true;
        else if (day < other.day)
            return true;

        return false; // Current date is a earlier date
    }

    bool operator==(const Date& other) const {
        /*
         * Year, Month, Day must be the same to be considered the same date.
         */
        return (year == other.year && month == other.month && day == other.day);
    }

    bool operator!=(const Date& other) const{
        /*
         * If any of them are different then they are not equivalent dates
         */
        return (year != other.year || month != other.month || day != other.day);
    }

private:
    void parse_date(std::string &date){
        // Date follows this format MM-DD-YYYY
        month = std::stoi(date.substr(0,2));
        day = std::stoi(date.substr(3, 2));
        year = std::stoi(date.substr(6, 4));
    }
};


#endif //MOBILEINVENTORY_DATE_H
