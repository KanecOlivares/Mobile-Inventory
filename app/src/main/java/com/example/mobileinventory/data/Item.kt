package com.example.mobileinventory.data

import androidx.room.Entity
import androidx.room.PrimaryKey

@Entity(tableName = "item")
data class Item(
    @PrimaryKey(autoGenerate = true) var id: Int = 0,
    val name: String,
    val count: Int,
)
