package com.example.mobileinventory.data

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase

@Database(entities = [Item::class], version = 1, exportSchema = false)
abstract class ItemDatabase : RoomDatabase() {

    abstract fun itemDAO(): ItemDao

    companion object{ // everthing in here will be visible to other classes
        @Volatile
        private var INSTANCE: ItemDatabase? = null // Only one instance of this class

        fun getDatabase(context: Context): ItemDatabase{
            val tempInstance = INSTANCE
            if (tempInstance != null){
                return tempInstance
            }else{
                synchronized(this){ // if instance does not exist CREATE ONE!!!
                    val instance = Room.databaseBuilder(
                        context.applicationContext,
                        ItemDatabase::class.java,
                         "item_database"
                    ).build()
                    INSTANCE = instance
                    return instance
                }
            }
        }
    }
}