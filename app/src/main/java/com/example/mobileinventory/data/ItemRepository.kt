package com.example.mobileinventory.data

import androidx.lifecycle.LiveData

/*
Suggest part for code separation.
 */
class ItemRepository(private val itemDao: ItemDao){
    val readAllData: LiveData<List<Item>> = itemDao.getAllItems()

    suspend fun addItem(item: Item){
        itemDao.addItem(item)
    }


}