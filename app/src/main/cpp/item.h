//
//
//

#ifndef MOBILEINVENTORY_ITEM_H
#define MOBILEINVENTORY_ITEM_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include "date.h"



class Item {
    int id;
    int count;
    std::string name;
    std::vector<std::tuple<Item, Date>> updates;

    Item(int item_id, std::string given_name, int given_count, Date given_date) : id(item_id), name(std::move(given_name)),
    count(given_count) {

    }

};

struct UpdatedItem{
    Date date;
    Item item;
};

#endif //MOBILEINVENTORY_ITEM_H
