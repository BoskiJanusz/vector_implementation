#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorTest, IntValueIntoVectorTest){
    my::vector<int> v{};
    int a = 5;
    v.push_back(a);
    auto value = v[0];
    auto expected = 5;
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharValueIntoVectorTest){
    my::vector<char> v{};
    char c = 't';
    v.push_back(c);
    auto value = v[0];
    auto expected = 't';
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringValueIntoVectorTest){
    my::vector<std::string> v{};
    std::string str{"test"};
    v.push_back(str);
    auto value = v[0];
    auto expected = "test";
    EXPECT_EQ(value, expected);
}

