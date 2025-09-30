package com.example.mobileinventory.data

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase


//@Database(entities = [Item::class], version = 1)
//abstract class ItemDatabase: RoomDatabase() {
//    abstract fun itemDao(): ItemDao
//
//    companion object{
//        @Volatile private var Instance: ItemDatabase? = null
//
//        fun getDatabase(context: Context): ItemDatabase{
//            return Instance ?: synchronized(this){
//                Room.databaseBuilder(
//                    context.applicationContext,
//                    ItemDatabase::class.java,
//                    "item_db"
//                ).build().also{Instance = it}
//            }
//        }
//
//    }
//}