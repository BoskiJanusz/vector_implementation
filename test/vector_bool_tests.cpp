#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorBoolTest, OneTrueValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    auto value = v[0];
    auto expected = true;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, OneFalseValueIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 0;
    v.push_back(a);
    auto value = v[0];
    auto expected = false;
    EXPECT_EQ(value, expected);
}

TEST(VectorBoolTest, FourTrueValuesIntoVectorTest) {
    my::vector<bool> v{};
    bool a = 1;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v[3];
    auto expected = true;
    EXPECT_EQ(value, expected);
}