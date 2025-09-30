// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
    // The plugins alias are found in the libs.versions.tomi
    alias(libs.plugins.android.application) apply false
    alias(libs.plugins.kotlin.android) apply false
    alias(libs.plugins.google.ksp) apply false
}