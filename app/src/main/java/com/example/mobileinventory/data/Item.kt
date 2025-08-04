package com.example.mobileinventory.data

import androidx.room.ColumnInfo
import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "inventory")
data class Item(
//    Make them into var not val because in compilation time it will become final
    @PrimaryKey(autoGenerate = true) var id: Int = 0,
    var count: Int,
    var name: String
){

}
