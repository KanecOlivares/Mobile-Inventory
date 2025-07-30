package com.example.mobileinventory

import android.os.Bundle
import android.view.Menu
import android.widget.Toast
import com.google.android.material.snackbar.Snackbar
import com.google.android.material.navigation.NavigationView
import androidx.navigation.findNavController
import androidx.navigation.ui.AppBarConfiguration
import androidx.navigation.ui.navigateUp
import androidx.navigation.ui.setupActionBarWithNavController
import androidx.navigation.ui.setupWithNavController
import androidx.drawerlayout.widget.DrawerLayout
import androidx.appcompat.app.AppCompatActivity
import com.example.mobileinventory.databinding.ActivityMainBinding
import com.google.android.material.dialog.MaterialAlertDialogBuilder

class MainActivity : AppCompatActivity() {

    private lateinit var appBarConfiguration: AppBarConfiguration
    private lateinit var binding: ActivityMainBinding

    private fun debug_msg(msg: String) {
        Snackbar.make(binding.root, msg, Snackbar.LENGTH_SHORT).show()
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Set up UI components
        setupToolbarAndFab()
        setupNavigation()


        val drawerLayout: DrawerLayout = binding.drawerLayout
        val navView: NavigationView = binding.navView
        val navController = findNavController(R.id.nav_host_fragment_content_main)

        // Passing each menu ID as a set of Ids because each
        // menu should be considered as top level destinations.
        appBarConfiguration = AppBarConfiguration(
            setOf(
                R.id.nav_home, R.id.nav_gallery, R.id.nav_slideshow
            ), drawerLayout
        )
        setupActionBarWithNavController(navController, appBarConfiguration)
        navView.setupWithNavController(navController)
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        // Inflate the menu; this adds items to the action bar if it is present.
        menuInflater.inflate(R.menu.main, menu)
        return true
    }

    override fun onSupportNavigateUp(): Boolean {
        val navController = findNavController(R.id.nav_host_fragment_content_main)
        return navController.navigateUp(appBarConfiguration) || super.onSupportNavigateUp()
    }

    private fun handlePickup(){
        debug_msg("handlePickup not implemented yet")
    }
    private fun handleDelivery(){
        debug_msg("handleDelivery not implemented yet")
    }
    private fun handleViewStock(){
        debug_msg("handleViewStock not implemented yet")
    }


    private fun showOptionsDialog() {
        val options = arrayOf("Pick-Up (Adding)", "Delivery (Taking Away)",
            "View Stock")
        var selectedIndex = 0  // Optional: default selected

        MaterialAlertDialogBuilder(this)
            .setTitle("Inventory")
            .setSingleChoiceItems(options, selectedIndex) { _, which ->
                // Save selected index
                selectedIndex = which
            }
            .setPositiveButton("OK") { dialog, _ ->
                when (selectedIndex) {
                    0 -> handlePickup()
                    1 -> handleDelivery()
                    2 -> handleViewStock()
                }
                dialog.dismiss()
            }
            .setNegativeButton("Cancel", null)
            .show()
    }

    private fun setupToolbarAndFab() {
        /*
         activity_main.xml
           └── includes app_bar_main.xml
                 └── contains a Toolbar with id="toolbar"
         Sets up the tool bar to act as an action bar
         NOTE:
             binding: Refers to the whole layout (activity_main.xml)
             appBarMain: Refers to the nested layout inside activity_main.xml
             toolbar: Is the ID of the Toolbar defined in app_bar_main.xml
         */

        setSupportActionBar(binding.appBarMain.toolbar)
        binding.appBarMain.fab.setOnClickListener {
            showOptionsDialog() // attaches click to floating action button
        }
    }

    private fun setupNavigation() {
        val drawerLayout: DrawerLayout = binding.drawerLayout
        val navView: NavigationView = binding.navView
        val navController = findNavController(R.id.nav_host_fragment_content_main)

        appBarConfiguration = AppBarConfiguration(
            setOf(R.id.nav_home, R.id.nav_gallery, R.id.nav_slideshow),
            drawerLayout
        )
        setupActionBarWithNavController(navController, appBarConfiguration)
        navView.setupWithNavController(navController)
    }
}