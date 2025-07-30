//
// Created by KanecO on 7/30/25.
//
#include <gtest/gtest.h>
#include <string>
#include "../date.h"
using namespace std;
// ./test_all --gtest_filter="SuiteName.*"
// g++ -fprofile-arcs -ftest-coverage -g -std=c++17 -I<..> date.cpp test_date.cpp -lgtest -lgtest_main -pthread -o test_all

/* ----- EQUALITY TESTING ----- */
TEST(IsEqual, Equal) {
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-04-2025");
    EXPECT_TRUE(july4_2025 == cookOut_2025);
}
TEST(IsNotEqual, byYear) {
    Date july4_2026("07-04-2026");
    Date cookOut_2025("07-04-2025");
    EXPECT_TRUE(july4_2026 != cookOut_2025);
}
TEST(IsNotEqual, byMonth) {
    Date july4_2025("07-04-2025");
    Date cookOut_2025("08-04-2025");
    EXPECT_TRUE(july4_2025 != cookOut_2025);
}
TEST(IsNotEqual, byDay) {
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-05-2025");
    EXPECT_TRUE(july4_2025 != cookOut_2025);
}

/* ----- LESS THAN TESTING ----- */
TEST(LessThan, isEqual){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-04-2025");
    EXPECT_FALSE(july4_2025 < cookOut_2025);
}
TEST(LessThan, byYear){
    Date july4_2026("07-04-2026");
    Date cookOut_2025("07-04-2025");
    EXPECT_TRUE(cookOut_2025 < july4_2026);
}
TEST(LessThan, byMonth){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("06-04-2025");
    EXPECT_TRUE(cookOut_2025 < july4_2025);
}
TEST(LessThan, byDay){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-03-2025");
    EXPECT_TRUE(cookOut_2025 < july4_2025);
}

/* ----- GREATER THAN TESTING ----- */
TEST(GreaterThan, isEqual){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-04-2025");
    EXPECT_FALSE(july4_2025 > cookOut_2025);
}
TEST(GreaterThan, byYear){
    Date july4_2026("07-04-2025");
    Date cookOut_2025("07-04-2026");
    EXPECT_TRUE(cookOut_2025 > july4_2026);
}
TEST(GreaterThan, byMonth){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("08-04-2025");
    EXPECT_TRUE(cookOut_2025 > july4_2025);
}
TEST(GreaterThan, byDay){
    Date july4_2025("07-04-2025");
    Date cookOut_2025("07-05-2025");
    EXPECT_TRUE(cookOut_2025 > july4_2025);
}

