package com.example.mobileinventory.data

import android.app.Application
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.LiveData
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.launch

class ItemViewModel(application: Application): AndroidViewModel(application) {

    private val readAllData: LiveData<List<Item>>
    private val repository: ItemRepository


    init{ // executed everytime user model is called
        val itemDao = ItemDatabase.getDatabase(application).itemDAO()
        repository = ItemRepository(itemDao)
        readAllData = repository.readAllData
    }

    fun addItem(item: Item){
        viewModelScope.launch(Dispatchers.IO) { // .IO makes it into coroutine so it runs as a bg job
            repository.addItem(item)
        }
    }
}