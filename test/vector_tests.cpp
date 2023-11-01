#include <gtest/gtest.h>
#include <string>
#include "../src/vector.hpp"

TEST(VectorTest, IntOneValueIntoVectorTest){
    my::vector<int> v{};
    int a = 5;
    v.push_back(a);
    auto value = v[0];
    auto expected = 5;
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntThreeValueIntoVectorTest){
    my::vector<int> v{};
    int a = 5;
    v.push_back(a);
    v.push_back(a);
    v.push_back(a);
    auto value = v[2];
    auto expected = 5;
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharOneValueIntoVectorTest){
    my::vector<char> v{};
    char c = 't';
    v.push_back(c);
    auto value = v[0];
    auto expected = 't';
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharThreeValueIntoVectorTest){
    my::vector<char> v{};
    char c = 't';
    v.push_back(c);
    v.push_back(c);
    v.push_back(c);
    auto value = v[2];
    auto expected = 't';
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringOneValueIntoVectorTest){
    my::vector<std::string> v{};
    std::string str{"test"};
    v.push_back(str);
    auto value = v[0];
    auto expected = "test";
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringThreeValueIntoVectorTest){
    my::vector<std::string> v{};
    std::string str{"test"};
    v.push_back(str);
    v.push_back(str);
    v.push_back(str);
    auto value = v[2];
    auto expected = "test";
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, IntCopyConstructorTest){
    int a{5};
    my::vector<int> vector{a};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, CharCopyConstructorTest){
    char c = 'c';
    my::vector<char> vector{c};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}

TEST(VectorTest, StringCopyConstructorTest){
    std::string str{"test"};
    my::vector<std::string> vector{str};
    auto copiedVector {vector};
    auto value = vector[0];
    auto expected = copiedVector[0];
    EXPECT_EQ(value, expected);
}
