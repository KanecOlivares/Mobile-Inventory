//
// Created by KanecO on 7/30/25.
//
#include <gtest/gtest.h>
#include <string>
#include "../date.h"
using namespace std;


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