package com.example.mobileinventory.ui

import androidx.recyclerview.widget.DiffUtil
import androidx.recyclerview.widget.ListAdapter
import com.example.mobileinventory.data.Item
//import com.example.mobile inventory.databinding.ItemBinding

//class ItemAdapter(
//    private val onToggleDone: (Item) -> Unit,
//    private val onDelete: (Item) -> Unit
//): ListAdapter<Item, ItemAdapter.ItemViewHolder>(DiffCallBack()) {
//
//    class ItemViewHolder(val binding: Item)
//
//    class DiffCallBack : DiffUtil.ItemCallback<Item>(){
//        // Based on Id
//        override fun areItemsTheSame(oldItem: Item, newItem: Item) = oldItem.id == newItem.id
//        // Based on the whole content
//        override fun areContentsTheSame(oldItem: Item, newItem: Item) = oldItem == newItem
//    }
//}