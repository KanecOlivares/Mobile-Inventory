//
// Created by KanecO on 7/18/25.
//

#ifndef MOBILEINVENTORY_ITEM_H
#define MOBILEINVENTORY_ITEM_H
#include <string>
#include <vector>
#include <tuple>
#include "date.h"



class Item {
    int count;
    std::string name;
    std::vector<std::tuple<Item, Date>> updates;

    Item(std::string given_name, int given_count, Date given_date) : name(std::move(given_name)),
    count(given_count) {
        updates.update(); // add function for updating the vector
    }

};

struct UpdatedItem{
    Date date;
    Item item;
};

#endif //MOBILEINVENTORY_ITEM_H
