//
// Created by KanecO on 7/30/25.
//
#include <iostream>
#include <string>
#include <sqlite3.h>


#ifndef MOBILEINVENTORY_INVENTORYMGMT_H
#define MOBILEINVENTORY_INVENTORYMGMT_H


class InventoryMgmt {
    sqlite3* DB;

public:
    InventoryMgmt(std::string db_filePath){
        int exit = 0;
        exit = sqlite3_open(db_filePath, &DB);
        if (exit) {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
            return (-1);
        }
        else {
            std::cout << "Opened Database Successfully!" << std::endl;
        }
        sqlite3_close(DB);

    }
private:


};


#endif //MOBILEINVENTORY_INVENTORYMGMT_H
